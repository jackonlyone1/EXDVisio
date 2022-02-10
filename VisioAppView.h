// VisioAppView.h : interface of the CVisioAppView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VISIOAPPVIEW_H__EA436CD6_578A_44A9_BEE6_FFE7189E3A4C__INCLUDED_)
#define AFX_VISIOAPPVIEW_H__EA436CD6_578A_44A9_BEE6_FFE7189E3A4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyCustomProperties.h"

 
//===========================================================================
// Summary:
//     The CVisioAppView class derived from CFOTabPageView
//      Microsoft Visio style Application View
//===========================================================================

class CVisioAppView : public CFOTabPageView
{
protected: // create from serialization only
	
	//-----------------------------------------------------------------------
	// Summary:
	// Microsoft Visio style Application View, Constructs a CVisioAppView object.
	//		Returns A  value.
	CVisioAppView();
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N C R E A T E, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CVisioAppView---Microsoft Visio style Application View, Specifies a CVisioAppView object.
	DECLARE_DYNCREATE(CVisioAppView)

// Attributes
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Document, Returns the specified value.
	//		Returns a pointer to the object CVisioAppDoc,or NULL if the call failed
	CVisioAppDoc* GetDocument();

public:

	// Do update ruler.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Update Ruler, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,
	virtual void DoUpdateRuler();

	// Update cells.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Update Cells, Call this member function to update the object.

	void UpdateCells();

	// Get port count.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Custom Count, Returns the specified value.
	//		Returns a int type value.
	int GetCustomCount();

	// Create context menu.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create Context Menu, You construct a CVisioAppView object in two steps. First call the constructor, then call Create, which creates the object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CMenu,or NULL if the call failed
	virtual CMenu* CreateContextMenu();

	// Add shape to selection list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Add To Selection, Adds an object to the specify list.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pShape---*pShape, A pointer to the CFODrawShape  or NULL if the call failed.
	virtual void AddToSelection(
		// Pointer of shape.
		CFODrawShape *pShape
		);

	// Remove shape to selection list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove From Selection, Call this function to remove a specify value from the specify object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pShape---*pShape, A pointer to the CFODrawShape  or NULL if the call failed.
	virtual void RemoveFromSelection(
		// Pointer of shape.
		CFODrawShape *pShape
		);

	// Remove all shapes from the selection list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove All From Selection, Call this function to remove a specify value from the specify object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void RemoveAllFromSelection();

	// Change the list of the shapes to a new layer.
	// pList -- list of the shapes to change.
	// strName -- name of the layer.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Change Shapes Layer, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pList---*pList, A pointer to the CFODrawShapeList  or NULL if the call failed.  
	//		&strName---&strName, Specifies A CString type value.
	virtual void ChangeShapesLayer(CFODrawShapeList *pList,const CString &strName);

	// Init layers combobox.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Initial Layers Combo Box, Call InitLayersComboBox after creating a new object.

	void InitLayersComboBox();

	// Layers changed.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Layers Changed, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		lHint---lHint, Specifies A lparam value.
	virtual void DoLayersChanged(
		// Hint value.
		LPARAM lHint);

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Layer, Returns the specified value.
	//		Returns a UINT type value.
	UINT GetLayer();

// Operations
public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Output Html, None Description.
	// Parameters:
	//		strRootPath---Root Path, Specifies A CString type value.  
	//		szImage---szImage, Specifies A CSize type value.
	void OutputHtml(CString strRootPath,CSize szImage);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Next Font Size, Returns the specified value.
	//		Returns a int type value.  
	// Parameters:
	//		nFont---nFont, Specifies A integer value.
	int GetNextFontSize(int nFont);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Previous Font Size, Returns the specified value.
	//		Returns a int type value.  
	// Parameters:
	//		nFont---nFont, Specifies A integer value.
	int GetPrevFontSize(int nFont);

	// When zoom sacle changed to call this function.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Zoom Scale Changing, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,
	virtual void DoZoomScaleChanging();

