#if !defined(FO_NEWVISUALPROXY_H__C4F5BA8E_D795_41AD_851D_FB8B93DE7AFD__INCLUDED_)
#define AFC_NEWVISUALPROXY_H__C4F5BA8E_D795_41AD_851D_FB8B93DE7AFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//------------------------------------------------------
// Description
// Author: ucancode.net Software.
//------------------------------------------------------
#include "FOPGDIPlusProxy.h"

 
//===========================================================================
// Summary:
//     The CNewVisualProxy class derived from CFOPGDIPlusProxy
//      New Visual Proxy
//===========================================================================

class CNewVisualProxy : public CFOPGDIPlusProxy  
{
protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N C R E A T E, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CNewVisualProxy---New Visual Proxy, Specifies a CNewVisualProxy object.
	DECLARE_DYNCREATE(CNewVisualProxy);
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// New Visual Proxy, Constructs a CNewVisualProxy object.
	//		Returns A  value.
	CNewVisualProxy();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C New Visual Proxy, Destructor of class CNewVisualProxy
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CNewVisualProxy();
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

public:

	// Generate dimension text.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Generate Dimension Text, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.  
	// Parameters:
	//		nLength---nLength, Specifies A integer value.
	virtual CString GenerateDimText(int nLength);

	// Generate the ports scales value of the CFODrawPortsShape
	// mpSpot -- list of the default ports
	
	//-----------------------------------------------------------------------
	// Summary:
	// Generate Default Ports, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		CArray<FOP_PortScale---Array< F O P_ Port Scale, Specifies A array.  
	//		mpSpot---mpSpot, A pointer to the FOP_PortScale> or NULL if the call failed.  
	//		&nShapeType---Shape Type, Specifies A integer value.
	virtual void GenerateDefaultPorts(CArray<FOP_PortScale,FOP_PortScale>* mpSpot,const int &nShapeType);

};


#endif // !defined(AFC_NEWVISUALPROXY_H__C4F5BA8E_D795_41AD_851D_FB8B93DE7AFD__INCLUDED_)
