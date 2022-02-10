// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__B449C391_7422_4813_BE5F_B2392CEF16EF__INCLUDED_)
#define AFX_MAINFRM_H__B449C391_7422_4813_BE5F_B2392CEF16EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define IDC_COMBO_ZOOMVALUE 1220
#define IDC_COMBO_FONTNAME 1221
#define IDC_COMBO_FONTSIZE 1222
#define IDC_COMBO_LAYER		1223

 
//===========================================================================
// Summary:
//     The CMainFrame class derived from CFOPMDIFrameWnd
//      Main Frame
//===========================================================================

class CMainFrame : public CFOPMDIFrameWnd
{
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N A M I C, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CMainFrame---Main Frame, Specifies a CMainFrame object.
	DECLARE_DYNAMIC(CMainFrame)
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Main Frame, Constructs a CMainFrame object.
	//		Returns A  value.
	CMainFrame();

// Attributes
public:
	
 
	// Undo String, The member supports arrays of CString objects.  
	CStringArray m_UndoString;
 
	// Redo String, The member supports arrays of CString objects.  
	CStringArray m_RedoString;


public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Enum Font Process Function, None Description.
	// This member function is a static function.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpLogFont---Logical Font, Specifies a LPLOGFONT lpLogFont object.  
	//		lpTextMetric---Text Metric, Specifies a LPTEXTMETRIC lpTextMetric object.  
	//		nFontType---Font Type, Specifies a short nFontType object.  
	//		lpData---lpData, Specifies a LPHANDLE lpData object.
	static BOOL CALLBACK EnumFontProc(LPLOGFONT lpLogFont, LPTEXTMETRIC lpTextMetric, short nFontType, LPHANDLE lpData);
	
	//Init the combobox fonts.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Initial Fonts, Call InitFonts after creating a new object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pBox---*pBox, A pointer to the CComboBox  or NULL if the call failed.
	virtual void InitFonts(CComboBox *pBox);

	// Init the font sizes.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Initial Font Sizes, Call InitFontSizes after creating a new object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pBox---*pBox, A pointer to the CComboBox  or NULL if the call failed.
	virtual void InitFontSizes(CComboBox *pBox);

// Operations
public:
	
 
	// Font Name Box, This member maintains a pointer to the object CComboBox.  
	CComboBox *pFontNameBox;
 
	// Font Size Box, This member maintains a pointer to the object CComboBox.  
	CComboBox *pFontSizeBox;
 
	// Scale Box, This member maintains a pointer to the object CComboBox.  
	CComboBox *pScaleBox;
 
	// Layer Box, This member maintains a pointer to the object CComboBox.  
	CComboBox *pLayerBox;

 
	// Save Font Color, This member sets A 32-bit value used as a color value.  
	COLORREF m_crSaveFontColor;
 
	// Save Line Color, This member sets A 32-bit value used as a color value.  
	COLORREF m_crSaveLineColor;
 
	// Save Fill Color, This member sets A 32-bit value used as a color value.  
	COLORREF m_crSaveFillColor;

 
	// Save Line Width, This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int		 m_nSaveLineWidth;
 
	// Save Line Type, This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int		 m_nSaveLineType;

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Before Create Window, Called before the creation of the Windows window attached to this CWnd object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		cs---Specifies a CREATESTRUCT& cs object.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Main Frame, Destructor of class CMainFrame
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CMainFrame();
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

public:  // control bar embedded members
 
	// Status Bar, This member specify E-XD++ CFOPStatusBar object.  
	CFOPStatusBar     m_wndStatusBar;
 
	// Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar    m_wndToolBar;
 
	// Font Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar    m_wndFontBar;
 
	// Draw Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar    m_wndDrawToolBar;
 
	// Format Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar    m_wndFormatToolBar;
 
	// Align Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar    m_wndAlignToolBar;
 
	// Link Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar    m_wndLinkToolBar;
 
	// Layout Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar		m_wndLayoutToolBar;
 
	// Tool Box Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar		m_wndToolBoxBar;
 
	// Pan Bar, This member specify E-XD++ CFOPNewPanBar object.  
	CFOPNewPanBar  m_wndPanBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View Drawbar, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnViewDrawbar();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update View Drawbar, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateViewDrawbar(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View Formatbar, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnViewFormatbar();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update View Formatbar, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateViewFormatbar(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create, Called as a part of window creation.
	//		Returns a int type value.  
	// Parameters:
	//		LPCREATESTRUCT---P C R E A T E S T R U C T, Specifies a LPCREATESTRUCT LPCREATESTRUCT object.
	afx_msg int OnCreate(LPCREATESTRUCT LPCREATESTRUCT);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Mail Me, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnMailMe();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View Fullscreen, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnViewFullscreen();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update View Fullscreen, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateViewFullscreen(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Layers, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateLayers(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Look Standard, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnLookStandard();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Look Standard, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateLookStandard(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Look Xp, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnLookXp();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Look Xp, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateLookXp(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Drop Files, This member function is called by the framework to allow your application to handle a Windows message.
	// Parameters:
	//		hDropInfo---Drop Information, Specifies a HDROP hDropInfo object.
	afx_msg void OnDropFiles(HDROP hDropInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Draw Bar, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateDrawBar(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw Bar, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnDrawBar();
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Undo Redo O K, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit signed integer.  
	// Parameters:
	//		wParam---wParam, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		lParam---lParam, Specifies A 32-bit signed integer.
	afx_msg LONG OnUndoRedoOK(UINT wParam, LONG lParam);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Tool Bar Initial, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit signed integer.  
	// Parameters:
	//		wParam---wParam, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		lParam---lParam, Specifies A 32-bit signed integer.
	afx_msg LONG OnToolBarInit(UINT wParam , LONG lParam);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View Valid Message, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		WPARAM---P A R A M, Provides additional information used in processing the message. The parameter value depends on the message.  
	//		LPARAM---P A R A M, Specifies A lparam value.
	afx_msg LRESULT OnViewValidMsg(WPARAM, LPARAM);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View In Valid Message, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		WPARAM---P A R A M, Provides additional information used in processing the message. The parameter value depends on the message.  
	//		LPARAM---P A R A M, Specifies A lparam value.
	afx_msg LRESULT OnViewInValidMsg(WPARAM, LPARAM);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Shape Changed Message, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		WPARAM---P A R A M, Provides additional information used in processing the message. The parameter value depends on the message.  
	//		LPARAM---P A R A M, Specifies A lparam value.
	afx_msg LRESULT OnShapeChangedMsg(WPARAM,LPARAM);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Canvas Changed Message, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		WPARAM---P A R A M, Provides additional information used in processing the message. The parameter value depends on the message.  
	//		LPARAM---P A R A M, Specifies A lparam value.
	afx_msg LRESULT OnCanvasChangedMsg(WPARAM,LPARAM);
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__B449C391_7422_4813_BE5F_B2392CEF16EF__INCLUDED_)
