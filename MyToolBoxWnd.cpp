// MyToolBoxWnd.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "VisioApp.h"
#include "MyToolBoxWnd.h"
#include "resource.h"
#include <io.h>
#include <direct.h>
#include <stdlib.h>
#include "NewOpenPageDlg.h"
#include "StdioFileEx.h"

#pragma warning (disable : 4244)
#pragma warning (disable : 4800)
#pragma warning (disable : 4018)
#pragma warning (disable : 4010)
#pragma warning (disable : 4663)

#if _MSC_VER >= 1300
#include <fstream>
#include <iosfwd>
using namespace std;
#else
#include <fstream.h>
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyRenameDlg dialog

CMyRenameDlg::CMyRenameDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMyRenameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyRenameDlg)
	m_strCaption = _T("");
	//}}AFX_DATA_INIT
}


void CMyRenameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyRenameDlg)
	DDX_Text(pDX, IDC_FO_RENAME_EDIT, m_strCaption);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyRenameDlg, CDialog)
//{{AFX_MSG_MAP(CMyRenameDlg)
ON_EN_CHANGE(IDC_FO_RENAME_EDIT, OnChangeEdit1)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyRenameDlg message handlers

BOOL CMyRenameDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetWindowText(_T("Please enter a new state text."));
	GetDlgItem(IDC_FO_RENAME_EDIT)->SetFocus();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CMyRenameDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO: Add your control notification handler code here
	
}

/////////////////////////////////////////////////////////////////////////////
// CMyToolBoxWnd

CMyToolBoxWnd::CMyToolBoxWnd()
{
}

CMyToolBoxWnd::~CMyToolBoxWnd()
{
}

BEGIN_MESSAGE_MAP(CMyToolBoxWnd, CFOMultiToolBoxWnd)
//{{AFX_MSG_MAP(CMyToolBoxWnd)
ON_COMMAND(ID_FO_TOOLBOX_CLOSEFILE, OnFoToolboxClosefile)
ON_COMMAND(ID_FO_TOOLBOX_LOADFILE, OnFoToolboxLoadfile)
ON_COMMAND(ID_FO_TOOLBOX_NEWFILE, OnFoToolboxNewfile)
ON_COMMAND(ID_FO_TOOLBOX_SAVEFILE, OnFoToolboxSavefile)
//}}AFX_MSG_MAP
ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyToolBoxWnd diagnostics

#ifdef _DEBUG
void CMyToolBoxWnd::AssertValid() const
{
	CWnd::AssertValid();
}

void CMyToolBoxWnd::Dump(CDumpContext& dc) const
{
	CWnd::Dump(dc);
}
#endif //_DEBUG

BOOL CMyToolBoxWnd::ClosePage() 
{
	// TODO: Add your action handler code here

	int nIndex = GetActiveIndex();

	if( nIndex == -1 )
	{
		return FALSE;
	}
	
	int nCount = m_arPages.GetSize();
	if(nCount <=1)
	{
		return FALSE;
	}

	RemovePage(nIndex);

	gfxData.FreeObjectCache();

	return TRUE;
}

void CMyToolBoxWnd::OpenPage(const CString &strPathName, const CString &strFileName) 
{
	// TODO: Add your command handler code here
	
	CString strName;
	strName.LoadString(IDS_FO_NEW_TOOLBOXPAGE);
	AddPage(strName,TRUE);
	
	m_pToolBoxWnd->LoadResFile(strPathName);
	CString strCaption = strFileName;
	strCaption = strCaption.Left(strCaption.GetLength() -4);
	m_pToolBoxWnd->GetCurrentPage()->SetObjectCaption(strCaption);
	if( RecalcLayout() )
	{
		Invalidate(TRUE);
	}
}

BOOL CMyToolBoxWnd::FindPage(const CString &strTile)
{
	CFOToolBoxPage *pPage = NULL;
	for( int x = m_arPages.GetSize()-1; x >=0; x-- )
	{
		pPage = (CFOToolBoxPage *)m_arPages.GetAt(x);
		if(pPage->GetObjectCaption() == strTile)
		{
			return TRUE;
		}
	}
	
	return FALSE;
}

