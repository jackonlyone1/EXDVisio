// MBEventEditDlg6.cpp : implementation file
//

#include "stdafx.h"
#include "VisioApp.h"
#include "MBEventEditDlg6.h"
#include "mainfrm.h"
#include "VisioAppDoc.h"
#include "VisioAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMBEventEditDlg6 dialog


CMBEventEditDlg6::CMBEventEditDlg6(CWnd* pParent /*=NULL*/)
	: CDialog(CMBEventEditDlg6::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMBEventEditDlg6)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	strPageName = "";
}


void CMBEventEditDlg6::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMBEventEditDlg6)
	DDX_Control(pDX, IDC_MB_PAGE_LIST, m_ItemList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMBEventEditDlg6, CDialog)
	//{{AFX_MSG_MAP(CMBEventEditDlg6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMBEventEditDlg6 message handlers
void CMBEventEditDlg6::InitListBox()
{
	m_ItemList.ResetContent();
	CMainFrame *pParent = STATIC_DOWNCAST(CMainFrame,AfxGetMainWnd());
	ASSERT_VALID(pParent);
	CVisioAppDoc *pDoc = (CVisioAppDoc *)pParent->GetActiveFrame()->GetActiveDocument();
	int nCount = pDoc->m_pModelManager->GetTabCount();
	for (int i = 0; i < nCount; i++)
	{
		CFOTabPageModel &pObj = pDoc->m_pModelManager->GetTab(i);
		CString strAdd;
		strAdd = pObj.m_strCaption;
		m_ItemList.AddString(strAdd);
	}
	
}

BOOL CMBEventEditDlg6::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitListBox();
	m_ItemList.SelectString(-1,strPageName);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMBEventEditDlg6::OnOK() 
{
	// TODO: Add extra validation here
	int nCur = m_ItemList.GetCurSel();
	if(nCur >= 0)
	{
		m_ItemList.GetText(nCur,strPageName);
	}
	CDialog::OnOK();
}
