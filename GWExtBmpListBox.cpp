// GWExtBmpListBox.cpp : implementation file
//

#include "stdafx.h"
#include "VisioApp.h"
#include "GWExtBmpListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// GWExtBmpListBox

#define DX_BITMAP        20
#define DY_BITMAP        16

#define DSx     0x00660046L
#define DSna    0x00220326L
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void GWExtBmpListBox::_DrawMaskedBitmap(CDC* pDC, CBitmap* pbmp, CBitmap* pbmpMask,
									   int x, int y, int cx, int cy)
{
	COLORREF oldBkColor = pDC->SetBkColor(RGB(255, 255, 255));
	COLORREF oldTextColor = pDC->SetTextColor(RGB(0, 0, 0));
	
	CDC dcCompat;
	dcCompat.CreateCompatibleDC(pDC);
	CBitmap* pbmpSave = dcCompat.SelectObject(pbmp);
	pDC->BitBlt(x, y, cx, cy, &dcCompat, 0, 0, DSx);
	dcCompat.SelectObject(pbmpMask);
	pDC->BitBlt(x, y, cx, cy, &dcCompat, 0, 0, DSna);
	dcCompat.SelectObject(pbmp);
	pDC->BitBlt(x, y, cx, cy, &dcCompat, 0, 0, DSx);
	dcCompat.SelectObject(pbmpSave);
	
	pDC->SetBkColor(oldBkColor);
	pDC->SetTextColor(oldTextColor);
}

void GWExtBmpListBox::_InitMaskFromBitmap(CBitmap* pbmp, CBitmap* pbmpMask)
{
	BITMAP bmp;
	pbmp->GetObject(sizeof (BITMAP), &bmp);
	pbmpMask->CreateBitmap(bmp.bmWidth, bmp.bmHeight, 1, 1, NULL);
	
	CDC dcDst;
	dcDst.CreateCompatibleDC(NULL);
	CDC dcSrc;
	dcSrc.CreateCompatibleDC(NULL);
	dcDst.SelectObject(pbmpMask);
	dcSrc.SelectObject(pbmp);
	
	COLORREF oldBkColor = dcSrc.SetBkColor(dcSrc.GetPixel(0, 0));
	dcDst.BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &dcSrc, 0, 0, NOTSRCCOPY);
	dcSrc.SetBkColor(oldBkColor);
}

GWExtBmpListBox::GWExtBmpListBox() : CListBox()
{
	m_bmpTrueType.LoadBitmap(IDB_MB_COMP_TYPE);
	_InitMaskFromBitmap(&m_bmpTrueType, &m_bmpMask);
}

GWExtBmpListBox::~GWExtBmpListBox()
{
}

IMPLEMENT_DYNAMIC(GWExtBmpListBox, CListBox)