void CMyToolBoxWnd::GetAllPages(CStringArray &array)
{
	CFOToolBoxPage *pPage = NULL;
	for( int x = m_arPages.GetSize()-1; x >=0; x-- )
	{
		pPage = (CFOToolBoxPage *)m_arPages.GetAt(x);

		CString str = pPage->GetObjectCaption();
		str.MakeLower();
		str.TrimLeft();
		str.TrimRight();
		array.Add(str);
	}
}



void CMyToolBoxWnd::OnCreateNewPage() 
{
	// TODO: Add your command handler code here
	CString strName;
	strName.LoadString(IDS_FO_NEW_TOOLBOXPAGE);
	AddPage(strName,TRUE);
}

BOOL FOPSetDir(const TCHAR* pcszDir)
{         
#if defined( WIN32 )
	return SetCurrentDirectory(pcszDir);
#else   
	if (pcszDir != NULL && *pcszDir != '\0')
	{
		return _chdrive(_totupper(*pcszDir) - 'A' + 1) == 0 &&
			chdir(pcszDir) == 0;
	}               
	
	return FALSE;
#endif
}

BOOL FOFileExists(CString strFilePath)
{
	CFileStatus fs;
	return CFile::GetStatus(strFilePath, fs);
}

CStringList  * FOGetFileSystemList()
{
	CStringList *pStringList = new CStringList();

	::SetErrorMode(SEM_FAILCRITICALERRORS);
	
	for (int nDriveNum = 0; nDriveNum < 26; nDriveNum++)
	{
		
#ifdef WIN32
		
		CString DriveName = (char)('a' + nDriveNum);
		DriveName = DriveName + ":\\";
		if (GetDriveType((const TCHAR *)DriveName) > 1)
		{
			CString DriveName = (char)('a' + nDriveNum);
			DriveName = DriveName + ":\\";
			pStringList->AddTail((const TCHAR *)DriveName);
		}
		
#else
		
		if (GetDriveType(nDriveNum) != 0)
		{
			CString DriveName = (char)('a' + nDriveNum);
			DriveName = DriveName + ":\\";
			pStringList->AddTail((const char *)DriveName);
		}
#endif
		
	} 
	::SetErrorMode(0);
	
	return pStringList;
}

BOOL FOFileSystemExists(const CString& FileSystemName)
{
	CString TempFSName = FileSystemName;
	TempFSName.MakeLower();
	
	BOOL bRetVal = FALSE;
	CStringList *pFSList = FOGetFileSystemList();
	for (POSITION pos = pFSList->GetHeadPosition(); pos != NULL; )
	{
		CString FSName = pFSList->GetNext(pos);
		if (FSName == TempFSName)
		{
			bRetVal = TRUE;
			break;
		}
	}
	
	delete pFSList;
	pFSList = NULL;
	
	return bRetVal;
}

BOOL FODirectoryExists(const CString& Path)
{
#ifdef WIN32
	DWORD dwRetVal = GetFileAttributes( Path );
	if ( dwRetVal == 0xFFFFFFFF )
		return FALSE;

	else if (dwRetVal & FILE_ATTRIBUTE_DIRECTORY)
		return TRUE;
	
	return FALSE;
#else
	CFileStatus FileStatus;
	
	if (CFile::GetStatus(Path, FileStatus) == TRUE  &&
		FileStatus.m_attribute & directory)
	{
		return TRUE;
	}
	else if (FOFileSystemExists(GetFullPathName(Path)))
	{
		return TRUE;
	}
	
	return FALSE;
#endif
}

