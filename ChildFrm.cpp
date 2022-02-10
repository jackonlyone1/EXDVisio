
// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "VisioApp.h"

//E-XD++ Library add lines.
#include "VisioAppDoc.h"
#include "VisioAppView.h"
#include "ChildFrm.h"
#include "fores.h"
#include "MBEventEditDlg6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CFOPMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CFOPMDIChildWnd)
//{{AFX_MSG_MAP(CChildFrame)
// NOTE - the ClassWizard will add and remove mapping macros here.
//    DO NOT EDIT what you see in these blocks of generated code !
//E-XD++ Library add lines.
ON_WM_CREATE()
//E-XD++ Library add lines.
ON_COMMAND(ID_FO_ADD_NEWPAGE, OnFoAddNewpage)
ON_COMMAND(ID_FO_REMOVE_PAGE, OnFoRemovePage)
ON_COMMAND(ID_VIEW_TOOLBOX, OnViewToolbox)
ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBOX, OnUpdateViewToolbox)
ON_COMMAND(ID_MOVE_PREVIOUS, OnMovePrevious)
ON_UPDATE_COMMAND_UI(ID_MOVE_PREVIOUS, OnUpdateMovePrevious)
ON_COMMAND(ID_MOVE_NEXT, OnMoveNext)
ON_UPDATE_COMMAND_UI(ID_MOVE_NEXT, OnUpdateMoveNext)
ON_COMMAND(ID_MB_CREATEPAGE_COPY, OnMbCreatepageCopy)
ON_UPDATE_COMMAND_UI(ID_MB_CREATEPAGE_COPY, OnUpdateMbCreatepageCopy)
ON_COMMAND(ID_CREATE_NEW_PAGE, OnCreateNewPage)
ON_COMMAND(ID_CREATE_SAVE_PAGE, OnCreateSavePage)
ON_COMMAND(ID_REMOVE_PAGE, OnRemovePage)
ON_COMMAND(ID_OPEN_PAGE, OnOpenPage)
ON_COMMAND(ID_TOOLBOX_ICON_STYLE, OnToolboxIconStyle)
ON_UPDATE_COMMAND_UI(ID_TOOLBOX_ICON_STYLE, OnUpdateToolboxIconStyle)
ON_COMMAND(ID_TOOLBOX_ICONNAME_STYLE, OnToolboxIconnameStyle)
ON_UPDATE_COMMAND_UI(ID_TOOLBOX_ICONNAME_STYLE, OnUpdateToolboxIconnameStyle)
ON_COMMAND(ID_TOOLBOX_NAME_STYLE, OnToolboxNameStyle)
	ON_UPDATE_COMMAND_UI(ID_TOOLBOX_NAME_STYLE, OnUpdateToolboxNameStyle)
	ON_COMMAND(ID_SHAPES_LIST, OnShapesList)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_LIST, OnUpdateShapesList)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREAFOAPPWIZARDRUCT cs

	if( !CFOPMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;
//E-XD++ Library add lines.
	cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
		| FWS_ADDTOTITLE | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CFOPMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CFOPMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers
//E-XD++ add lines.
int CChildFrame::OnCreate(LPCREATESTRUCT LPCREATESTRUCT) 
{
	if (CFOPMDIChildWnd::OnCreate(LPCREATESTRUCT) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	if (!m_FileBar.Create(this, _T("ToolBox Bar"), WS_CHILD|WS_VISIBLE|CBRS_LEFT|CBRS_TOOLTIPS|CBRS_SIZE_DYNAMIC, 
		CBRS_FOP_DEFAULT|CBRS_FOP_BDSP, 1212))
	{
		TRACE(_T("Failed to create List Bar\n"));
		return -1;
	}

	if (!m_ListBar.Create(this, _T("Shapes Bar"), WS_CHILD|WS_VISIBLE|CBRS_LEFT|CBRS_TOOLTIPS|CBRS_SIZE_DYNAMIC, 
		CBRS_FOP_DEFAULT|CBRS_FOP_BDSP, 1213))
	{
		TRACE(_T("Failed to create List Bar\n"));
		return -1;
	}

	m_FileBar.EnableDocking(CBRS_ALIGN_ANY);
	m_ListBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBarEx(&m_FileBar, AFX_IDW_DOCKBAR_LEFT, 0.80, 300);
	DockControlBarEx(&m_ListBar, AFX_IDW_DOCKBAR_LEFT, 0.20, 300);
	DockControlBarBottomOf(&m_ListBar, &m_FileBar);

	return 0;
}

//E-XD++ Library add lines.
void CChildFrame::ActivateFrame(int nCmdShow)
{
	nCmdShow = SW_SHOWMAXIMIZED;
	CFOPMDIChildWnd::ActivateFrame(nCmdShow);
	CVisioAppDoc* pDoc = (CVisioAppDoc*) GetActiveDocument();
	
	if(pDoc->bNewDocument)
	{
		pDoc->bNewDocument = FALSE;
	}
	else if(pDoc->bOpenDocument)
	{
		pDoc->bOpenDocument = FALSE;
		if(pDoc->m_pModelManager->GetTabCount() < 2)
		{
			return;
		}
		
		CFOTabPageModel *pModel = (CFOTabPageModel *)pDoc->m_pModelManager->m_arTabs[1];
		
		CFOTabPageView *pView = (CFOTabPageView *)m_wndTab.GetTabControl()->GetTab(0).GetWnd();
		pView->SetTabModel(pModel);
		m_wndTab.GetTabControl()->GetTab(0).SetTabModel(pModel);
		pView->SendMessage(0x0364);
		
		for(int x = 2;x < pDoc->m_pModelManager->GetTabCount(); x++)
		{
			CFOTabPageModel *pModel = (CFOTabPageModel *)pDoc->m_pModelManager->m_arTabs[x];
			if(pModel != NULL)
			{
				m_wndTab.InsertPage(pModel,NULL);
			}
		}
		
		pDoc->m_pModelManager->DeleteTab2(0);
		m_wndTab.SetActiveTab(0);
		
	}

}

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	pContext->m_pNewViewClass = RUNTIME_CLASS(CVisioAppView);

	// creates the tab window
	CVisioAppDoc* pDoc = (CVisioAppDoc*) pContext->m_pCurrentDoc;
	CExtTabModel *pModel = (CExtTabModel *)pDoc->m_pModelManager->InsertTab();
	VERIFY(m_wndTab.Create(this,pDoc->m_pModelManager,pContext));
	// next sheets
	m_wndTab.InsertPage(pModel,pContext);

	return TRUE;
}

void CChildFrame::OnFoAddNewpage() 
{
	// TODO: Add your command handler code here
	CVisioAppDoc* pDoc = (CVisioAppDoc*)GetActiveDocument();
	CExtTabModel *pModel = (CExtTabModel *)pDoc->m_pModelManager->InsertTab();
	m_wndTab.InsertPage(pModel,NULL);
}

void CChildFrame::OnFoRemovePage() 
{
	// TODO: Add your command handler code here
	CVisioAppDoc* pDoc = (CVisioAppDoc*) GetActiveDocument();
	int nCurrentTab = m_wndTab.GetTabControl()->m_nSelect;
	if(m_wndTab.RemoveTab(nCurrentTab))
	{
		pDoc->m_pModelManager->DeleteTab(nCurrentTab);
	}
}

//E-XD++ Library add lines.
void CChildFrame::OnViewToolbox() 
{
	// TODO: Add your command handler code here
	BOOL bVisible = m_FileBar.IsWindowVisible();
	if(bVisible)
	{
		ShowControlBar(&m_FileBar,FALSE,FALSE);
	}
	else
	{
		ShowControlBar(&m_FileBar,TRUE,FALSE);
	}
}

void CChildFrame::OnUpdateViewToolbox(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_FileBar.IsWindowVisible());
}

