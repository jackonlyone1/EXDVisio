#if !defined(AFX_LINEPROPDLG_H__1D050F58_6EB3_11DF_A473_525400EA266C__INCLUDED_)
#define AFX_LINEPROPDLG_H__1D050F58_6EB3_11DF_A473_525400EA266C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinePropDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLinePropDlg dialog

 
//===========================================================================
// Summary:
//     The CLinePropDlg class derived from CDialog
//      Line Property Dialog
//===========================================================================

class CLinePropDlg : public CDialog
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Line Property Dialog, Constructs a CLinePropDlg object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---pParent, A pointer to the CWnd or NULL if the call failed.
	CLinePropDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLinePropDlg)
	enum { IDD = IDD_DIALOG_LINE };
 
	// m_spinCtrl, This member specify CSpinButtonCtrl object.  
	CSpinButtonCtrl	m_spinCtrl;
 
	// m_strDescription, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_strDescription;
 
	// Line Width, This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int		m_nLineWidth;
 
	// m_strItem, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_strItem;
 
	// Product Name, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_strProductName;
 
	// Unit Price, This member specify The float keyword designates a 32-bit floating-point number.  
	float	m_fUnitPrice;
	//}}AFX_DATA

	// Save product name.
 
	// Old Product Name, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_strOldProductName;

	// Save item.
 
	// Old Item, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_strOldItem;

	// Save Unit price.
 
	// Old Unit Price, This member specify The float keyword designates a 32-bit floating-point number.  
	float m_fOldUnitPrice;

	// Save description.
 
	// Old Description, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_strOldDescription;

	// Save old pen width.
 
	// Old Line Width, This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int m_nOldLineWidth;

	// Modify flag.
 
	// m_bModify, This member sets TRUE if it is right.  
	BOOL m_bModify;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinePropDlg)
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
	//{{AFX_MSG(CLinePropDlg)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Initial Dialog, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL OnInitDialog();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Nc Activate, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		bActive---bActive, Specifies A Boolean value.
	afx_msg BOOL OnNcActivate(BOOL bActive);
	
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

#endif // !defined(AFX_LINEPROPDLG_H__1D050F58_6EB3_11DF_A473_525400EA266C__INCLUDED_)
