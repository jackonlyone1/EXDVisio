// MyToolBoxBar.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MyToolBoxBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyToolBoxBar

CMyToolBoxBar::CMyToolBoxBar()
{
}

CMyToolBoxBar::~CMyToolBoxBar()
{
	POSITION pos = m_Pages.GetHeadPosition();
	while(pos != NULL)
	{
		delete m_Pages.GetNext(pos);
	}
	m_Pages.RemoveAll();
}


BEGIN_MESSAGE_MAP(CMyToolBoxBar, CFOPControlBar)
	//{{AFX_MSG_MAP(CMyToolBoxBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMyToolBoxBar message handlers

int CMyToolBoxBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFOPControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_wndTool.Create(WS_CHILD|WS_VISIBLE|WS_TABSTOP|WS_EX_CLIENTEDGE,CRect(0,0,100,100),this,1232);
	
	// Do create toolbox pages.
	DoCreatePages();

	return 0;
}

void CMyToolBoxBar::DoCreatePages()
{
	LoadFromFile();	

	if(m_Pages.GetCount() <= 0)
	{
		CString strNewTitle;
		strNewTitle.LoadString(IDS_FO_NEW_TOOLBOXPAGE);
		m_wndTool.AddPage(strNewTitle);
		m_wndTool.ActivatePage(0);
	}
	else
	{
		POSITION pos = m_Pages.GetHeadPosition();
		while(pos != NULL)
		{
			CFOListItemObj *pObj = (CFOListItemObj *)m_Pages.GetNext(pos);
			CString strPathX = AfxGetApp()->m_pszHelpFilePath;
			strPathX = strPathX.Left(strPathX.ReverseFind('\\'));
			CString strOtherFile;
			strOtherFile = strPathX+_T("\\Shapes\\");
			strOtherFile += pObj->strFileName;
			CString strTitle = pObj->strFileName;
			strTitle = strTitle.Left(strTitle.GetLength() -4);
			m_wndTool.AddPage(strTitle);
			m_wndTool.GetToolBoxWnd()->LoadResFile(strOtherFile);
			m_wndTool.GetToolBoxWnd()->GetCurrentPage()->SetObjectCaption(strTitle);

		}
		
		m_wndTool.ActivatePage(0);
	}
}

void CMyToolBoxBar::OnSize(UINT nType, int cx, int cy) 
{
	CFOPControlBar::OnSize(nType, cx, cy);
	
	if( m_wndTool.GetSafeHwnd() != NULL )
	{
		CRect r;
		GetFullRect(r);

		m_wndTool.SetWindowPos( NULL, r.left, r.top, r.Width(), r.Height(), SWP_NOZORDER|SWP_NOACTIVATE );
	}
}

BOOL CMyToolBoxBar::OnEraseBkgnd( CDC* pDC )
{
	CFOPControlBar::OnEraseBkgnd(pDC);
	return TRUE;
}

CFOListItemObj *CMyToolBoxBar::FindObjByID(int nIndex)
{
	POSITION pos = m_Pages.GetHeadPosition();
	while(pos != NULL)
	{
		CFOListItemObj *pObj = (CFOListItemObj *)m_Pages.GetNext(pos);
		if(pObj->nID == nIndex)
		{
			return pObj;
		}
	}
	return NULL;
}

void CMyToolBoxBar::LoadFromFile()
{
	CString strPathX = AfxGetApp()->m_pszHelpFilePath;
	strPathX = strPathX.Left(strPathX.ReverseFind('\\'));
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
					CFOListItemObj *pObj = new CFOListItemObj;
					pObj->strTitle = strTitle;
					pObj->strFileName = strFile;
					pObj->nID = nNumber;
					m_Pages.AddTail(pObj);
					nNumber ++;
				}
			}	
		}
		m_File.Close();
	}
}
