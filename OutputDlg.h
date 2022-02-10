#if !defined(AFX_OUTPUTDLG_H__EABA02C4_CE0B_11D6_A660_0050BAE30439__INCLUDED_)
#define AFX_OUTPUTDLG_H__EABA02C4_CE0B_11D6_A660_0050BAE30439__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutputDlg dialog

 
//===========================================================================
// Summary:
//     The COutputDlg class derived from CDialog
//      Output Dialog
//===========================================================================

class COutputDlg : public CDialog
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Output Dialog, Constructs a COutputDlg object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---pParent, A pointer to the CWnd or NULL if the call failed.
	COutputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COutputDlg)
	enum { IDD = IDD_DIALOG_HTML };
	//}}AFX_DATA
 
	// m_strPath, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_strPath;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputDlg)
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
	//{{AFX_MSG(COutputDlg)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button1, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButton1();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On O K, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void OnOK();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Initial Dialog, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTDLG_H__EABA02C4_CE0B_11D6_A660_0050BAE30439__INCLUDED_)