void CChildFrame::GoToPage(const int &nGoPage) 
{
	// TODO: Add your command handler code here
	int nPage = nGoPage;
	int nCount = m_wndTab.GetTabControl()->GetTabCount();

	int nCurrentTab = m_wndTab.GetTabControl()->m_nSelect;
	if(nCurrentTab == nPage)
	{
		return;
	}
	
	if(nPage < 0)
	{
		nPage = 0;
	}

	if(nPage >= nCount)
	{
		nPage = nCount -1;
	}

	m_wndTab.SetActiveTab(nPage);

}

void CChildFrame::OnMovePrevious() 
{
	// TODO: Add your command handler code here
	int nCurrentTab = m_wndTab.GetTabControl()->m_nSelect;
	if(nCurrentTab -1 >= 0)
	{
		m_wndTab.SetActiveTab(nCurrentTab -1);
	}
	else
	{
		m_wndTab.SetActiveTab(0);
	}
}

void CChildFrame::OnUpdateMovePrevious(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	int nCurrentTab = m_wndTab.GetTabControl()->m_nSelect;
	int nCount = m_wndTab.GetTabControl()->GetTabCount();
	if(nCount == 1)
	{
		pCmdUI->Enable(FALSE);
	}
	else
	{
		pCmdUI->Enable(nCurrentTab != 0);
	}
}

