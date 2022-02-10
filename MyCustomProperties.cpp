// MyCustomProperties.cpp: implementation of the CMyCustomProperties class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VisioApp.h"
#include "MyCustomProperties.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


/////////////////////////////////////////////////////////////////////////////
// CMyCustomProperties construction/destruction

IMPLEMENT_SERIAL(CMyCustomProperties, CFOBaseProperties,1)

//mfunc | CMyCustomProperties | CMyCustomProperties | Constructor.

CMyCustomProperties::CMyCustomProperties(int nCurID) : CFOBaseProperties(nCurID)
{
	m_strDescription = "";
	m_strProduct = "";
	m_strItem = "";
	m_fUnitPrice = 0;
}

CMyCustomProperties::CMyCustomProperties(const CMyCustomProperties& propShape) 
	: CFOBaseProperties(propShape.GetPropId())
{
	m_strDescription	= propShape.GetDescription();
	m_strProduct		= propShape.GetProductName();
	m_strItem			= propShape.GetItem();
	m_fUnitPrice		= propShape.GetUnitPrice();
}

//mfunc Destructor.
CMyCustomProperties::~CMyCustomProperties()
{
}

//The property to copy.
CMyCustomProperties& CMyCustomProperties::operator=(const CMyCustomProperties& propShape)
{
	m_strDescription	= propShape.GetDescription();
	m_strProduct		= propShape.GetProductName();
	m_strItem			= propShape.GetItem();
	m_fUnitPrice		= propShape.GetUnitPrice();
	return *this;
}

BOOL CMyCustomProperties::IsEqual(CFOBaseProperties* prop)
{
	if (GetPropId() == prop->GetPropId())
	{
		CMyCustomProperties* pProp = (CMyCustomProperties*)prop;

		if (pProp)
			return (*this == *pProp);
	}

	return FALSE;
}

BOOL CMyCustomProperties::operator==(const CMyCustomProperties &propEdit) const
{
	if(GetDescription() == propEdit.GetDescription() &&
		GetProductName() == propEdit.GetProductName() &&
		GetItem() == propEdit.GetItem() &&
		GetUnitPrice() == propEdit.GetUnitPrice() )
	{
		return TRUE;
	}
	
	return FALSE;
}

////////////////////////////////////////////////////////////////////////////
// CMyCustomProperties serialization
void CMyCustomProperties::Serialize(CArchive& ar)
{
	CFOBaseProperties::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_strDescription;
		ar << m_strProduct;
		ar << m_strItem;
		ar << (float)m_fUnitPrice;
	}
	else
	{
		ar >> m_strDescription;
		ar >> m_strProduct;
		ar >> m_strItem;
		float fTemp;
		ar >> fTemp;
		m_fUnitPrice = fTemp;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CMyCustomProperties diagnostics

#ifdef _DEBUG
void CMyCustomProperties::AssertValid() const
{
	CFOBaseProperties::AssertValid();
}

void CMyCustomProperties::Dump(CDumpContext& dc) const
{
	CFOBaseProperties::Dump(dc);
}
#endif //_DEBUG


void CMyCustomProperties::DoBackUp(CFOBaseProperties* pProp)
{
	*this = *(CMyCustomProperties *)pProp;
}

BOOL CMyCustomProperties::PutValue(const int &nPropId,const FO_VALUE &value)
{
	BOOL bReturn = TRUE;
	switch(nPropId)
	{
	case M_ID_DESCRIPTION:
		{
			SetDescription(value.m_strValue);
		}
		break;
		
	case M_ID_PRODUCTNAME:
		{
			SetProductName(value.m_strValue);
		}
		break;

	case M_ID_ITEM:
		{
			SetItem(value.m_strValue);
		}
		break;

	case M_ID_UNITPRICE:
		{
			SetUnitPrice(value.m_fValue);
		}
		break;

	default:
		{
			bReturn = FALSE;
		}
		break;
		
	}


	return bReturn;
}

BOOL CMyCustomProperties::GetValue(FO_VALUE &value,const int &nPropId)
{
	BOOL bReturn = TRUE;
	switch(nPropId)
	{
	case M_ID_DESCRIPTION:
		{
			value.m_nValueType = V_STRING;
			value.m_strValue = GetDescription();
		}
		break;
		
	case M_ID_PRODUCTNAME:
		{
			value.m_nValueType = V_STRING;
			value.m_strValue = GetProductName();
		}
		break;

	case M_ID_ITEM:
		{
			value.m_nValueType = V_STRING;
			value.m_strValue = GetItem();
		}
		break;

	case M_ID_UNITPRICE:
		{
			value.m_nValueType = V_FLOAT;
			value.m_fValue = GetUnitPrice();
		}
		break;

	default:
		{
			bReturn = FALSE;
		}
		break;
		
	}


	return bReturn;
}