BOOL FOMakeDirectory(const CString& NewDirectory)
{
#ifdef WIN32
	
	SECURITY_ATTRIBUTES security_attrib;
	security_attrib.nLength = sizeof(SECURITY_ATTRIBUTES);
	security_attrib.lpSecurityDescriptor = NULL;
	security_attrib.bInheritHandle = TRUE;
	
	BOOL bRetVal = CreateDirectory((const TCHAR *) NewDirectory, &security_attrib);
	return bRetVal;
	
#else
	
	int nRetVal = _tmkdir((const char *) NewDirectory);
	if (nRetVal == -1)
	{
		return FALSE;
	}
	
	return TRUE;
	
#endif
}

BOOL FOMakePath(const CString& NewDirectory)
{
	CString NewDir = NewDirectory;
	CString  DirName;
	BOOL    bRetVal = TRUE;

	if (NewDir.GetLength() == 0)
	{
		return FALSE;
	}

	if (NewDir[NewDir.GetLength() - 1] != '\\')
	{
		NewDir = NewDir + '\\';
	}

	UINT  nIndex = 0;
	BOOL  bDone = FALSE;
	while (!bDone)
	{
		nIndex = NewDir.Find('\\');
		if (nIndex != -1)
		{
			DirName = DirName + NewDir.Left(nIndex);
			NewDir = NewDir.Right(NewDir.GetLength() - nIndex - 1);
			
			if (DirName.GetLength() >= 1  &&  DirName[DirName.GetLength() - 1] != ':')
			{
				bRetVal = FOMakeDirectory(DirName);
			}
			DirName = DirName + '\\';
		}
		else
		{
			bDone = TRUE;
		}
	}

	return bRetVal;
}

void CMyToolBoxWnd::OnCreateSavePage() 
{
	// TODO: Add your command handler code here
	CString str = GetToolBoxWnd()->GetCurrentPage()->m_strFileName;
	if(GetToolBoxWnd()->GetCurrentPage()->m_strFileName.IsEmpty())
	{
		
		CString strPathX = AfxGetApp()->m_pszHelpFilePath;
		strPathX = strPathX.Left(strPathX.ReverseFind('\\'));

		CString strCheck = strPathX + _T("\\Shapes\\");
		if(!FODirectoryExists(strCheck))
		{
			FOMakePath(strCheck);
		}
		FOPSetDir(strPathX);
		
//		CString title;
//		title.LoadString(IDS_FO_SAVE_FILE_TITLE);
		
//		CString strExt;
//		strExt.LoadString(IDS_FO_TRSFILE_EXT);
//		CFileDialog dlgFile (FALSE,NULL,NULL,OFN_HIDEREADONLY| OFN_OVERWRITEPROMPT,strExt,this);
//		if(dlgFile.DoModal() == IDOK)
fopDoStart0311:
		CMyRenameDlg dlg;
//		dlg.GetDlgItem(IDC_FO_RENAME_EDIT)->SetFocus();
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
			if(FOFileExists(strFile))
			{
				goto fopDoStart0311;
			}

			GetToolBoxWnd()->GetCurrentPage()->m_strFileName = strFile;
			GetToolBoxWnd()->SaveResFile(strFile);
			GetToolBoxWnd()->GetCurrentPage()->SetObjectCaption(strCaption);
			if( RecalcLayout())
			{
				Invalidate(TRUE);
			}

			CStringArray m_Files;

			CString strOtherFile;
			strOtherFile = strPathX+_T("\\Shapes\\index.dat");
			gfxData.m_strDefToolboxFile	= _T("index.dat");
			CStdioFile m_File;
			if(m_File.Open(strOtherFile,CFile::modeRead | CFile::typeText))
			{
				CString strTemp;
				int nNumber = 100;
				while (m_File.ReadString(strTemp))
				{
					strTemp.TrimLeft();
					strTemp.TrimRight();
					if(!strTemp.IsEmpty())
					{
						m_Files.Add(strTemp);
					}	
				}
				m_File.Close();
			}

			CString strFileName;
			strFileName = strOtherFile;// File name
			
			CStdioFile fileWriteUnicode;
			
			if (fileWriteUnicode.Open(strFileName, 
				CFile::modeCreate | CFile::modeWrite))
			{
				for( int x = 0; x < m_Files.GetSize(); x++)
				{
					CString str = m_Files.GetAt(x);
					fileWriteUnicode.WriteString(str + _T("\n"));
				}
				
				CString strCur;
				strCur.Format(_T("%u#%s"),m_Files.GetSize(), strSave);
				fileWriteUnicode.WriteString(strCur + _T("\n"));
				
				fileWriteUnicode.Close();
			}	
		}
	}
	else
	{
		GetToolBoxWnd()->GetCurrentPage()->SetModifyFlag(TRUE);
		GetToolBoxWnd()->SaveFile();
	}

	
}

