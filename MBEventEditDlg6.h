#if !defined(AFX_MBEVENTEDITDLG6_H__0B43CEA8_1844_11D6_A51B_525400EA266C__INCLUDED_)
#define AFX_MBEVENTEDITDLG6_H__0B43CEA8_1844_11D6_A51B_525400EA266C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MBEventEditDlg6.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMBEventEditDlg6 dialog

 
//===========================================================================
// Summary:
//     The CMBEventEditDlg6 class derived from CDialog
//      M B Event Edit Dlg6
//===========================================================================

class CMBEventEditDlg6 : public CDialog
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// M B Event Edit Dlg6, Constructs a CMBEventEditDlg6 object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---pParent, A pointer to the CWnd or NULL if the call failed.
	CMBEventEditDlg6(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMBEventEditDlg6)
	enum { IDD = IDD_MB_EVENT_EDITDLG6 };
 
	// Item List, This member specify CListBox object.  
	CListBox m_ItemList;
	//}}AFX_DATA
 
	// Page Name, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString strPageName;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Initial List Box, Call InitListBox after creating a new object.

	void InitListBox();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMBEventEditDlg6)
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
	//{{AFX_MSG(CMBEventEditDlg6)
	
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
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MBEVENTEDITDLG6_H__0B43CEA8_1844_11D6_A51B_525400EA266C__INCLUDED_)
