// VisioAppDoc.h : interface of the CVisioAppDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VISIOAPPDOC_H__E4FA9075_6C02_454F_8985_16770216113B__INCLUDED_)
#define AFX_VISIOAPPDOC_H__E4FA9075_6C02_454F_8985_16770216113B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//E-XD++ Library add lines.
#include "ExtTabModelManager.h"	

 
//===========================================================================
// Summary:
//     The CVisioAppDoc class derived from COleDocument
//      Microsoft Visio style Application Document
//===========================================================================

class CVisioAppDoc : public COleDocument
{
protected: // create from serialization only
	
	//-----------------------------------------------------------------------
	// Summary:
	// Microsoft Visio style Application Document, Constructs a CVisioAppDoc object.
	//		Returns A  value.
	CVisioAppDoc();
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N C R E A T E, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CVisioAppDoc---Microsoft Visio style Application Document, Specifies a CVisioAppDoc object.
	DECLARE_DYNCREATE(CVisioAppDoc)

// Attributes
public:

	//E-XD++ Library add lines.
 
	// Model Manager, This member maintains a pointer to the object CExtTabModelManager.  
	CExtTabModelManager *m_pModelManager;
 
	// New Document, This member sets TRUE if it is right.  
	BOOL bNewDocument;
 
	// Open Document, This member sets TRUE if it is right.  
	BOOL bOpenDocument;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisioAppDoc)
	public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// On New Document, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL OnNewDocument();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Serialize, Reads or writes this object from or to an archive.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		ar---Specifies a CArchive& ar object.
	virtual void Serialize(CArchive& ar);
	//E-XD++ Library add lines.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Delete Contents, Deletes the given object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void DeleteContents();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Modified Flag, Sets a specify value to current class CVisioAppDoc
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		bModified---bModified, Specifies A Boolean value.
	virtual void SetModifiedFlag(BOOL bModified = TRUE);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Is Modified, Determines if the given value is correct or exist.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL IsModified();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Save Document, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszPathName---Path Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Open Document, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszPathName---Path Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Microsoft Visio style Application Document, Destructor of class CVisioAppDoc
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CVisioAppDoc();
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
	//{{AFX_MSG(CVisioAppDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
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

#endif // !defined(AFX_VISIOAPPDOC_H__E4FA9075_6C02_454F_8985_16770216113B__INCLUDED_)
