// ExtListBar.cpp : implementation file
//

#include "stdafx.h"
#include "visioapp.h"
#include "ExtListBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExtListBar

CExtListBar::CExtListBar()
{
	hRoot = NULL;
}

CExtListBar::~CExtListBar()
{
}


BEGIN_MESSAGE_MAP(CExtListBar, CFOPControlBar)
	//{{AFX_MSG_MAP(CExtListBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CExtListBar message handlers
#define ID_TREE 2093

int CExtListBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFOPControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	
	DWORD dwStyle = WS_BORDER | WS_CHILD | TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT;
	if (!m_TreeCtrl.Create(dwStyle, CRect(0,0,0,0), this, ID_TREE))
		return -1;      // failed to create tree control
	m_TreeCtrl.ModifyStyleEx(0, WS_EX_CLIENTEDGE);

	// Create arrow bitmap cache.
	m_image.Create( IDB_MB_COMP_TYPE, 20, 0, RGB(255,255,255) );
	
	m_TreeCtrl.SetImageList(&m_image,TVSIL_NORMAL);

	TV_INSERTSTRUCT tvins;
	
	tvins.item.mask=TVIF_TEXT|TVIF_STATE|TVIF_IMAGE|TVIF_SELECTEDIMAGE|
		TVIF_PARAM|TVIF_CHILDREN;
	// NAMESPACEOBJECT object is not defined for Desktop item
	tvins.item.lParam=(LPARAM)NULL;
	// Desktop item always has subfolders
	tvins.item.cChildren=1;
	// display name

	CString strText = _T("Shapes List");
	tvins.item.pszText=(LPTSTR) (LPCTSTR) strText;
	
	// Request icon index for normal state
	tvins.item.iImage=0;
	tvins.item.iSelectedImage=0;
	// expanded from the beginning
	tvins.item.state=TVIS_EXPANDED|TVIS_EXPANDEDONCE;
	tvins.item.stateMask=tvins.item.state;
	
	// We collected all information we needed. It's time to insert 
	// new item in our TreeCtrl.
	tvins.hInsertAfter=TVI_LAST;
	tvins.hParent=TVI_ROOT;
	
	hRoot = m_TreeCtrl.InsertItem(&tvins);

	m_TreeCtrl.ShowWindow(SW_SHOW);
	return 0;
}

void CExtListBar::InsertWithComp(HTREEITEM hParent, CFOCompositeShape *pComp)
{
	CString strSpace = _T("                  ");
	CString strMe;
	CString strNeed = _T("");

	POSITION pos = pComp->GetCompList()->GetHeadPosition();
	while(pos != NULL)
	{
		CFODrawShape *pShape = pComp->GetCompList()->GetNext(pos);
		if(pShape->IsKindOf(RUNTIME_CLASS(CFOCompositeShape)))
		{
			CFOCompositeShape *pCompisite = static_cast<CFOCompositeShape *>(pShape);
			strMe = pShape->GetObjectName();
			strMe = _T("Group - ") + strMe;
			TV_INSERTSTRUCT tvins;
			
			tvins.item.mask=TVIF_TEXT|TVIF_STATE|TVIF_IMAGE|TVIF_SELECTEDIMAGE|
				TVIF_PARAM|TVIF_CHILDREN;
			// NAMESPACEOBJECT object is not defined for Desktop item
			tvins.item.lParam=(LPARAM)NULL;
			// Desktop item always has subfolders
			tvins.item.cChildren=1;
			// display name
			tvins.item.pszText=(LPTSTR) (LPCTSTR) strMe;
			
			// Request icon index for normal state
			tvins.item.iImage=0;
			tvins.item.iSelectedImage=0;
			// expanded from the beginning
			tvins.item.state=TVIS_EXPANDED|TVIS_EXPANDEDONCE;
			tvins.item.stateMask=tvins.item.state;
			
			// We collected all information we needed. It's time to insert 
			// new item in our TreeCtrl.
			tvins.hInsertAfter=TVI_LAST;
			tvins.hParent=hParent;
			
			HTREEITEM hCurrent = m_TreeCtrl.InsertItem(&tvins);

			InsertWithComp(hCurrent, pCompisite);
		}
		else
		{
			strMe = pShape->GetObjectName();
			if(strMe.GetLength() < strSpace.GetLength())
			{
				strNeed = strSpace.Left(strSpace.GetLength() - strMe.GetLength());
			}
			CRect rcPos = pShape->GetDrawRect();
			CString strTotal;
			strTotal.Format(_T("(%u,%u,%u,%u)"),rcPos.left,rcPos.top,rcPos.Width(),rcPos.Height());
			strTotal = strMe + strNeed + strTotal;

			TV_INSERTSTRUCT tvins;
			
			tvins.item.mask=TVIF_TEXT|TVIF_STATE|TVIF_IMAGE|TVIF_SELECTEDIMAGE|
				TVIF_PARAM;
			// NAMESPACEOBJECT object is not defined for Desktop item
			tvins.item.lParam=(LPARAM)NULL;
			// Desktop item always has subfolders
			tvins.item.cChildren=0;
			// display name
			tvins.item.pszText=(LPTSTR) (LPCTSTR) strTotal;
			
			// Request icon index for normal state
			tvins.item.iImage=1;
			tvins.item.iSelectedImage=1;
			// expanded from the beginning
			tvins.item.state=TVIS_EXPANDED|TVIS_EXPANDEDONCE;
			tvins.item.stateMask=tvins.item.state;
			
			// We collected all information we needed. It's time to insert 
			// new item in our TreeCtrl.
			tvins.hInsertAfter=TVI_LAST;
			tvins.hParent=hParent;

			m_TreeCtrl.InsertItem(&tvins);
		}
	}
}

