// VisioApp.h : main header file for the VISIOAPP application
//

#if !defined(AFX_VISIOAPP_H__D1EBE189_96C4_467A_9B73_E1901F68098C__INCLUDED_)
#define AFX_VISIOAPP_H__D1EBE189_96C4_467A_9B73_E1901F68098C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVisioAppApp:
// See VisioApp.cpp for the implementation of this class
//

 
//===========================================================================
// Summary:
//     The CVisioAppApp class derived from CWinApp
//      Microsoft Visio style Application Application
//===========================================================================

class CVisioAppApp : public CWinApp
{
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Microsoft Visio style Application Application, Constructs a CVisioAppApp object.
	//		Returns A  value.
	CVisioAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisioAppApp)
	public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Initial Instance, Override to perform Windows instance initialization, such as creating your window objects.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL
 
	// Document Template, This member maintains a pointer to the object CMultiDocTemplate.  
	CMultiDocTemplate* m_pDocTemplate;
	//Image List
	
// Implementation
	//{{AFX_MSG(CVisioAppApp)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Application About, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
extern CVisioAppApp theApp;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISIOAPP_H__D1EBE189_96C4_467A_9B73_E1901F68098C__INCLUDED_)