BEGIN_MESSAGE_MAP(GWExtBmpListBox, CListBox)
//{{AFX_MSG_MAP(GWExtBmpListBox)
ON_WM_CREATE()
ON_WM_DESTROY()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void GWExtBmpListBox::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	ASSERT( lpDIS->CtlType == ODT_LISTBOX );
	
	// make sure this is a *real* item
	if (lpDIS->itemID == -1)
		return;
	
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	COLORREF crBk, crText;
	TEXTMETRIC tm;
	int x, y;
	
	// Calculate the colors to use
	crBk = pDC->SetBkColor(GetSysColor(lpDIS->itemState & ODS_SELECTED ? COLOR_HIGHLIGHT : COLOR_WINDOW) );
	crText = pDC->SetTextColor(GetSysColor(lpDIS->itemState & ODS_SELECTED ? COLOR_HIGHLIGHTTEXT : COLOR_WINDOWTEXT) );
	
	// Calculate the position of the text
	pDC->GetTextMetrics( &tm );
	x = LOWORD(GetDialogBaseUnits()) / 4;
	y = (lpDIS->rcItem.bottom + lpDIS->rcItem.top - tm.tmHeight) / 2;
	
	// Draw the text
	CRect temRect = CRect(lpDIS->rcItem);
	temRect.left +=  DX_BITMAP + 2 * x;
	
	CString strFaceName;
	GetText(lpDIS->itemID, strFaceName);
	
	CString strSpaces = "                        ";  // 50 spaces
	
	CString strFirst;
	CString strSecond;
	strFirst = strFaceName;
	if(strFaceName.ReverseFind(_T('@'))>0)
	{
		strFirst = strFaceName.Left(strFaceName.ReverseFind(_T('@')));
	}
	strSecond ="";
	strSecond = strFaceName.Right(strFaceName.GetLength() - strFirst.GetLength() -1);

	CString strDraw;
	CString strSpace = "";
	if((strSpaces.GetLength() - strFirst.GetLength())>0)
	{
	   strSpace = strSpaces.Left(strSpaces.GetLength() - strFirst.GetLength());
	}

	strDraw = strFirst +strSpace+strSecond;
	// Draw the text
	pDC->ExtTextOut(lpDIS->rcItem.left + DX_BITMAP + 2 * x, y, ETO_CLIPPED | ETO_OPAQUE,
		&lpDIS->rcItem,(LPCTSTR) strDraw,
		lstrlen((LPCTSTR) strDraw), NULL );
	
	// Put the colors back as they were
	pDC->SetTextColor( crText );
	pDC->SetBkColor( crBk );
	
	// Draw the TrueType bitmap
	
	int dy;
	dy = ((lpDIS->rcItem.bottom - lpDIS->rcItem.top) - DY_BITMAP) / 2;
	_DrawMaskedBitmap(pDC, &m_bmpTrueType, &m_bmpMask,
		x, lpDIS->rcItem.top + dy, DX_BITMAP, DY_BITMAP);
	
	
	// Draw the focus rect if needed
	if (lpDIS->itemState & ODS_FOCUS)
		pDC->DrawFocusRect( &lpDIS->rcItem );
}

void GWExtBmpListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	CClientDC cdc(this);
	TEXTMETRIC tm;
	cdc.GetTextMetrics(&tm);
	lpMeasureItemStruct->itemHeight = tm.tmHeight+6;
}


void GWExtBmpListBox::OnDestroy()
{
	CListBox::OnDestroy();
}

int GWExtBmpListBox::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListBox::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}
//->cmember
	//-> Deletes an item from the font listbox. 
void GWExtBmpListBox::DeleteItem(LPDELETEITEMSTRUCT lpDIS)
{
	CListBox::DeleteItem(lpDIS);
}


void CTRSFileListBox::_DrawMaskedBitmap(CDC* pDC, CBitmap* pbmp, CBitmap* pbmpMask,
									   int x, int y, int cx, int cy)
{
	COLORREF oldBkColor = pDC->SetBkColor(RGB(255, 255, 255));
	COLORREF oldTextColor = pDC->SetTextColor(RGB(0, 0, 0));
	
	CDC dcCompat;
	dcCompat.CreateCompatibleDC(pDC);
	CBitmap* pbmpSave = dcCompat.SelectObject(pbmp);
	pDC->BitBlt(x, y, cx, cy, &dcCompat, 0, 0, DSx);
	dcCompat.SelectObject(pbmpMask);
	pDC->BitBlt(x, y, cx, cy, &dcCompat, 0, 0, DSna);
	dcCompat.SelectObject(pbmp);
	pDC->BitBlt(x, y, cx, cy, &dcCompat, 0, 0, DSx);
	dcCompat.SelectObject(pbmpSave);
	
	pDC->SetBkColor(oldBkColor);
	pDC->SetTextColor(oldTextColor);
}

void CTRSFileListBox::_InitMaskFromBitmap(CBitmap* pbmp, CBitmap* pbmpMask)
{
	BITMAP bmp;
	pbmp->GetObject(sizeof (BITMAP), &bmp);
	pbmpMask->CreateBitmap(bmp.bmWidth, bmp.bmHeight, 1, 1, NULL);
	
	CDC dcDst;
	dcDst.CreateCompatibleDC(NULL);
	CDC dcSrc;
	dcSrc.CreateCompatibleDC(NULL);
	dcDst.SelectObject(pbmpMask);
	dcSrc.SelectObject(pbmp);
	
	COLORREF oldBkColor = dcSrc.SetBkColor(dcSrc.GetPixel(0, 0));
	dcDst.BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &dcSrc, 0, 0, NOTSRCCOPY);
	dcSrc.SetBkColor(oldBkColor);
}