void CChildFrame::OnMoveNext() 
{
	// TODO: Add your command handler code here
	int nCurrentTab = m_wndTab.GetTabControl()->m_nSelect;
	int nCount = m_wndTab.GetTabControl()->GetTabCount();
	if(nCurrentTab +1 < nCount)
	{
		m_wndTab.SetActiveTab(nCurrentTab +1);
	}
	else
	{
		m_wndTab.SetActiveTab(nCount-1);
	}
}

void CChildFrame::OnUpdateMoveNext(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	int nCurrentTab = m_wndTab.GetTabControl()->m_nSelect;
	int nCount = m_wndTab.GetTabControl()->GetTabCount();
	if(nCount == 1)
	{
		pCmdUI->Enable(FALSE);
	}
	else
	{
		pCmdUI->Enable(nCurrentTab < (nCount-1));
	}
}

void CChildFrame::OnMbCreatepageCopy() 
{
	// TODO: Add your command handler code here
	CVisioAppDoc* pDoc = (CVisioAppDoc*)GetActiveDocument();
	CVisioAppView* pView = (CVisioAppView*)GetActiveView();
	// TODO: Add your command handler code here
	CString strCurPage;
	strCurPage = "";
	if(pView != NULL)
	{
		CExtTabModel *pModel = (CExtTabModel *)pView->GetCurrentModel();
		strCurPage = pModel->m_strCaption;
	}
	CMBEventEditDlg6 dlg;
	dlg.strPageName = strCurPage;
	if(dlg.DoModal() == IDOK)
	{
		CString strName = dlg.strPageName;
		if(!strName.IsEmpty())
		{
			CExtTabModel *pModel = (CExtTabModel *)pDoc->m_pModelManager->FindModel(strName);
			if(pModel != NULL)
			{
				CFODrawShapeSet *pList = pModel->GetFormObjects();
				pModel->ResetLinkNames(*pList);

				pModel->EndEditingBack();

				CExtTabModel *pNewModel = (CExtTabModel *)pModel->Copy();
				pNewModel->RestoreAllConnections();
				CString strCaption = pDoc->m_pModelManager->GetUniquePageCaption();
				CExtTabModel *pModelX = (CExtTabModel *)pDoc->m_pModelManager->InsertTab(pNewModel);
				pModelX->m_strCaption = strCaption;
				m_wndTab.InsertPage(pModelX,NULL);
			}
		}
	}
}

void CChildFrame::OnUpdateMbCreatepageCopy(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI;
}

void CChildFrame::OnCreateNewPage() 
{
	// TODO: Add your command handler code here
	m_FileBar.m_wndTool.OnCreateNewPage();
}

void CChildFrame::OnCreateSavePage() 
{
	// TODO: Add your command handler code here
	m_FileBar.m_wndTool.OnCreateSavePage();
}

void CChildFrame::OnRemovePage() 
{
	// TODO: Add your command handler code here
	m_FileBar.m_wndTool.OnRemovePage();
}

void CChildFrame::OnOpenPage() 
{
	// TODO: Add your command handler code here
	m_FileBar.m_wndTool.OnOpenPage();	
}

void CChildFrame::OnToolboxIconStyle() 
{
	// TODO: Add your command handler code here
	m_FileBar.m_wndTool.SetViewStyle(VIEW_ST_ICON_NAME);
}

void CChildFrame::OnUpdateToolboxIconStyle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_FileBar.m_wndTool.GetViewStyle() == VIEW_ST_ICON_NAME);
}

void CChildFrame::OnToolboxIconnameStyle() 
{
	// TODO: Add your command handler code here
	m_FileBar.m_wndTool.SetViewStyle(VIEW_ST_ICON_DETAIL);
}

void CChildFrame::OnUpdateToolboxIconnameStyle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_FileBar.m_wndTool.GetViewStyle() == VIEW_ST_ICON_DETAIL);
}

void CChildFrame::OnToolboxNameStyle() 
{
	// TODO: Add your command handler code here
	m_FileBar.m_wndTool.SetViewStyle(VIEW_ST_NAME);
}

void CChildFrame::OnUpdateToolboxNameStyle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_FileBar.m_wndTool.GetViewStyle() == VIEW_ST_NAME);
}

void CChildFrame::OnShapesList() 
{
	// TODO: Add your command handler code here
	m_FileBar.m_wndTool.OnOpenPage();
}

void CChildFrame::OnUpdateShapesList(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
