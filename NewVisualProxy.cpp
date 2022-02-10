// NewVisualProxy.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "NewVisualProxy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CNewVisualProxy, CFOPGDIPlusProxy)

CNewVisualProxy::CNewVisualProxy()
{

}

CNewVisualProxy::~CNewVisualProxy()
{

}

/////////////////////////////////////////////////////////////////////////////
// CNewVisualProxy diagnostics

#ifdef _DEBUG
void CNewVisualProxy::AssertValid() const
{
	CObject::AssertValid();
}

void CNewVisualProxy::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);
}
#endif //_DEBUG

CString CNewVisualProxy::GenerateDimText(int nLength)
{
	CString strReturn;
	strReturn.Format(_T("%u Pixel"),nLength);
	return strReturn;
}


void CNewVisualProxy::GenerateDefaultPorts(CArray<FOP_PortScale,FOP_PortScale>* mpSpot,const int &nShapeType)
{
	mpSpot->RemoveAll();
	if(nShapeType == FO_COMP_COMPOSITE ||
		nShapeType == FO_COMP_STATICRECT ||
		nShapeType == FO_COMP_EDITBOX ||
		nShapeType == FO_COMP_FRAME ||
		nShapeType == FO_COMP_BUTTON ||
		nShapeType == FO_COMP_CHECKBOX ||
		nShapeType == FO_COMP_RADIO ||
		nShapeType == FO_COMP_COMBOBOX ||
		nShapeType == FO_COMP_LISTBOX ||
		nShapeType == FO_COMP_HORSCROLL ||
		nShapeType == FO_COMP_VERSCROLL ||
		nShapeType == FO_COMP_SPINEDIT ||
		nShapeType == FO_COMP_PROGRESS ||
		nShapeType == FO_COMP_SLIDER ||
		nShapeType == FO_COMP_LISTCTRL ||
		nShapeType == FO_COMP_TAB ||
		nShapeType == FO_COMP_CALENDAR ||
		nShapeType == FO_COMP_SEPARATOR ||
		nShapeType == FO_COMP_MARQUEE ||
		nShapeType == FO_COMP_ROUNDBUTTON ||
		nShapeType == FO_COMP_SELECTEDIT ||
		nShapeType == FO_COMP_MASKEDIT ||
		nShapeType == FO_COMP_PASSWORD ||
		nShapeType == FO_COMP_TABCOMBOBOX ||
		nShapeType == FO_COMP_DATETIME ||
		nShapeType == FO_COMP_MENUEDIT ||
		nShapeType == FO_COMP_CAPTION ||
		nShapeType == FOP_ROUND_CALLOUT ||
		nShapeType == FOP_RECT_CALLOUT ||
		nShapeType == FOP_CLOUD_CALLOUT ||
		nShapeType == FO_COMP_GROUP ||
		nShapeType == FO_COMP_PORT ||
		nShapeType == FOP_COMP_NEW_GRID ||
		nShapeType == FOP_NUMBER_EDITSHAPE ||
		nShapeType == FOP_COMP_AUTOFONTTEXT ||
		nShapeType == FOP_COMP_OLE ||
		nShapeType == FOP_COMP_RICHEDIT ||
		nShapeType == FOP_FONTWORK_SHAPE ||
		nShapeType == FOP_CALC_EDITSHAPE ||
		nShapeType == FO_COMP_POSTNUMBER ||
		nShapeType == FOP_COMP_SUBGRAPH ||
		nShapeType == FO_COMP_BUTTON
		
		)
	{
		mpSpot->SetSize(0);
	}
	else
	{
		mpSpot->SetSize(1);
		
		FOP_PortScale m_Scale5;
		m_Scale5.xScale = 0.5;
		m_Scale5.yScale = 0.5;
		mpSpot->SetAt(0,m_Scale5);
	}
}
