// NewOpenPageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VisioApp.h"
#include "NewOpenPageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewOpenPageDlg dialog


CNewOpenPageDlg::CNewOpenPageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewOpenPageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewOpenPageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bHasInit = FALSE;
}


void CNewOpenPageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewOpenPageDlg)
	DDX_Control(pDX, IDC_LIST_SYS1, m_ItemList);
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewOpenPageDlg, CDialog)
	//{{AFX_MSG_MAP(CNewOpenPageDlg)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, OnButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_LBN_DBLCLK(IDC_LIST_SYS1, OnDblclkList1)
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_LBN_SELCHANGE(IDC_LIST_SYS1, OnSelchangeList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewOpenPageDlg message handlers

BOOL CNewOpenPageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_bHasInit = TRUE;

	// TODO: Add extra initialization here
	CString strPathX = AfxGetApp()->m_pszHelpFilePath;
	strPathX = strPathX.Left(strPathX.ReverseFind('\\'));
	CString strOtherFile;
	strOtherFile = strPathX+_T("\\Shapes");
	AddInfoToTab(strOtherFile);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNewOpenPageDlg::OnOK() 
{
	// TODO: Add extra validation here
	CListBox *pListBox = (CListBox *)GetDlgItem(IDC_LIST_SYS1);
	int nSel = pListBox->GetCurSel();
	if(nSel < 0)
	{
		pListBox->SetFocus();
		AfxMessageBox(_T("Please select a file for openning..."), MB_OK|MB_ICONINFORMATION);
		return;
	}
	else
	{
		pListBox->GetText(nSel, strSelectFile);
	}
	
	CDialog::OnOK();
}

BOOL CNewOpenPageDlg::FindIn(const CString &strFile)
{
	for(int x = 0; x < m_array.GetSize(); x++)
	{
		if(strFile == m_array.GetAt(x))
		{
			return TRUE;
		}
	}
	
	return FALSE;
}

void CNewOpenPageDlg::AddInfoToTab(const CString &strFolder)
{
	CFileFind ff;
	BOOL res = ff.FindFile(strFolder + _T("\\*.*"));
	CListBox *pListBox = (CListBox *)GetDlgItem(IDC_LIST_SYS1);
	int nCount = 0;
	
 	CFileFind fItem;
	BOOL resItem = fItem.FindFile(strFolder + _T("\\*.trs"));
	while (resItem)
	{// AddItem
		resItem = fItem.FindNextFile();
 		if (!fItem.IsDirectory() && !fItem.IsDots())
		{
 			CString strPath = fItem.GetFilePath();
			CString strTitle = fItem.GetFileTitle();
			CString strCheck = strTitle;
			strCheck.MakeLower();
			strCheck.TrimLeft();
			strCheck.TrimRight();

			if(!FindIn(strCheck))
			{
				pListBox->InsertString(-1, strTitle);
				nCount ++;
			}
		}
	}

	if(nCount > 0)
		pListBox->SetCurSel(0);
}

BOOL FOFileExistsRR(CString strFilePath)
{
	CFileStatus fs;
	return CFile::GetStatus(strFilePath, fs);
}

void CNewOpenPageDlg::OnButtonLoad()
{
	CString Filter = _T("ToolBox page file (*.trs)|*.trs");
	CFileDialog fileDlg( TRUE, _T("trs"), _T(""), OFN_OVERWRITEPROMPT,Filter, NULL);
	if (fileDlg.DoModal() != IDOK)
		return;
	
	CString filename=fileDlg.GetPathName();
	
	CString strPathX = AfxGetApp()->m_pszHelpFilePath;
	strPathX = strPathX.Left(strPathX.ReverseFind('\\'));
	
fopDoStart0312:
	CFORenameDlg dlg;
	dlg.m_strCaption = fileDlg.GetFileTitle();
	if(dlg.DoModal() == IDOK)
	{
		CString strFile = dlg.m_strCaption;
		CString strExt = strFile.Right(3);
		CString strCaption = strFile;
		CString strSave = strCaption;
		strExt.MakeLower();
		if(strExt != _T("trs"))
		{
			strFile += _T(".trs");
			strSave += _T(".trs");
		}
		else
		{
			strCaption = strCaption.Left(strCaption.GetLength() -4);
		}
		
		strFile = strPathX + _T("\\Shapes\\")+ strFile;
		if(FOFileExistsRR(strFile))
		{
			goto fopDoStart0312;
		}

		CFOToolBoxPage* pPage = new CFOToolBoxPage;
		pPage->OpenDocument(filename);
		pPage->SaveDocument(strFile);
		CListBox *pListBox = (CListBox *)GetDlgItem(IDC_LIST_SYS1);
		pListBox->ResetContent();
		CString strOtherFile;
		strOtherFile = strPathX+_T("\\Shapes");

		AddInfoToTab(strOtherFile);

		pListBox->SelectString(-1, strCaption);
		delete pPage;
	}
}

void CNewOpenPageDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	CListBox *pListBox = (CListBox *)GetDlgItem(IDC_LIST_SYS1);
	int nSel = pListBox->GetCurSel();
	if(nSel < 0)
	{
		pListBox->SetFocus();
		AfxMessageBox(_T("Please select a file for openning..."), MB_OK|MB_ICONINFORMATION);
		return;
	}
	else
	{
		pListBox->GetText(nSel, strSelectFile);
	}

	if(!strSelectFile.IsEmpty())
	{
		CString strMsg = strSelectFile + _T(".trs\n");
		strMsg += _T("Do you really need to delete this file from disk? \n Warning: The deleted file cann't be recovered. It is deleted from disk. ");
		if(AfxMessageBox(strMsg, MB_YESNO|MB_ICONINFORMATION ) == IDYES)
		{
			CString strPathX = AfxGetApp()->m_pszHelpFilePath;
			strPathX = strPathX.Left(strPathX.ReverseFind('\\'));
			
			CString strOtherFile;
			strOtherFile = strPathX+_T("\\Shapes\\") + strSelectFile + _T(".trs");
			
			CFile::Remove((const TCHAR *) strOtherFile);
			
			strOtherFile = strPathX+_T("\\Shapes");
			CListBox *pListBox = (CListBox *)GetDlgItem(IDC_LIST_SYS1);
			pListBox->ResetContent();
			AddInfoToTab(strOtherFile);
		}
	}
}

