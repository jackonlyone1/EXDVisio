#if !defined(AFX_NEWOPENPAGEDLG_H__889B204C_5D33_4837_AC7F_01A4612BDA55__INCLUDED_)
#define AFX_NEWOPENPAGEDLG_H__889B204C_5D33_4837_AC7F_01A4612BDA55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewOpenPageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewOpenPageDlg dialog
#include "GWExtBmpListBox.h"

 
//===========================================================================
// Summary:
//     The CNewOpenPageDlg class derived from CDialog
//      New Open Page Dialog
//===========================================================================

class CNewOpenPageDlg : public CDialog
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// New Open Page Dialog, Constructs a CNewOpenPageDlg object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---pParent, A pointer to the CWnd or NULL if the call failed.
	CNewOpenPageDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewOpenPageDlg)
	enum { IDD = IDD_DIALOG_PAGE_OPEN };
 
	// Item List, This member specify CTRSFileListBox object.  
	CTRSFileListBox	m_ItemList;
	//}}AFX_DATA

	
	//-----------------------------------------------------------------------
	// Summary:
	// Add Information To Tab, Adds an object to the specify list.
	// Parameters:
	//		&strFolder---&strFolder, Specifies A CString type value.
	void AddInfoToTab(const CString &strFolder);
 
	// The member supports arrays of CString objects.  
	CStringArray m_array;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Find In, Searches the list sequentially to find the first CObject pointer matching the specified CObject pointer. 
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		&strFile---&strFile, Specifies A CString type value.
	BOOL FindIn(const CString &strFile);

 
	// Select File, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString strSelectFile;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewOpenPageDlg)
	protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Data Exchange, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDX---D X, A pointer to the CDataExchange or NULL if the call failed.
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewOpenPageDlg)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Initial Dialog, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL OnInitDialog();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On O K, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void OnOK();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Load, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonLoad();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Delete, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonDelete();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Double click List1, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnDblclkList1();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Size, Called after the size of CWnd has changed.
	// Parameters:
	//		nType---nType, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		cx---Specifies A integer value.  
	//		cy---Specifies A integer value.
	afx_msg void OnSize(UINT nType, int cx, int cy);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Sizing, This member function is called by the framework to allow your application to handle a Windows message.
	// Parameters:
	//		nSide---nSide, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		lpRect---lpRect, Specifies a LPRECT lpRect object.
	afx_msg void OnSizing(UINT nSide, LPRECT lpRect);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Select change List1, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnSelchangeList1();
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
protected:
	
	//Has it intialize
 
	// Has Initial, This member sets TRUE if it is right.  
	BOOL m_bHasInit;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWOPENPAGEDLG_H__889B204C_5D33_4837_AC7F_01A4612BDA55__INCLUDED_)