CString FOPGetFileName(const CString& strFullPath)
{
	CString strFile = strFullPath; 
	int nIndex = strFile.ReverseFind(_T('\\'));
	int nIndex2 = strFile.ReverseFind(_T('/'));
	if(nIndex2 > nIndex) 
		nIndex = nIndex2;

	if(nIndex >= 0)
	{
		strFile = strFile.Right(strFile.GetLength() - nIndex - 1);
	}
	
	return strFile;
}

void CMyToolBoxWnd::OnRemovePage() 
{
	// TODO: Add your command handler code here
	CString strMsg = FOPGetFileName(GetToolBoxWnd()->GetCurrentPage()->m_strFileName);
	strMsg = strMsg.Left(strMsg.GetLength() - 4);
	strMsg += _T("\n\n");
	strMsg += _T("Do you make sure you really need to remove this page?");

	if(GetToolBoxWnd()->GetCurrentPage()->m_strFileName.IsEmpty())
	{
		ClosePage();
	}
	else //if(AfxMessageBox(strMsg,
	//	MB_YESNO|MB_ICONINFORMATION) == IDYES)
	{
		CString strxx = GetToolBoxWnd()->GetCurrentPage()->GetObjectCaption();
		strxx += _T(".trs");
		if(!ClosePage())
			return;

		CString strPathX = AfxGetApp()->m_pszHelpFilePath;
		strPathX = strPathX.Left(strPathX.ReverseFind('\\'));

		CStringArray m_Files;
		CString strOtherFile;
		strOtherFile = strPathX+_T("\\Shapes\\index.dat");
		gfxData.m_strDefToolboxFile	= _T("index.dat");
		CStdioFile m_File;
		if(m_File.Open(strOtherFile,CFile::modeRead | CFile::typeText))
		{
			CString strTemp;
			int nNumber = 100;
			while (m_File.ReadString(strTemp))
			{
				strTemp.TrimLeft();
				strTemp.TrimRight();
				if(!strTemp.IsEmpty())
				{
					CString strTitle;
					CString strFile;
					strTitle = strTemp.Left(strTemp.ReverseFind('#'));
					strFile = strTemp.Right(strTemp.GetLength() - strTitle.GetLength() -1);
					if((!strTitle.IsEmpty()) && (!strFile.IsEmpty()))
					{
						if(strFile != strxx)
							m_Files.Add(strTemp);
					}
				}	
			}
			m_File.Close();
		}
		
		CString strFileName;
		strFileName = strOtherFile;// File name
		
		CStdioFile fileWriteUnicode;
		
		if (fileWriteUnicode.Open(strFileName, 
			CFile::modeCreate | CFile::modeWrite))
		{
			for( int x = 0; x < m_Files.GetSize(); x++)
			{
				CString str = m_Files.GetAt(x);
				fileWriteUnicode.WriteString(str + _T("\n"));
			}
	
			fileWriteUnicode.Close();
		}
	}
}