void CNewOpenPageDlg::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CNewOpenPageDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CListBox *pListCtrl1 = (CListBox *)GetDlgItem(IDC_LIST_SYS1);
	if(m_bHasInit) 
	{
		int dx = LOWORD(GetDialogBaseUnits());
		int dy = HIWORD(GetDialogBaseUnits());
		int nButtonWidth = 15*dx;
		int nButtonHeight = 3*dy/2;
		
		CWnd *pwndOkBtn = GetDlgItem(IDOK);
		CWnd *pwndGotoBtn = GetDlgItem(IDCANCEL);
		CWnd *pwndPropBtn = GetDlgItem(IDC_BUTTON_LOAD);
		CWnd *pwndDelBtn = GetDlgItem(IDC_BUTTON_DELETE);
		CWnd *pDesc = GetDlgItem(IDC_DESCRI);
		
		pwndOkBtn->SetWindowPos(0, cx-dx/3-nButtonWidth, dy/4 + 18, nButtonWidth, nButtonHeight, SWP_NOZORDER);
		pwndGotoBtn->SetWindowPos(0, cx-dx/3-nButtonWidth, nButtonHeight+2*dy/4 + 18, nButtonWidth, nButtonHeight, SWP_NOZORDER);
		pwndPropBtn->SetWindowPos(0, cx-dx/3-nButtonWidth, 2*nButtonHeight+3*dy/4 + 18, nButtonWidth, nButtonHeight, SWP_NOZORDER);
		pwndDelBtn->SetWindowPos(0, cx-dx/3-nButtonWidth, 3*nButtonHeight+4*dy/4 + 18, nButtonWidth, nButtonHeight, SWP_NOZORDER);
		pDesc->SetWindowPos(0, cx-dx/3-nButtonWidth, nButtonHeight+4*dy/4 + 100, nButtonWidth, nButtonHeight * 8, SWP_NOZORDER);
		
		pListCtrl1->SetWindowPos(0, dx/3 + 6, dy/4 + 22, cx-dx-nButtonWidth - 6, cy-dy/2 - 25, SWP_NOZORDER);
		
	}
}

