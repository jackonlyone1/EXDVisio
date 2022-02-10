#if !defined(AFX_GWEXTBMPLISTBOX_H__6E0E4F63_1453_11D6_A516_525400EA266C__INCLUDED_)
#define AFX_GWEXTBMPLISTBOX_H__6E0E4F63_1453_11D6_A516_525400EA266C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GWExtBmpListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// GWExtBmpListBox window

///////////////////////////////////////////////////////////////////////////
// GWExtBmpListBox window

 
//===========================================================================
// Summary:
//     The GWExtBmpListBox class derived from CListBox
//      W Extend Bmp List Box
//===========================================================================

class GWExtBmpListBox : public CListBox
{
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N A M I C, None Description.
	//		Returns A  value.  
	// Parameters:
	//		GWExtBmpListBox---W Extend Bmp List Box, Specifies a GWExtBmpListBox object.
	DECLARE_DYNAMIC(GWExtBmpListBox)
		// Construction
public:
	
	
	//-----------------------------------------------------------------------
	// Summary:
	// W Extend Bmp List Box, Constructs a GWExtBmpListBox object.
	//		Returns A  value.
	//  GWExtBmpListBox constructor 
	GWExtBmpListBox();
	
	//  GWExtBmpListBox destructor 
	
	//-----------------------------------------------------------------------
	// Summary:
	// G W Extend Bmp List Box, Destructor of class GWExtBmpListBox
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~GWExtBmpListBox();
	
	// Operations
public:
	
	//  Adds a font to the list box. 
	
public:
	
	
	//  Draws font listbox items. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Draw Item, Draws current object to the specify device.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		lpDIS---D I S, Specifies a LPDRAWITEMSTRUCT lpDIS object.
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);
	
	
	//  Deletes an item from the font listbox. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Delete Item, Deletes the given object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		lpDIS---D I S, Specifies a LPDELETEITEMSTRUCT lpDIS object.
	virtual void DeleteItem(LPDELETEITEMSTRUCT lpDIS);
	
	
	//  Returns the measurement of a listbox item. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Measure Item, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		lpMeasureItemStruct---Measure Item Struct, Specifies a LPMEASUREITEMSTRUCT lpMeasureItemStruct object.
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	
	
	//  Draws a masked bitmap. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Draw Masked Bitmap, None Description.
	// This member function is a static function.
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pbmp---A pointer to the CBitmap or NULL if the call failed.  
	//		pbmpMask---pbmpMask, A pointer to the CBitmap or NULL if the call failed.  
	//		x---Specifies A integer value.  
	//		y---Specifies A integer value.  
	//		cx---Specifies A integer value.  
	//		cy---Specifies A integer value.
	static void _DrawMaskedBitmap(CDC* pDC, CBitmap* pbmp, CBitmap* pbmpMask,
		int x, int y, int cx, int cy);
	
	//  Generates a sprite mask given a bitmap. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Initial Mask From Bitmap, None Description.
	// This member function is a static function.
	// Parameters:
	//		pbmp---A pointer to the CBitmap or NULL if the call failed.  
	//		pbmpMask---pbmpMask, A pointer to the CBitmap or NULL if the call failed.
	static void _InitMaskFromBitmap(CBitmap* pbmp, CBitmap* pbmpMask);
	
	
protected:
	//{{AFX_MSG(GWExtBmpListBox)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create, Called as a part of window creation.
	//		Returns a int type value.  
	// Parameters:
	//		lpCreateStruct---Create Struct, Specifies a LPCREATESTRUCT lpCreateStruct object.
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Destroy, Called when CWnd is being destroyed.

	afx_msg void OnDestroy();
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
protected:
	
	//  TrueType bitmap (used for listbox item drawing). 
 
	// True Type, The CBitmap class encapsulates a Windows graphics device interface (GDI) bitmap and provides member functions to manipulate the bitmap.   
	CBitmap m_bmpTrueType;
	
	
	//  TrueType bitmap sprite mask. 
 
	// m_bmpMask, The CBitmap class encapsulates a Windows graphics device interface (GDI) bitmap and provides member functions to manipulate the bitmap.   
	CBitmap m_bmpMask;
};