CTRSFileListBox::CTRSFileListBox() : CListBox()
{
	m_bmpTrueType.LoadBitmap(IDB_MB_TRS_LIST);
	_InitMaskFromBitmap(&m_bmpTrueType, &m_bmpMask);
}

CTRSFileListBox::~CTRSFileListBox()
{
}

IMPLEMENT_DYNAMIC(CTRSFileListBox, CListBox)

BEGIN_MESSAGE_MAP(CTRSFileListBox, CListBox)
//{{AFX_MSG_MAP(CTRSFileListBox)
ON_WM_CREATE()
ON_WM_DESTROY()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CTRSFileListBox::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	ASSERT( lpDIS->CtlType == ODT_LISTBOX );
	
	// make sure this is a *real* item
	if (lpDIS->itemID == -1)
		return;
	
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	COLORREF crBk, crText;
	TEXTMETRIC tm;
	int x, y;
	
	// Calculate the colors to use
	crBk = pDC->SetBkColor(GetSysColor(lpDIS->itemState & ODS_SELECTED ? COLOR_HIGHLIGHT : COLOR_WINDOW) );
	crText = pDC->SetTextColor(GetSysColor(lpDIS->itemState & ODS_SELECTED ? COLOR_HIGHLIGHTTEXT : COLOR_WINDOWTEXT) );
	
	// Calculate the position of the text
	pDC->GetTextMetrics( &tm );
	x = LOWORD(GetDialogBaseUnits()) / 4;
	y = (lpDIS->rcItem.bottom + lpDIS->rcItem.top - tm.tmHeight) / 2;
	
	// Draw the text
	CRect temRect = CRect(lpDIS->rcItem);
	temRect.left +=  DX_BITMAP + 2 * x;
	
	CString strFaceName;
	GetText(lpDIS->itemID, strFaceName);
	
	CString strSpaces = "                        ";  // 50 spaces
	
	CString strFirst;
	CString strSecond;
	strFirst = strFaceName;
	if(strFaceName.ReverseFind(_T('@'))>0)
	{
		strFirst = strFaceName.Left(strFaceName.ReverseFind(_T('@')));
	}
	strSecond ="";
	strSecond = strFaceName.Right(strFaceName.GetLength() - strFirst.GetLength() -1);

	CString strDraw;
	CString strSpace = "";
	if((strSpaces.GetLength() - strFirst.GetLength())>0)
	{
	   strSpace = strSpaces.Left(strSpaces.GetLength() - strFirst.GetLength());
	}

	strDraw = strFirst +strSpace+strSecond;
	// Draw the text
	pDC->ExtTextOut(lpDIS->rcItem.left + DX_BITMAP + 2 * x, y, ETO_CLIPPED | ETO_OPAQUE,
		&lpDIS->rcItem,(LPCTSTR) strDraw,
		lstrlen((LPCTSTR) strDraw), NULL );
	
	// Put the colors back as they were
	pDC->SetTextColor( crText );
	pDC->SetBkColor( crBk );
	
	// Draw the TrueType bitmap
	
	int dy;
	dy = ((lpDIS->rcItem.bottom - lpDIS->rcItem.top) - DY_BITMAP) / 2;
	_DrawMaskedBitmap(pDC, &m_bmpTrueType, &m_bmpMask,
		x, lpDIS->rcItem.top + dy, DX_BITMAP, DY_BITMAP);
	
	
	// Draw the focus rect if needed
	if (lpDIS->itemState & ODS_FOCUS)
		pDC->DrawFocusRect( &lpDIS->rcItem );
}

void CTRSFileListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	CClientDC cdc(this);
	TEXTMETRIC tm;
	cdc.GetTextMetrics(&tm);
	lpMeasureItemStruct->itemHeight = tm.tmHeight+6;
}


void CTRSFileListBox::OnDestroy()
{
	CListBox::OnDestroy();
}

int CTRSFileListBox::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListBox::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}
//->cmember
	//-> Deletes an item from the font listbox. 
void CTRSFileListBox::DeleteItem(LPDELETEITEMSTRUCT lpDIS)
{
	CListBox::DeleteItem(lpDIS);
}

