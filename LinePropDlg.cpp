// LinePropDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VisioApp.h"
#include "LinePropDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinePropDlg dialog


CLinePropDlg::CLinePropDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLinePropDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLinePropDlg)
	m_strDescription = _T("");
	m_nLineWidth = 0;
	m_strItem = _T("");
	m_strProductName = _T("");
	m_fUnitPrice = 100.0f;
	//}}AFX_DATA_INIT
	m_bModify = FALSE;
}


void CLinePropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinePropDlg)
	DDX_Control(pDX, IDC_SPIN1, m_spinCtrl);
	DDX_Text(pDX, IDC_EDIT_SYS2, m_strDescription);
	DDX_Text(pDX, IDC_EDIT_SYS1, m_nLineWidth);
	DDV_MinMaxInt(pDX, m_nLineWidth, 0, 100);
	DDX_Text(pDX, IDC_EDIT_ITEM, m_strItem);
	DDX_Text(pDX, IDC_EDIT_PRODUCT, m_strProductName);
	DDX_Text(pDX, IDC_EDIT_UNITPRICE, m_fUnitPrice);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLinePropDlg, CDialog)
	//{{AFX_MSG_MAP(CLinePropDlg)
	ON_WM_NCACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinePropDlg message handlers


BOOL CLinePropDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_spinCtrl.SetBase(10);
	m_spinCtrl.SetRange(0,100);
	m_spinCtrl.SetPos(m_nLineWidth);
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CLinePropDlg::OnNcActivate(BOOL bActive)
{
	if (FODiscardNcActivate())
		return TRUE;

	return CDialog::OnNcActivate(bActive);
}

void CLinePropDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_strOldDescription != m_strDescription ||
		m_nOldLineWidth != m_nLineWidth ||
		m_strOldProductName != m_strProductName ||
		m_strOldItem != m_strItem ||
		m_fOldUnitPrice != m_fUnitPrice)
	{
		m_bModify = TRUE;
	}

	CDialog::OnOK();
}