/////////////////////////////////////////////////////////////////////////////

 
//===========================================================================
// Summary:
//     The CTRSFileListBox class derived from CListBox
//      T R S File List Box
//===========================================================================

class CTRSFileListBox : public CListBox
{
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N A M I C, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CTRSFileListBox---T R S File List Box, Specifies a CTRSFileListBox object.
	DECLARE_DYNAMIC(CTRSFileListBox)
		// Construction
public:
	
	
	//-----------------------------------------------------------------------
	// Summary:
	// T R S File List Box, Constructs a CTRSFileListBox object.
	//		Returns A  value.
	//  CTRSFileListBox constructor 
	CTRSFileListBox();
	
	//  CTRSFileListBox destructor 
	
	//-----------------------------------------------------------------------
	// Summary:
	// C T R S File List Box, Destructor of class CTRSFileListBox
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CTRSFileListBox();
	
	// Operations
public:
	
	//  Adds a font to the list box. 
	
public:
	
	
	//  Draws font listbox items. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Draw Item, Draws current object to the specify device.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		lpDIS---D I S, Specifies a LPDRAWITEMSTRUCT lpDIS object.
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);
	
	
	//  Deletes an item from the font listbox. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Delete Item, Deletes the given object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		lpDIS---D I S, Specifies a LPDELETEITEMSTRUCT lpDIS object.
	virtual void DeleteItem(LPDELETEITEMSTRUCT lpDIS);
	
	
	//  Returns the measurement of a listbox item. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Measure Item, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		lpMeasureItemStruct---Measure Item Struct, Specifies a LPMEASUREITEMSTRUCT lpMeasureItemStruct object.
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	
	
	//  Draws a masked bitmap. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Draw Masked Bitmap, None Description.
	// This member function is a static function.
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pbmp---A pointer to the CBitmap or NULL if the call failed.  
	//		pbmpMask---pbmpMask, A pointer to the CBitmap or NULL if the call failed.  
	//		x---Specifies A integer value.  
	//		y---Specifies A integer value.  
	//		cx---Specifies A integer value.  
	//		cy---Specifies A integer value.
	static void _DrawMaskedBitmap(CDC* pDC, CBitmap* pbmp, CBitmap* pbmpMask,
		int x, int y, int cx, int cy);
	
	//  Generates a sprite mask given a bitmap. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Initial Mask From Bitmap, None Description.
	// This member function is a static function.
	// Parameters:
	//		pbmp---A pointer to the CBitmap or NULL if the call failed.  
	//		pbmpMask---pbmpMask, A pointer to the CBitmap or NULL if the call failed.
	static void _InitMaskFromBitmap(CBitmap* pbmp, CBitmap* pbmpMask);
	
	
protected:
	//{{AFX_MSG(CTRSFileListBox)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create, Called as a part of window creation.
	//		Returns a int type value.  
	// Parameters:
	//		lpCreateStruct---Create Struct, Specifies a LPCREATESTRUCT lpCreateStruct object.
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Destroy, Called when CWnd is being destroyed.

	afx_msg void OnDestroy();
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
protected:
	
	//  TrueType bitmap (used for listbox item drawing). 
 
	// True Type, The CBitmap class encapsulates a Windows graphics device interface (GDI) bitmap and provides member functions to manipulate the bitmap.   
	CBitmap m_bmpTrueType;
	
	
	//  TrueType bitmap sprite mask. 
 
	// m_bmpMask, The CBitmap class encapsulates a Windows graphics device interface (GDI) bitmap and provides member functions to manipulate the bitmap.   
	CBitmap m_bmpMask;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GWEXTBMPLISTBOX_H__6E0E4F63_1453_11D6_A516_525400EA266C__INCLUDED_)
