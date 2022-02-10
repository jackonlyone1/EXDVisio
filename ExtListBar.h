#if !defined(AFX_EXTLISTBAR_H__3594B972_7B57_49BD_96C9_34728E9B24B8__INCLUDED_)
#define AFX_EXTLISTBAR_H__3594B972_7B57_49BD_96C9_34728E9B24B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExtListBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExtListBar window

/////////////////////////////////////////////////////////////////////////////
// CExtListBar
 
//===========================================================================
// Summary:
//     The CExtListBar class derived from CFOPControlBar
//      Extend List Bar
//===========================================================================

class CExtListBar : public CFOPControlBar
{

	// Construction
public:
	// constructor
	
	//-----------------------------------------------------------------------
	// Summary:
	// Extend List Bar, Constructs a CExtListBar object.
	//		Returns A  value.
	CExtListBar();
 
	// Tree , This member specify CTreeCtrl object.  
	CTreeCtrl m_TreeCtrl;
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtListBar)
	//}}AFX_VIRTUAL

	// Tree handle.
 
	// hRoot, This member specify HTREEITEM object.  
	HTREEITEM hRoot;

	// Init shapes.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Initial Shapes, Call InitShapes after creating a new object.
	// Parameters:
	//		*pDataModel---Data Model, A pointer to the CFODataModel  or NULL if the call failed.
	void InitShapes(CFODataModel *pDataModel);

	
	//-----------------------------------------------------------------------
	// Summary:
	// Insert With Component, Inserts a child object at the given index..
	// Parameters:
	//		hParent---hParent, Specifies a HTREEITEM hParent object.  
	//		*pComp---*pComp, A pointer to the CFOCompositeShape  or NULL if the call failed.
	void InsertWithComp(HTREEITEM hParent, CFOCompositeShape *pComp);
 
	// This member is a collection of same-sized images.  
	CImageList  m_image;
// Implementation
public:

	// destructor
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Extend List Bar, Destructor of class CExtListBar
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CExtListBar();

	// Generated message map functions
protected:

	//{{AFX_MSG(CExtListBar)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create, Called as a part of window creation.
	//		Returns a int type value.  
	// Parameters:
	//		lpCreateStruct---Create Struct, Specifies a LPCREATESTRUCT lpCreateStruct object.
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	
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
	// On Erase Background, Called when the window background needs erasing.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
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

#endif // !defined(AFX_EXTLISTBAR_H__3594B972_7B57_49BD_96C9_34728E9B24B8__INCLUDED_)
