// MyCustomProperties.h: interface for the CMyCustomProperties class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCUSTOMPROPERTIES_H__7E087801_BAB9_11D5_A479_525400EA266C__INCLUDED_)
#define AFX_MYCUSTOMPROPERTIES_H__7E087801_BAB9_11D5_A479_525400EA266C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//------------------------------------------------------
// Properties.
//------------------------------------------------------

#define FO_MY_PROP_ID  FO_CUSTOM_PROP_ID +1

#define M_ID_PRODUCTNAME		5001
#define M_ID_ITEM				5002
#define M_ID_DESCRIPTION		5003
#define M_ID_UNITPRICE			5004

 
//===========================================================================
// Summary:
//     The CMyCustomProperties class derived from CFOBaseProperties
//      My Custom Properties
//===========================================================================

class CMyCustomProperties : public CFOBaseProperties
{
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ S E R I A L, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CMyCustomProperties---My Custom Properties, Specifies a CMyCustomProperties object.
	DECLARE_SERIAL(CMyCustomProperties)

// Construction/Destruction
public:

	// Constructor with ID.
	
	//-----------------------------------------------------------------------
	// Summary:
	// My Custom Properties, Constructs a CMyCustomProperties object.
	//		Returns A  value.  
	// Parameters:
	//		nCurID---Cur I D, Specifies A integer value.
	CMyCustomProperties(int nCurID = FO_MY_PROP_ID);
	
	// Copy constructor. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// My Custom Properties, Constructs a CMyCustomProperties object.
	//		Returns A  value.  
	// Parameters:
	//		propShape---propShape, Specifies a const CMyCustomProperties& propShape object.
	CMyCustomProperties(const CMyCustomProperties& propShape);
	
	// Destructor. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// C My Custom Properties, Destructor of class CMyCustomProperties
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CMyCustomProperties();

	
	//-----------------------------------------------------------------------
	// Summary:
	// Copy, Create a duplicate copy of this object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFOBaseProperties,or NULL if the call failed
	// Create a copy of properties.
	virtual CFOBaseProperties* Copy();

	// Is equal.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Is Equal, Determines if the given value is correct or exist.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		prop---A pointer to the CFOBaseProperties or NULL if the call failed.
	virtual BOOL IsEqual(CFOBaseProperties* prop);

	// Obtain the backup of this properties values.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Back Up, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pProp---pProp, A pointer to the CFOBaseProperties or NULL if the call failed.
	virtual void DoBackUp(CFOBaseProperties* pProp);

public:

	// Put value.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Put Value, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		&nPropId---Property Id, Specifies A integer value.  
	//		&Value---&Value, Specifies a const FO_VALUE &Value object.
	virtual BOOL PutValue(const int &nPropId,const FO_VALUE &Value);

	// Get value.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Value, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		&Value---&Value, Specifies a FO_VALUE &Value object.  
	//		&nPropId---Property Id, Specifies A integer value.
	virtual BOOL GetValue(FO_VALUE &Value,const int &nPropId);

public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Product Name, Sets a specify value to current class CMyCustomProperties
	// Parameters:
	//		&strName---&strName, Specifies A CString type value.
	void	SetProductName(const CString &strName)	{ m_strProduct = strName; }
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Product Name, Returns the specified value.
	//		Returns a CString type value.
	CString	GetProductName() const					{ return m_strProduct; }

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Item, Sets a specify value to current class CMyCustomProperties
	// Parameters:
	//		&strItem---&strItem, Specifies A CString type value.
	void	SetItem(const CString &strItem)			{ m_strItem = strItem; }
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Item, Returns the specified value.
	//		Returns a CString type value.
	CString	GetItem() const					{ return m_strItem; }

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Description, Sets a specify value to current class CMyCustomProperties
	// Parameters:
	//		&strText---&strText, Specifies A CString type value.
	void	SetDescription(const CString &strText)	{ m_strDescription = strText; }
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Description, Returns the specified value.
	//		Returns a CString type value.
	CString	GetDescription() const					{ return m_strDescription; }

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Unit Price, Sets a specify value to current class CMyCustomProperties
	// Parameters:
	//		&nPrice---&nPrice, Specifies A float value.
	void	SetUnitPrice(const float &nPrice)		{ m_fUnitPrice = nPrice; }
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Unit Price, Returns the specified value.
	//		Returns a float value.
	float	GetUnitPrice() const					{ return m_fUnitPrice; }

// Attributes
protected:
	
	// FODO:Add your properties items below.
	
	// Product name.
 
	// m_strProduct, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_strProduct;

	// Item
 
	// m_strItem, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_strItem;

	// Custom properties.
 
	// m_strDescription, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_strDescription;

	// Unit Price.
 
	// Unit Price, This member specify The float keyword designates a 32-bit floating-point number.  
	float	m_fUnitPrice;

public:

	
	// Sets this set of font properties equal to another. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	//		Returns A CMyCustomProperties& value.  
	// Parameters:
	//		propEdit---propEdit, Specifies a const CMyCustomProperties& propEdit object.
	CMyCustomProperties& operator=(const CMyCustomProperties& propEdit);

	// Determines if another set of fill properties is equal to this one. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		propEdit---propEdit, Specifies a const CMyCustomProperties propEdit object.
	BOOL operator==(const CMyCustomProperties &propEdit) const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Serialize, Reads or writes this object from or to an archive.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		ar---Specifies a CArchive& ar object.
	virtual void Serialize(CArchive& ar);

// Implementation
public:

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

};
inline CFOBaseProperties* CMyCustomProperties::Copy()
{
	return new CMyCustomProperties(*this);
}

#endif // !defined(AFX_MYCUSTOMPROPERTIES_H__7E087801_BAB9_11D5_A479_525400EA266C__INCLUDED_)
