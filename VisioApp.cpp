// VisioApp.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "VisioApp.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "VisioAppDoc.h"
#include "VisioAppView.h"
#include "FOHyperLink.h"
#include "NewVisualProxy.h"
#include "FOPGDIPlusProxy.h"
#include "NewVisualProxy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVisioAppApp

BEGIN_MESSAGE_MAP(CVisioAppApp, CWinApp)
	//{{AFX_MSG_MAP(CVisioAppApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisioAppApp construction

CVisioAppApp::CVisioAppApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVisioAppApp object

CVisioAppApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CVisioAppApp initialization

static BOOL NEAR PASCAL FO_SetRegKey(LPCTSTR lpszKey, LPCTSTR lpszValue) 
{ 
	if (::RegSetValue(HKEY_CLASSES_ROOT, lpszKey, REG_SZ, lpszValue,
		lstrlen(lpszValue)) != ERROR_SUCCESS)
	{
		TRACE1("Warning: registration database update failed for key'%Fs'\n", lpszKey);
		return FALSE;
	}
	
	return TRUE;
	
} 

BOOL FO_WriteRegStringCreateValue(HKEY MainKey, LPCTSTR SubPath, LPTSTR SectionName,TCHAR *KeyName)
{
	DWORD dwErrorCode;
	HKEY hKey;
	DWORD dwDisposition;
	
	dwErrorCode = RegCreateKeyEx(MainKey,
		SubPath,
		0,
		_T(""),
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		NULL, //Security
		&hKey,
		&dwDisposition );
	if (dwErrorCode != ERROR_SUCCESS) goto end;
	
	if(!KeyName) goto end;
	dwErrorCode = RegSetValueEx(hKey, SectionName, NULL, REG_SZ, 
		(LPBYTE)KeyName, _tcslen(KeyName)*sizeof(TCHAR));
	
end:
	if (hKey) RegCloseKey(hKey);
	if (dwErrorCode == ERROR_SUCCESS) 
	       return TRUE;
	else
		return FALSE;
}

BOOL CVisioAppApp::InitInstance()
{
	// E-XD++ Library Add line.
	AfxOleInit();
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	
	FOEnableXPStyle(TRUE);
	gfxData.InitGUIType(GUI_BLUE);
	FOPEnableLinkRoute(TRUE);
	FOEnableContinueDraw(TRUE);
	//E-XD++ Library add lines.
	FOInit(RUNTIME_CLASS(CNewVisualProxy));

	AfxInitRichEdit();

#if _MSC_VER <= 1200 // MFC 6.0 or earlier
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
#endif // MFC 6.0 or earlier

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("ucancode\\visioapp"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	m_pDocTemplate = new CMultiDocTemplate(
		IDR_VISIOATYPE,
		RUNTIME_CLASS(CVisioAppDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CVisioAppView));
	AddDocTemplate(m_pDocTemplate);

	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	
	m_pMainWnd = pMainFrame;
	DragAcceptFiles(pMainFrame->m_hWnd,TRUE);
	
	if (m_lpCmdLine[0] == '\0')
	{
		OnFileNew();
	}
	else
	{
		OpenDocumentFile(m_lpCmdLine);
	}

	EnableShellOpen( );
	CString      strFileTypeId;
	m_pDocTemplate->GetDocString(strFileTypeId,CDocTemplate::regFileTypeId);
	FO_SetRegKey(_T(".vap"), strFileTypeId);
	
	TCHAR pathname[512];
	TCHAR _pathname[512];
	TCHAR sname[512];
	TCHAR tmppath[512];
	::GetModuleFileName(m_hInstance, pathname, 512);
	TCHAR drive[_MAX_DRIVE];
	TCHAR dir[_MAX_DIR];
	TCHAR fname[_MAX_FNAME];
	TCHAR ext[_MAX_EXT];
	
	_tsplitpath( pathname, drive, dir, fname, ext );
	_tcscpy(sname,fname);
	_tcscat(sname,ext);
	
	_tcscpy(_pathname,_T("\""));
	_tcscat(_pathname,pathname);
	_tcscat(_pathname,_T("\" \"%1\""));
	OutputDebugString(_pathname);
	FO_WriteRegStringCreateValue(HKEY_CLASSES_ROOT,strFileTypeId + _T("\\shell\\open\\command"),NULL,_pathname);
	
	_tcscpy( tmppath , _T(".vap\\OpenWithList\\"));_tcscat( tmppath ,sname);
	FO_WriteRegStringCreateValue(HKEY_CLASSES_ROOT,tmppath,NULL,NULL);
	
	_tcscpy(pathname,_T("Applications\\"));
	_tcscat(pathname,sname);
	_tcscat(pathname,_T("\\shell\\open\\command"));
	FO_WriteRegStringCreateValue(HKEY_CLASSES_ROOT,pathname ,NULL,_pathname);
	
	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	CFOHyperLink m_Home;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_HOMEPAGE, m_Home);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_BUTTON_SYS1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCustomMSampleApp message handlers


void CAboutDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	HKEY hKey1;
	LONG res = RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Shared Tools\\MSInfo",0L,KEY_ALL_ACCESS,&hKey1);
	if (res == ERROR_SUCCESS)
	{
		DWORD bufsize = _MAX_PATH;
		char msinfo[_MAX_PATH];

		res = RegQueryValueEx(hKey1,"Path",0L,0,(LPBYTE)msinfo,(LPDWORD)&bufsize);
		RegCloseKey(hKey1);
		if (res == ERROR_SUCCESS) WinExec(msinfo, SW_SHOW);
	}
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Home.SetColors(RGB(0,0,255), RGB(0,0,255), RGB(51,102,153) );
	m_Home.SetURL("http://www.ucancode.net");
	GetDlgItem(IDC_EDIT_SYS1)->SetWindowText(_T("If you want to learn more about E-XD++ Visualization Enterprise Edition,Visit:http://www.ucancode.net"));
	return TRUE;
}

// App command to run the dialog
void CVisioAppApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CVisioAppApp message handlers