void CMyToolBoxWnd::OnOpenPage() 
{
	// TODO: Add your command handler code here

	CString strPathX = AfxGetApp()->m_pszHelpFilePath;
	strPathX = strPathX.Left(strPathX.ReverseFind('\\'));
	FOPSetDir(strPathX);

	CNewOpenPageDlg dlgFile;
	GetAllPages(dlgFile.m_array);
	if(dlgFile.DoModal() == IDOK)
	{
		if(!dlgFile.strSelectFile.IsEmpty())
		{
			CString strFile = dlgFile.strSelectFile + _T(".trs");

			CString strSave = strFile;
			
			CString strOtherFile;
			strOtherFile = strPathX+_T("\\Shapes\\") + strFile;
			OpenPage(strOtherFile, strFile);

			CString strPathX = AfxGetApp()->m_pszHelpFilePath;
			strPathX = strPathX.Left(strPathX.ReverseFind('\\'));
			
			{
				CStringArray m_Files;
				CString strOtherFile;
				strOtherFile = strPathX+_T("\\Shapes\\index.dat");
				gfxData.m_strDefToolboxFile	= _T("index.dat");
				CStdioFile m_File;
				if(m_File.Open(strOtherFile,CFile::modeRead | CFile::typeText))
				{
					CString strTemp;
					int nNumber = 100;
					while (m_File.ReadString(strTemp))
					{
						strTemp.TrimLeft();
						strTemp.TrimRight();
						if(!strTemp.IsEmpty())
						{
							CString strTitle;
							CString strFile;
							strTitle = strTemp.Left(strTemp.ReverseFind('#'));
							strFile = strTemp.Right(strTemp.GetLength() - strTitle.GetLength() -1);
							if((!strTitle.IsEmpty()) && (!strFile.IsEmpty()))
							{
								m_Files.Add(strTemp);
							}
						}	
					}
					m_File.Close();
				}
				
				CString strFileName;
				strFileName = strOtherFile;// File name
				
				CStdioFile fileWriteUnicode;
				
				if (fileWriteUnicode.Open(strFileName, 
					CFile::modeCreate | CFile::modeWrite))
				{
					for( int x = 0; x < m_Files.GetSize(); x++)
					{
						CString str = m_Files.GetAt(x);
						fileWriteUnicode.WriteString(str + _T("\n"));
					}
					
					CString strCur;
					strCur.Format(_T("%u#%s"),m_Files.GetSize(), strSave);
					fileWriteUnicode.WriteString(strCur + _T("\n"));
					
					fileWriteUnicode.Close();
				}
			}
			gfxData.FreeObjectCache();
		}
	}	
}

void CMyToolBoxWnd::OnFoToolboxClosefile() 
{
	// TODO: Add your action handler code here
	OnRemovePage();
}

void CMyToolBoxWnd::OnFoToolboxLoadfile() 
{
	// TODO: Add your action handler code here
	OnOpenPage();
}

void CMyToolBoxWnd::OnFoToolboxNewfile() 
{
	// TODO: Add your action handler code here
	OnCreateNewPage();
}

void CMyToolBoxWnd::OnFoToolboxSavefile() 
{
	// TODO: Add your action handler code here
	OnCreateSavePage();
}

void CMyToolBoxWnd::DoCreateToolBoxPageWnd()
{
	m_pToolBoxWnd = new CMyToolBoxPageWnd;
}

/////////////////////////////////////////////////////////////////////////////
// CMyToolBoxPageWnd

CMyToolBoxPageWnd::CMyToolBoxPageWnd()
{
}

CMyToolBoxPageWnd::~CMyToolBoxPageWnd()
{
}