void CExtListBar::InitShapes(CFODataModel *pDataModel)
{
	if(pDataModel == NULL)
	{
		return;
	}
	m_TreeCtrl.DeleteAllItems();
	hRoot = m_TreeCtrl.InsertItem(_T("Shapes List"));
	CString strSpace = _T("                  ");
	CString strMe;
	CString strNeed = _T("");

	CFODrawShape *pObject = NULL;
	int xy = 0;
	for(xy = 0; xy < pDataModel->GetFormObjects()->GetCount(); xy ++)
	{
		pObject = (CFODrawShape*)(pDataModel->GetFormObjects()->GetObject(xy));
		if(pObject->IsKindOf(RUNTIME_CLASS(CFOCompositeShape)))
		{
			CFOCompositeShape *pCompisite = static_cast<CFOCompositeShape *>(pObject);
			strMe = pObject->GetObjectName();
			strMe = _T("Group - ") + strMe;

			TV_INSERTSTRUCT tvins;
			
			tvins.item.mask=TVIF_TEXT|TVIF_STATE|TVIF_IMAGE|TVIF_SELECTEDIMAGE|
				TVIF_PARAM|TVIF_CHILDREN;
			// NAMESPACEOBJECT object is not defined for Desktop item
			tvins.item.lParam=(LPARAM)NULL;
			// Desktop item always has subfolders
			tvins.item.cChildren=1;
			// display name
			tvins.item.pszText=(LPTSTR) (LPCTSTR) strMe;
			
			// Request icon index for normal state
			tvins.item.iImage=0;
			tvins.item.iSelectedImage=0;
			// expanded from the beginning
			tvins.item.state=TVIS_EXPANDED|TVIS_EXPANDEDONCE;
			tvins.item.stateMask=tvins.item.state;
			
			// We collected all information we needed. It's time to insert 
			// new item in our TreeCtrl.
			tvins.hInsertAfter=TVI_LAST;
			tvins.hParent=hRoot;
			
			HTREEITEM hCurrent = m_TreeCtrl.InsertItem(&tvins);

			InsertWithComp(hCurrent, pCompisite);
		}
		else
		{
			strMe = pObject->GetObjectName();
			if(strMe.GetLength() < strSpace.GetLength())
			{
				strNeed = strSpace.Left(strSpace.GetLength() - strMe.GetLength());
			}
			CRect rcPos = pObject->GetDrawRect();
			CString strTotal;
			strTotal.Format(_T("(%u,%u,%u,%u)"),rcPos.left,rcPos.top,rcPos.Width(),rcPos.Height());
			strTotal = strMe + strNeed + strTotal;

			TV_INSERTSTRUCT tvins;
			
			tvins.item.mask=TVIF_TEXT|TVIF_STATE|TVIF_IMAGE|TVIF_SELECTEDIMAGE|
				TVIF_PARAM;
			// NAMESPACEOBJECT object is not defined for Desktop item
			tvins.item.lParam=(LPARAM)NULL;
			// Desktop item always has subfolders
			tvins.item.cChildren=0;
			// display name
			tvins.item.pszText=(LPTSTR) (LPCTSTR) strTotal;
			
			// Request icon index for normal state
			tvins.item.iImage=1;
			tvins.item.iSelectedImage=1;
			// expanded from the beginning
			tvins.item.state=TVIS_EXPANDED|TVIS_EXPANDEDONCE;
			tvins.item.stateMask=tvins.item.state;
			
			// We collected all information we needed. It's time to insert 
			// new item in our TreeCtrl.
			tvins.hInsertAfter=TVI_LAST;
			tvins.hParent=hRoot;

			m_TreeCtrl.InsertItem(&tvins);
		}
	}

	m_TreeCtrl.Expand(hRoot,TVE_EXPAND);
	m_TreeCtrl.ShowWindow(SW_SHOW);
}

void CExtListBar::OnSize(UINT nType, int cx, int cy) 
{
	CFOPControlBar::OnSize(nType, cx, cy);
	if( m_TreeCtrl.GetSafeHwnd() != NULL )
	{
		CRect r;
		GetFullRect(r);
		m_TreeCtrl.SetWindowPos( NULL, r.left, r.top, r.Width(), r.Height(), SWP_NOZORDER|SWP_NOACTIVATE );
	}
}

BOOL CExtListBar::OnEraseBkgnd( CDC* pDC )
{
	CFOPControlBar::OnEraseBkgnd(pDC);
	return TRUE;
}
