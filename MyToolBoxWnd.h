#if !defined(FO_MYTOOLBOXWND_H__7D3B24C0_F425_11D5_A4D1_525400EA266C__INCLUDED_)
#define AFC_MYTOOLBOXWND_H__7D3B24C0_F425_11D5_A4D1_525400EA266C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///////////////////////////////////////
// Create a new toolbox wnd.
///////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CMyRenameDlg dialog

 
//===========================================================================
// Summary:
//     The CMyRenameDlg class derived from CDialog
//      My Rename Dialog
//===========================================================================

class CMyRenameDlg : public CDialog
{
	
	// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// My Rename Dialog, Constructs a CMyRenameDlg object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---pParent, A pointer to the CWnd or NULL if the call failed.
	CMyRenameDlg(CWnd* pParent = NULL);   // standard constructor
	
	
	// Dialog Data
	//{{AFX_DATA(CMyRenameDlg)
	enum { IDD = IDD_FO_TAB_RENAME };
 
	// m_strCaption, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_strCaption;
	//}}AFX_DATA
	
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyRenameDlg)
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
	//{{AFX_MSG(CMyRenameDlg)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Initial Dialog, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL OnInitDialog();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Change Edit1, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

 
//===========================================================================
// Summary:
//     The CMyToolBoxPageWnd class derived from CFOToolBoxPageWnd
//      My Tool Box Page Window
//===========================================================================

class CMyToolBoxPageWnd : public CFOToolBoxPageWnd  
{
public:
	
	// constructor
	
	//-----------------------------------------------------------------------
	// Summary:
	// My Tool Box Page Window, Constructs a CMyToolBoxPageWnd object.
	//		Returns A  value.
	CMyToolBoxPageWnd();
	
	// Destructor.
	
	//-----------------------------------------------------------------------
	// Summary:
	// C My Tool Box Page Window, Destructor of class CMyToolBoxPageWnd
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CMyToolBoxPageWnd();
	
	// Show save file dialog and save resource file.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Save Res File, Saves the specify data to a file..
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL DoSaveResFile();

	// Create sub toolbox context menu.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create Child Context Menu, You construct a CMyToolBoxPageWnd object in two steps. First call the constructor, then call Create, which creates the object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CMenu ,or NULL if the call failed
	virtual CMenu * CreateSubContextMenu();

public:

	//{{AFX_MSG(CMyToolBoxPageWnd)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Add State, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAddState();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Add State, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateAddState(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Change All Property, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnChangeAllProp();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Change All Property, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateChangeAllProp(CCmdUI* pCmdUI);
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

 
//===========================================================================
// Summary:
//     The CMyToolBoxWnd class derived from CFOMultiToolBoxWnd
//      My Tool Box Window
//===========================================================================

class CMyToolBoxWnd : public CFOMultiToolBoxWnd  
{

public:

	// constructor
	
	//-----------------------------------------------------------------------
	// Summary:
	// My Tool Box Window, Constructs a CMyToolBoxWnd object.
	//		Returns A  value.
	CMyToolBoxWnd();

	// Destructor.
	
	//-----------------------------------------------------------------------
	// Summary:
	// C My Tool Box Window, Destructor of class CMyToolBoxWnd
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CMyToolBoxWnd();

public:
	// Override this to hook in a CFOToolBoxPageWnd derived object.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Create Tool Box Page Window, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,
	virtual void DoCreateToolBoxPageWnd();

	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create New Page, Called as a part of window creation.

	void OnCreateNewPage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create Save Page, Called as a part of window creation.

	void OnCreateSavePage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Remove Page, This member function is called by the framework to allow your application to handle a Windows message.

	void OnRemovePage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Open Page, This member function is called by the framework to allow your application to handle a Windows message.

	void OnOpenPage();

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

	
	//-----------------------------------------------------------------------
	// Summary:
	// Close Page, None Description.
	//		Returns TRUE on success; FALSE otherwise.
	BOOL ClosePage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Open Page, None Description.
	// Parameters:
	//		&strPathName---Path Name, Specifies A CString type value.  
	//		&strFileName---File Name, Specifies A CString type value.
	void OpenPage(const CString &strPathName, const CString &strFileName);

	
	//-----------------------------------------------------------------------
	// Summary:
	// Find Page, Searches the list sequentially to find the first CObject pointer matching the specified CObject pointer. 
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		&strTile---&strTile, Specifies A CString type value.
	BOOL FindPage(const CString &strTile);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get All Pages, Returns the specified value.
	// Parameters:
	//		&array---Specifies A CString type value.
	void GetAllPages(CStringArray &array);

	//{{AFX_MSG(CMyToolBoxPageWnd)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Fo Toolbox Closefile, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFoToolboxClosefile();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Fo Toolbox Loadfile, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFoToolboxLoadfile();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Fo Toolbox Newfile, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFoToolboxNewfile();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Fo Toolbox Savefile, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFoToolboxSavefile();
	//}}AFX_MSG
	
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFC_MYTOOLBOXWND_H__7D3B24C0_F425_11D5_A4D1_525400EA266C__INCLUDED_)