void CNewOpenPageDlg::OnSizing(UINT nSide, LPRECT lpRect)
{
	int dx = LOWORD(GetDialogBaseUnits());
	int dy = HIWORD(GetDialogBaseUnits());
	
	int nMinWidth = 30*dx;
	int nMinHeight = 10*dy;
	
	if(lpRect->right - lpRect->left < nMinWidth)
	{
		if(nSide == WMSZ_LEFT || nSide == WMSZ_TOPLEFT || nSide == WMSZ_BOTTOMLEFT)
			lpRect->left = lpRect->right - nMinWidth;
		else
			lpRect->right = lpRect->left + nMinWidth;
	}
	
	if(lpRect->bottom - lpRect->top < nMinHeight) 
	{
		if(nSide == WMSZ_TOP || nSide == WMSZ_TOPLEFT || nSide == WMSZ_TOPRIGHT)
			lpRect->top = lpRect->bottom - nMinHeight;
		else
			lpRect->bottom = lpRect->top + nMinHeight;
	}
}

BOOL FO_GetFileCreateTime(const CString& FileName, CTime& time)
{
	CFileStatus FileStatus;
	if (CFile::GetStatus(FileName, FileStatus))
	{
		time = FileStatus.m_ctime;
		return TRUE;
	}
	
	return FALSE;
}

BOOL FO_GetFileAccessTime(const CString& FileName, CTime& time)
{
	CFileStatus FileStatus;
	if (CFile::GetStatus(FileName, FileStatus))
	{
		time = FileStatus.m_atime;
		return TRUE;
	}
	
	return FALSE;
}

void CNewOpenPageDlg::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	CListBox *pListBox = (CListBox *)GetDlgItem(IDC_LIST_SYS1);
	int nSel = pListBox->GetCurSel();
	if(nSel < 0)
	{
		pListBox->SetFocus();
		AfxMessageBox(_T("Please select a file for openning..."), MB_OK|MB_ICONINFORMATION);
		return;
	}
	else
	{
		pListBox->GetText(nSel, strSelectFile);
	}
	
	if(!strSelectFile.IsEmpty())
	{
		CString strPathX = AfxGetApp()->m_pszHelpFilePath;
		strPathX = strPathX.Left(strPathX.ReverseFind('\\'));
		
		CString strOtherFile;
		strOtherFile = strPathX+_T("\\Shapes\\") + strSelectFile + _T(".trs");
		
		CTime m_Create, m_Ass;
		FO_GetFileCreateTime(strOtherFile, m_Create);

		FO_GetFileAccessTime(strOtherFile, m_Ass);

		CString strMsg = _T("Note:\n");
		CString str;
		str.Format(_T("Create Time: %u/%u/%u\n"), m_Create.GetMonth(), m_Create.GetDay(),m_Create.GetYear());
		strMsg += str;
		
		str.Format(_T("Access Time: %u/%u/%u\n"), m_Ass.GetMonth(), m_Ass.GetDay(),m_Ass.GetYear());
		strMsg += str;
		GetDlgItem(IDC_DESCRI)->SetWindowText(strMsg);

	}
}
