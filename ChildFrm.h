// ChildFrm.h : interface of the CChildFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDFRM_H__6EB9193F_17F6_43F7_A44A_C1058DB67CD4__INCLUDED_)
#define AFX_CHILDFRM_H__6EB9193F_17F6_43F7_A44A_C1058DB67CD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ExtListBar.h"
#include "MyToolBoxBar.h"

 
//===========================================================================
// Summary:
//     The CChildFrame class derived from CFOPMDIChildWnd
//      Child Frame
//===========================================================================

class CChildFrame : public CFOPMDIChildWnd
{
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N C R E A T E, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CChildFrame---Child Frame, Specifies a CChildFrame object.
	DECLARE_DYNCREATE(CChildFrame)
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Child Frame, Constructs a CChildFrame object.
	//		Returns A  value.
	CChildFrame();

// Attributes
public:
	
 
	// File Bar, This member specify CMyToolBoxBar object.  
	CMyToolBoxBar m_FileBar;
 
	// List Bar, This member specify CExtListBar object.  
	CExtListBar		   m_ListBar;

 
	// m_wndTab, This member specify E-XD++ CFOMultiPageTabWnd object.  
	CFOMultiPageTabWnd m_wndTab; 

// Operations
public:

	// Goto a specify page.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Go To Page, None Description.
	// Parameters:
	//		&nPage---&nPage, Specifies A integer value.
	void GoToPage(const int &nPage);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildFrame)
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Before Create Window, Called before the creation of the Windows window attached to this CWnd object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		cs---Specifies a CREATESTRUCT& cs object.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//E-XD++ Library add lines.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create Client, Called as a part of window creation.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpcs---Specifies a LPCREATESTRUCT lpcs object.  
	//		pContext---pContext, A pointer to the CCreateContext or NULL if the call failed.
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Activate Frame, Activates the specified object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		nCmdShow---Cmd Show, Specifies A integer value.
	virtual void ActivateFrame(int nCmdShow);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Child Frame, Destructor of class CChildFrame
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CChildFrame();
#ifdef _DEBUG
	
	//-----------------------------------------------------------------------
	// Summary:
	// Assert Valid, Assert performs a validity check on this object by checking its internal state.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void AssertValid() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Dump, Dumps the contents of your object to a CDumpContext object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		dc---Specifies a CDumpContext& dc object.
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(CChildFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//E-XD++ Library add lines.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create, Called as a part of window creation.
	//		Returns a int type value.  
	// Parameters:
	//		LPCREATESTRUCT---P C R E A T E S T R U C T, Specifies a LPCREATESTRUCT LPCREATESTRUCT object.
	afx_msg int OnCreate(LPCREATESTRUCT LPCREATESTRUCT);
	//E-XD++ Library add lines.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Fo Add Newpage, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFoAddNewpage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Fo Remove Page, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFoRemovePage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View Toolbox, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnViewToolbox();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update View Toolbox, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateViewToolbox(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Move Previous, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnMovePrevious();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Move Previous, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateMovePrevious(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Move Next, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnMoveNext();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Move Next, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateMoveNext(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Mb Createpage Copy, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnMbCreatepageCopy();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Mb Createpage Copy, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateMbCreatepageCopy(CCmdUI* pCmdUI);

	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create New Page, Called as a part of window creation.

	afx_msg void OnCreateNewPage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create Save Page, Called as a part of window creation.

	afx_msg void OnCreateSavePage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Remove Page, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnRemovePage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Open Page, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnOpenPage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Toolbox Icon Style, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnToolboxIconStyle();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Toolbox Icon Style, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateToolboxIconStyle(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Toolbox Iconname Style, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnToolboxIconnameStyle();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Toolbox Iconname Style, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateToolboxIconnameStyle(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Toolbox Name Style, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnToolboxNameStyle();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Toolbox Name Style, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateToolboxNameStyle(CCmdUI* pCmdUI);

	
	//-----------------------------------------------------------------------
	// Summary:
	// On Shapes List, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnShapesList();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Shapes List, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateShapesList(CCmdUI* pCmdUI);
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDFRM_H__6EB9193F_17F6_43F7_A44A_C1058DB67CD4__INCLUDED_)
