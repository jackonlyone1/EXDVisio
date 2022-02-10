// MyCorsssLineShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "MyCorsssLineShape.h"
#include <afxpriv.h>
#include "LinePropDlg.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// CMyCorsssLineShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CMyCorsssLineShape, CFODrawPortsShape, 0)
CMyCorsssLineShape::CMyCorsssLineShape()
{
	SetBkColor(RGB(187,224,227));
	SetPolyObject(TRUE);
	SetType(MY_LINE_TYPE);

	CMyCustomProperties propLine;
	AddNewProperty(propLine);
}

CMyCorsssLineShape::CMyCorsssLineShape(const CMyCorsssLineShape& src)
{
	SetPolyObject(TRUE);
	*this = src;
}

CMyCorsssLineShape::~CMyCorsssLineShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CMyCorsssLineShape diagnostics

#ifdef _DEBUG
void CMyCorsssLineShape::AssertValid() const
{
	CFODrawPortsShape::AssertValid();
}

void CMyCorsssLineShape::Dump(CDumpContext& dc) const
{
	CFODrawPortsShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////

void CMyCorsssLineShape::Create(CRect &rcPos,CString strCaption)
{
	AllocMemory(6);
	
	m_lpShapePoints[0] = CPoint(rcPos.left,  rcPos.top);
	m_lpShapePoints[1] = CPoint(rcPos.left+rcPos.Width() *3/4, rcPos.top);
	m_lpShapePoints[2] = CPoint(rcPos.right, rcPos.CenterPoint().y);
	m_lpShapePoints[3] = CPoint(rcPos.left+rcPos.Width() *3/4,  rcPos.bottom);
	m_lpShapePoints[4] = CPoint(rcPos.left, rcPos.bottom);
	m_lpShapePoints[5] = CPoint(rcPos.left+rcPos.Width()/4, rcPos.CenterPoint().y);

	CFODrawPortsShape::Create(rcPos,strCaption);

	CreateDefaultPort(0.5,0.5);
	CreateDefaultPort(0,0);
	CreateDefaultPort(0.75,0);
	CreateDefaultPort(0,1.0);
	CreateDefaultPort(0.75,1.0);
	CreateDefaultPort(1,0.5);
	
	
	UpdateComp();
	
}

void CMyCorsssLineShape::Serialize(CArchive& ar)
{
	CFODrawPortsShape::Serialize(ar);
	if(ar.IsStoring())
	{
		//FODO:Add your own code here.

	}
	else
	{
		//FODO:Add your own code here.

	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrintBaseJob serialization
CFile* CMyCorsssLineShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
								 CFileException* pError)
{
	CMirrorFile* pFile = new CMirrorFile;
	ASSERT(pFile != NULL);
	if (!pFile->Open(lpszFileName, nOpenFlags, pError))
	{
		delete pFile;
		pFile = NULL;
	}
	return pFile;
}
void CMyCorsssLineShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}
BOOL CMyCorsssLineShape::OpenDocument(LPCTSTR lpszPathName)
{
	
	CFileException fe;
	CFile* pFile = GetFile(lpszPathName,
		CFile::modeRead|CFile::shareDenyWrite, &fe);
	if (pFile == NULL)
	{
		return FALSE;
	}
	
	CArchive loadArchive(pFile, CArchive::load | CArchive::bNoFlushOnDelete);
	loadArchive.m_bForceFlat = FALSE;
	TRY
	{
		CWaitCursor wait;
		if (pFile->GetLength() != 0)
			Serialize(loadArchive);     // load me
		loadArchive.Close();
		ReleaseFile(pFile, FALSE);
	}
	CATCH_ALL(e)
	{
		ReleaseFile(pFile, TRUE);
		
		return FALSE;
	}
	END_CATCH_ALL
		
		
		return TRUE;
}
BOOL CMyCorsssLineShape::SaveDocument(LPCTSTR lpszPathName)
{
	
	CFileException fe;
	CFile* pFile = NULL;
	pFile = GetFile(lpszPathName, CFile::modeCreate |
		CFile::modeReadWrite | CFile::shareExclusive, &fe);
	
	if (pFile == NULL)
	{
		
		return FALSE;
	}
	
	CArchive saveArchive(pFile, CArchive::store | CArchive::bNoFlushOnDelete);
	saveArchive.m_bForceFlat = FALSE;
	TRY
	{
		CWaitCursor wait;
		Serialize(saveArchive);     // save me
		saveArchive.Close();
		ReleaseFile(pFile, FALSE);
	}
	CATCH_ALL(e)
	{
		ReleaseFile(pFile, TRUE);
		
		return FALSE;
	}
	END_CATCH_ALL
		
		
		return TRUE;        // success
}


CMyCorsssLineShape& CMyCorsssLineShape::operator=(const CMyCorsssLineShape& src)
{
	(*(CFODrawPortsShape*)this) = src;
	return (*this);
}

CFODrawShape* CMyCorsssLineShape::Copy() const
{
	return (new CMyCorsssLineShape(*this));
}

void CMyCorsssLineShape::SetDescription(const CString strText)	
{ 
	CMyCustomProperties *pProp = GetLineProperty();
	pProp->SetDescription(strText);
}

CString	CMyCorsssLineShape::GetDescription() const
{ 
	CMyCustomProperties *pProp = GetLineProperty();
	return pProp->GetDescription();
}

void CMyCorsssLineShape::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	nFlags; 
	point; 
	CChildFrame* pChildFrame = (CChildFrame *)((CMDIFrameWnd*)::AfxGetMainWnd())->MDIGetActive();
	if (pChildFrame)
	{
		pChildFrame->GoToPage(1);
	}
	
}