	// Asign custom properties to a specify shape with name.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Asign Custom Properties, None Description.
	// Parameters:
	//		strShapeName---Shape Name, Specifies A CString type value.  
	//		&prop---Specifies a const CMyCustomProperties &prop object.
	void AsignCustomProperties(CString strShapeName,const CMyCustomProperties &prop);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisioAppView)
	public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Before Create Window, Called before the creation of the Windows window attached to this CWnd object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		cs---Specifies a CREATESTRUCT& cs object.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Drop, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pDataObject---Data Object, A pointer to the COleDataObject or NULL if the call failed.  
	//		dropEffect---dropEffect, Specifies a DROPEFFECT dropEffect object.  
	//		point---Specifies A CPoint type value.
	virtual BOOL OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point);
	protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Initial Update, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void OnInitialUpdate(); // called first time after construct
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Prepare Printing, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pInfo---pInfo, A pointer to the CPrintInfo or NULL if the call failed.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Begin Printing, Called when a print job begins; override to allocate graphics device interface (GDI) resources.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---pInfo, A pointer to the CPrintInfo or NULL if the call failed.
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On End Printing, Called when a print job ends; override to deallocate GDI resources.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---pInfo, A pointer to the CPrintInfo or NULL if the call failed.
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Print, Called to print or preview a page of the document.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---pInfo, A pointer to the CPrintInfo or NULL if the call failed.
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update, Called to notify a view that its document has been modified.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pSender---pSender, A pointer to the CView or NULL if the call failed.  
	//		lHint---lHint, Specifies A lparam value.  
	//		pHint---pHint, A pointer to the CObject or NULL if the call failed.
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Activate View, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		bActivate---bActivate, Specifies A Boolean value.  
	//		pActivateView---Activate View, A pointer to the CView or NULL if the call failed.  
	//		pDeactiveView---Deactive View, A pointer to the CView or NULL if the call failed.
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Microsoft Visio style Application View, Destructor of class CVisioAppView
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CVisioAppView();
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

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVisioAppView)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Face Change, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontFaceChange();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Size Change, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontSizeChange();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Scale Change, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontScaleChange();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Layer Change, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnLayerChange();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Facename, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontFacename(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Typesize, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontTypesize(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Style Bold, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontStyleBold();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Style Bold, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontStyleBold(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Style Italic, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontStyleItalic();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Style Italic, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontStyleItalic(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Style Underline, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontStyleUnderline();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Style Underline, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontStyleUnderline(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Big, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontBig();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Big, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontBig(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Small, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontSmall();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Small, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontSmall(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On L Button Down, Called when the user presses the left mouse button.
	// Parameters:
	//		nFlags---nFlags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		point---Specifies A CPoint type value.
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On L Button Up, Called when the user releases the left mouse button.
	// Parameters:
	//		nFlags---nFlags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		point---Specifies A CPoint type value.
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On R Button Down, Called when the user presses the right mouse button.
	// Parameters:
	//		nFlags---nFlags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		point---Specifies A CPoint type value.
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Left Align, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontLeftAlign();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Left Align, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontLeftAlign(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Right Align, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontRightAlign();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Right Align, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontRightAlign(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Center, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontCenter();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Center, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontCenter(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On File Print Preview, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFilePrintPreview();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Color, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontColor(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Line Color, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateLineColor(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Line Width, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateLineWidth(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Line Type, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateLineType(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Fill Color, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFillColor(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On New Shape, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnNewShape();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update New Shape, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateNewShape(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Fo Custom Properties, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFoCustomProperties();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Fo Custom Properties, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFoCustomProperties(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Save Data, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnSaveData();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Save Data, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateSaveData(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Drop Menu, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnDropMenu();
	
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
	// On Font Top Align, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontTopAlign();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Top Align, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontTopAlign(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Bottom Align, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontBottomAlign();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Bottom Align, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontBottomAlign(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Vcenter Align, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontVcenterAlign();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Font Vcenter Align, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateFontVcenterAlign(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Insert Objects, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnInsertObjects();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Insert Objects, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateInsertObjects(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Brush Style, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnBrushStyle();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Brush Style, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateBrushStyle(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Drag Drop, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnDragDrop();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Drag Drop, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateDragDrop(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Information Search, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnInfoSearch();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Information Search, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateInfoSearch(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Spellcheck, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnSpellcheck();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Spellcheck, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateSpellcheck(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Save As Html, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnSaveAsHtml();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update Save As Html, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateSaveAsHtml(CCmdUI* pCmdUI);
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
	// On None Text Color, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnNoneTextColor();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Auto Text Color, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAutoTextColor();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Text Color Change, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnTextColorChange();

	
	//-----------------------------------------------------------------------
	// Summary:
	// On None Line Color, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnNoneLineColor();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Auto Line Color, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAutoLineColor();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Line Color Change, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnLineColorChange();

	
	//-----------------------------------------------------------------------
	// Summary:
	// On None Fill Color, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnNoneFillColor();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Auto Fill Color, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAutoFillColor();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Fill Color Change, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFillColorChange();

	
	//-----------------------------------------------------------------------
	// Summary:
	// On None Line Width, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnNoneLineWidth();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Line Width Change, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnLineWidthChange();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Line Type Change, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnLineTypeChange();
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VisioAppView.cpp
inline CVisioAppDoc* CVisioAppView::GetDocument()
   { return (CVisioAppDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISIOAPPVIEW_H__EA436CD6_578A_44A9_BEE6_FFE7189E3A4C__INCLUDED_)
