// VisioAppDoc.cpp : implementation of the CVisioAppDoc class
//

#include "stdafx.h"
#include "VisioApp.h"

#include "VisioAppDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVisioAppDoc

IMPLEMENT_DYNCREATE(CVisioAppDoc, COleDocument)

BEGIN_MESSAGE_MAP(CVisioAppDoc, COleDocument)
	//{{AFX_MSG_MAP(CVisioAppDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
#ifdef OLE_CLIENT_SUPPORT	
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, COleDocument::OnUpdateObjectVerbMenu)
#endif
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisioAppDoc construction/destruction

CVisioAppDoc::CVisioAppDoc()
{
	// TODO: add one-time construction code here
	//E-XD++ Library add lines.
	m_pModelManager = new CExtTabModelManager;
	bNewDocument = FALSE;
	bOpenDocument = FALSE;
	// Use OLE compound files
//	EnableCompoundFile();
	
	EnableConnections();
	
	EnableAutomation();
	
	AfxOleLockApp();
}

CVisioAppDoc::~CVisioAppDoc()
{
	AfxOleUnlockApp();
	//E-XD++ Library add lines.
	if(m_pModelManager != NULL)
	{
		delete m_pModelManager;
		m_pModelManager = NULL;
	}
}

BOOL CVisioAppDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVisioAppDoc serialization

void CVisioAppDoc::Serialize(CArchive& ar)
{
	//E-XD++ Library add lines.
	m_pModelManager->Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}



//E-XD++ Library add lines.
void CVisioAppDoc::SetModifiedFlag(BOOL b)
{
	// Do nothing
	m_pModelManager->SetModifiedFlag(b);
}

//added override
BOOL CVisioAppDoc::IsModified()
{
	return m_pModelManager->IsModified();
}

void CVisioAppDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	COleDocument::DeleteContents();
	m_pModelManager->ResetContent();
}


BOOL CVisioAppDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	bOpenDocument = TRUE;
	if (!COleDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	return TRUE;
}

BOOL CVisioAppDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	return COleDocument::OnSaveDocument(lpszPathName);
}
/////////////////////////////////////////////////////////////////////////////
// CVisioAppDoc diagnostics

#ifdef _DEBUG
void CVisioAppDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CVisioAppDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVisioAppDoc commands