void CMyCorsssLineShape::PrepareDC(CDC* pDC)
{
	CFODrawPortsShape::PrepareDC(pDC);
	//FODO:Add your own code below.
	
}

void CMyCorsssLineShape::OnDrawTrackCustom(CDC *pDC)
{
	CFODrawPortsShape::OnDrawTrackCustom(pDC);
	// Add your own code here.
}

void CMyCorsssLineShape::OnDrawFlat(CDC *pDC)
{
	CFODrawPortsShape::OnDrawFlat(pDC);
	//FODO:Add your own code below.
	FillPoly(pDC,m_lpShapePoints, m_nCompPtCount,GetBkColor(),GetPatternColor(),GetBrushType());
	OnDrawPorts(pDC,TRUE);
}

void CMyCorsssLineShape::OnDrawShadow(CDC *pDC)
{
	FillShadowPoly(pDC,m_lpShapePoints, m_nCompPtCount);
}

void CMyCorsssLineShape::OnDraw3d(CDC *pDC)
{
	CFODrawPortsShape::OnDraw3d(pDC);
	FillPoly(pDC,m_lpShapePoints, m_nCompPtCount,GetBkColor(),GetPatternColor(),GetBrushType());
	OnDrawPorts(pDC,TRUE);
}

void CMyCorsssLineShape::ClearDC(CDC* pDC)
{
	CFODrawPortsShape::ClearDC(pDC);
	//FODO:Add your own code below.
}

void CMyCorsssLineShape::RotateShape(double nAngle, float fOriginX, float fOriginY)
{
	CFODrawPortsShape::RotateShape(nAngle,fOriginX,fOriginY);
}

void CMyCorsssLineShape::RotateTrackShape(double nAngle, float fOriginX, float fOriginY)
{
	CFODrawPortsShape::RotateTrackShape(nAngle,fOriginX,fOriginY);
}


void CMyCorsssLineShape::GeometryUpdated(CFOArea* pRgn)
{
	if (m_lpShapePoints && pRgn)
	{
		pRgn->BuildPolygonArea(m_lpShapePoints, m_nCompPtCount);
		m_rectPosition = pRgn->GetBoundingRect();
	}
}

CMyCustomProperties *CMyCorsssLineShape::GetLineProperty() const
{
	return (CMyCustomProperties *)FindProperty(FO_MY_PROP_ID);
}

void CMyCorsssLineShape::OnCustomProperties()
{
}