BEGIN_MESSAGE_MAP(CMyToolBoxPageWnd, CFOToolBoxPageWnd)
//{{AFX_MSG_MAP(CMyToolBoxPageWnd)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CMyToolBoxPageWnd::DoSaveResFile()
{
	if(GetCurrentPage()->m_strFileName.IsEmpty())
	{
		CString strPathX = AfxGetApp()->m_pszHelpFilePath;
		strPathX = strPathX.Left(strPathX.ReverseFind('\\'));

		CString strCheck = strPathX + _T("\\Shapes\\");
		if(!FODirectoryExists(strCheck))
		{
			FOMakePath(strCheck);
		}

		FOPSetDir(strPathX);
		
		//		CString title;
		//		title.LoadString(IDS_FO_SAVE_FILE_TITLE);
		
		//		CString strExt;
		//		strExt.LoadString(IDS_FO_TRSFILE_EXT);
		//		CFileDialog dlgFile (FALSE,NULL,NULL,OFN_HIDEREADONLY| OFN_OVERWRITEPROMPT,strExt,this);
		//		if(dlgFile.DoModal() == IDOK)
fopDoStart0311:
		CMyRenameDlg dlg;
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
			if(FOFileExists(strFile))
			{
				goto fopDoStart0311;
			}
			
			GetCurrentPage()->m_strFileName = strFile;
			SaveResFile(strFile);
			GetCurrentPage()->SetObjectCaption(strCaption);
//			if( RecalcLayout())
			{
				Invalidate(TRUE);
			}
			
			CStringArray m_Files;
			
			CString strOtherFile;
			strOtherFile = strPathX+_T("\\Shapes\\index.dat");
			gfxData.m_strDefToolboxFile	= _T("index.dat");
			CStdioFile m_File;
			if(m_File.Open(strOtherFile,CFile::modeRead | CFile::typeText))
			{
				CString strTemp;
				int nNumber = 100;
				while (m_File.ReadString(strTemp))
				{
					strTemp.TrimLeft();
					strTemp.TrimRight();
					if(!strTemp.IsEmpty())
					{
						m_Files.Add(strTemp);
					}	
				}
				m_File.Close();
			}
			
			CString strFileName;
			strFileName = strOtherFile;// File name

			CStdioFile fileWriteUnicode;
			
			if (fileWriteUnicode.Open(strFileName, 
				CFile::modeCreate | CFile::modeWrite))
			{
				for( int x = 0; x < m_Files.GetSize(); x++)
				{
					CString str = m_Files.GetAt(x);
					fileWriteUnicode.WriteString(str + _T("\n"));
				}

				CString strCur;
				strCur.Format(_T("%u#%s"),m_Files.GetSize(), strSave);
				fileWriteUnicode.WriteString(strCur + _T("\n"));

				fileWriteUnicode.Close();
			}
			
		}
	}
	else
	{
		GetCurrentPage()->SetModifyFlag(TRUE);
		SaveFile();
		gfxData.FreeObjectCache();
	}

	return TRUE;
}

CMenu * CMyToolBoxPageWnd::CreateSubContextMenu()
{
	if (m_pContextMenu)
		delete m_pContextMenu;
	
	CMenu* pMenu;
	m_pContextMenu = new CMenu();
	m_pContextMenu->LoadMenu(IDR_NEW_MENU);
	
	pMenu = m_pContextMenu->GetSubMenu(1);
	
	ASSERT_VALID(pMenu);
	return pMenu;
}

BOOL X_FindWithIndex(CStringArray &m_Array, const CString &strValue)
{
	for(int x = 0; x < m_Array.GetSize(); x++)
	{
		CString nCur = m_Array.GetAt(x);
		if(nCur == strValue)
		{
			return TRUE;
		}
	}
	
	return FALSE;
}

CString X_GetCorrectValue(CStringArray &m_Array, CString strCorrect)
{
	int nCorrect = 0;
	for(;;)
	{
		if(X_FindWithIndex(m_Array, strCorrect))
		{
			nCorrect ++;
			strCorrect.Format(_T("K%u"), nCorrect);
		}
		else
		{
			return strCorrect;
		}
	}
	
	return strCorrect;
}

void CMyToolBoxPageWnd::OnAddState() 
{
	// TODO: Add your command handler code here
	
}

void CMyToolBoxPageWnd::OnUpdateAddState(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here

}


void CMyToolBoxPageWnd::OnChangeAllProp() 
{
	// TODO: Add your command handler code here
	
	
}

void CMyToolBoxPageWnd::OnUpdateChangeAllProp(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here

}

