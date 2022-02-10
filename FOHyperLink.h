// FOHyperLink.h: interface for the CFOHyperLink class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FOHYPERLINK_H__44FC73BC_F596_11DD_A43A_525400EA266C__INCLUDED_)
#define AFX_FOHYPERLINK_H__44FC73BC_F596_11DD_A43A_525400EA266C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

 
//===========================================================================
// Summary:
//     The CFOHyperLink class derived from CStatic
//      F O Hyper Link
//===========================================================================

class CFOHyperLink : public CStatic
{
// Construction/destruction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// F O Hyper Link, Constructs a CFOHyperLink object.
	//		Returns A  value.
    CFOHyperLink();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C F O Hyper Link, Destructor of class CFOHyperLink
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
    virtual ~CFOHyperLink();

// Attributes
public:

// Operations
public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set U R L, Sets a specify value to current class CFOHyperLink
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		strURL---U R L, Specifies A CString type value.
    virtual void SetURL(CString strURL);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get U R L, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.
    virtual CString GetURL() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Colors, Sets a specify value to current class CFOHyperLink
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		crLinkColor---Link Color, Specifies A 32-bit value used as a color value.  
	//		crVisitedColor---Visited Color, Specifies A 32-bit value used as a color value.  
	//		crHoverColor---Hover Color, Specifies A 32-bit value used as a color value.
    virtual void SetColors(COLORREF crLinkColor, COLORREF crVisitedColor, 
                    COLORREF crHoverColor = -1);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Link Color, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A 32-bit value used as a color value.
    virtual COLORREF GetLinkColor() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Visited Color, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A 32-bit value used as a color value.
    virtual COLORREF GetVisitedColor() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Hover Color, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A 32-bit value used as a color value.
    virtual COLORREF GetHoverColor() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Visited, Sets a specify value to current class CFOHyperLink
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		bVisited---bVisited, Specifies A Boolean value.
    virtual void SetVisited(BOOL bVisited = TRUE);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Visited, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
    virtual BOOL GetVisited() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Link Cursor, Sets a specify value to current class CFOHyperLink
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		hCursor---hCursor, Specifies a HCURSOR hCursor object.
    virtual void SetLinkCursor(HCURSOR hCursor);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Link Cursor, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A HCURSOR value.
    virtual HCURSOR GetLinkCursor() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Underline, Sets a specify value to current class CFOHyperLink
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		bUnderline---bUnderline, Specifies A Boolean value.
    virtual void SetUnderline(BOOL bUnderline = TRUE);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Underline, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
    virtual BOOL GetUnderline() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Auto Size, Sets a specify value to current class CFOHyperLink
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		bAutoSize---Auto Size, Specifies A Boolean value.
    virtual void SetAutoSize(BOOL bAutoSize = TRUE);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Auto Size, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
    virtual BOOL GetAutoSize() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Goto U R L, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A HINSTANCE value.  
	// Parameters:
	//		url---Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.  
	//		showcmd---Specifies A integer value.
    virtual HINSTANCE GotoURL(LPCTSTR url, int showcmd);

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CFOHyperLink)
    public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Before Translate Message, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pMsg---pMsg, A pointer to the MSG or NULL if the call failed.
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Before Subclass Window, None Description.
	// This member function is also a virtual function, you can Override it if you need,
    virtual void PreSubclassWindow();
    //}}AFX_VIRTUAL

// Implementation
protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Report Error, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		nError---nError, Specifies A integer value.
    virtual void ReportError(int nError);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Registry Key, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A 32-bit signed integer.  
	// Parameters:
	//		key---Specifies a HKEY key object.  
	//		subkey---Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.  
	//		retdata---Specifies a LPTSTR retdata object.
    virtual LONG GetRegKey(HKEY key, LPCTSTR subkey, LPTSTR retdata);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Position Window, None Description.
	// This member function is also a virtual function, you can Override it if you need,
    virtual void PositionWindow();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Default Cursor, Sets a specify value to current class CFOHyperLink
	// This member function is also a virtual function, you can Override it if you need,
    virtual void SetDefaultCursor();

// Protected attributes
protected:
    COLORREF m_crLinkColor, m_crVisitedColor;  
 
	// Hover Color, This member sets A 32-bit value used as a color value.  
    COLORREF m_crHoverColor; 
 
	// Over , This member sets TRUE if it is right.  
    BOOL     m_bOverControl;  
 
	// m_bVisited, This member sets TRUE if it is right.  
    BOOL     m_bVisited;   
 
	// m_bUnderline, This member sets TRUE if it is right.  
    BOOL     m_bUnderline;     
 
	// Adjust To Fit, This member sets TRUE if it is right.  
    BOOL     m_bAdjustToFit;  
 
	// U R L, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
    CString  m_strURL; 
 
	// m_Font, The CFont class encapsulates a Windows graphics device interface (GDI) font and provides member functions for manipulating the font.  
    CFont    m_Font;   
 
	// Link Cursor, This member specify HCURSOR object.  
    HCURSOR  m_hLinkCursor;   
 
	// Tool Tip, This member specify CToolTipCtrl object.  
    CToolTipCtrl m_ToolTip; 

    // Generated message map functions
protected:
    //{{AFX_MSG(CFOHyperLink)
	
	//-----------------------------------------------------------------------
	// Summary:
	// Ctl Color, None Description.
	//		Returns A afx_msg HBRUSH value.  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		nCtlColor---Ctl Color, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Set Cursor, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pWnd---pWnd, A pointer to the CWnd or NULL if the call failed.  
	//		nHitTest---Hit Test, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		message---Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
    afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Mouse Move, Called when the mouse cursor moves.
	// Parameters:
	//		nFlags---nFlags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		point---Specifies A CPoint type value.
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    //}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Clicked, This member function is called by the framework to allow your application to handle a Windows message.

    afx_msg void OnClicked();
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
    DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_FOHYPERLINK_H__44FC73BC_F596_11DD_A43A_525400EA266C__INCLUDED_)
