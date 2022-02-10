// OutputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Resource.h"
#include "OutputDlg.h"
#include "DirDialog.h"
#include <io.h>
#include <direct.h>
#include <stdlib.h>

#if _MSC_VER >= 1300
	#include <fstream>
#else
	#include <fstream.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputDlg dialog


COutputDlg::COutputDlg(CWnd* pParent /*=NULL*/)
: CDialog(COutputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COutputDlg)
	//}}AFX_DATA_INIT
	m_strPath = _T("c:\\temp\\");
}


void COutputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COutputDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COutputDlg, CDialog)
//{{AFX_MSG_MAP(COutputDlg)
ON_BN_CLICKED(IDC_BUTTON_SYS1, OnButton1)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutputDlg message handlers

void COutputDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CDirDialog dlg;
	dlg.SetWindowTitle("Select Directory");
	dlg.SetSelDir(m_strPath);
	if(dlg.DoModal() == IDOK)
	{
		CString Path = dlg.GetPathname();
		if(Path.Right(1) != "\\")
		{
			Path += "\\";
		}
		GetDlgItem(IDC_EDIT_PATH)->SetWindowText(Path);
	}
}

BOOL DirectoryExists(const CString& Path)
{
#ifdef WIN32
	DWORD dwRetVal = GetFileAttributes( Path );
	if ( dwRetVal == 0xFFFFFFFF )
		return FALSE;
	
	// SB:  check for directory attribute
	else if (dwRetVal & FILE_ATTRIBUTE_DIRECTORY)
		return TRUE;
	
	return FALSE;
#else
	CFileStatus FileStatus;
	
	if (CFile::GetStatus(Path, FileStatus) == TRUE  &&
		FileStatus.m_attribute & directory)
	{
		return TRUE;
	} // if
	else if (FileSystemExists(GetFullPathName(Path)))
	{
		return TRUE;
	} // else if
	
	return FALSE;
#endif
} // DirectoryExists

BOOL MakeDirectory(const CString& pcszDirectory)
{
	static TCHAR cSlash = _T('\\');
	
	BOOL bRetVal = FALSE;
	
	const int nLength = _tcslen( pcszDirectory ) + 1;
	LPTSTR pszDirectoryPath = (LPTSTR)malloc( nLength * sizeof( TCHAR ) );
	if( pszDirectoryPath )
	{
		
		LPCTSTR pcszNextDirectory = pcszDirectory;
		
		//
		//	Determine if the path is a UNC path. We do this by looking at the first two bytes
		//	and checkin they are both backslashes
		if( nLength > 2 && *pcszNextDirectory == cSlash && *(pcszNextDirectory+1) == cSlash )
		{
			//	We need to skip passed this bit and copy it into out local path.
			//	"\\Russ\C\"
			pcszNextDirectory += 2;
			while( *pcszNextDirectory && *pcszNextDirectory != cSlash )	pcszNextDirectory++;
			pcszNextDirectory++;
			while( *pcszNextDirectory && *pcszNextDirectory != cSlash )	pcszNextDirectory++;
			_tcsncpy( pszDirectoryPath, pcszDirectory, pcszNextDirectory - pcszDirectory );
			pszDirectoryPath[ pcszNextDirectory - pcszDirectory ] = '\000';
		}
		
		//
		//	Set the return value to true because the nly thing that can fail now is the
		//	CreateDirectory. If that fails then we change the return value back to fals.
		bRetVal = TRUE;
		
		//
		//	Now, loop over the path, creating directories as we go. If we fail at any point then get out of the loop
		do
		{
			if( *pcszNextDirectory )
				pcszNextDirectory++;
			
			while( *pcszNextDirectory && *pcszNextDirectory != cSlash )
				pcszNextDirectory++;
			
			_tcsncpy( pszDirectoryPath, pcszDirectory, pcszNextDirectory - pcszDirectory );
			pszDirectoryPath[ pcszNextDirectory - pcszDirectory ] = '\000';
			
			if( _taccess( pszDirectoryPath, 0 ) )
			{
				if( !CreateDirectory( pszDirectoryPath, NULL ) )
				{
					bRetVal = FALSE;
					break;
				}
			}
		}
		while( *pcszNextDirectory );
		
		free( pszDirectoryPath );
		pszDirectoryPath = NULL;
	}
	return bRetVal;
} // MakeDirectory


void COutputDlg::OnOK() 
{
	// TODO: Add extra validation here
	GetDlgItem(IDC_EDIT_PATH)->GetWindowText(m_strPath);
	if(m_strPath.IsEmpty())
	{
		GetDlgItem(IDC_EDIT_PATH)->SetFocus();
		return;
	}
	
	if(m_strPath.Right(1) != "\\")
	{
		m_strPath += "\\";
	}
	
	if(!DirectoryExists(m_strPath))
	{
		MakeDirectory(m_strPath);
	}
	
	CDialog::OnOK();
}

BOOL COutputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_EDIT_PATH)->SetWindowText(m_strPath);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
