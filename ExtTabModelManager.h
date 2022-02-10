#if !defined(AFX_EXTTABMODELMANAGER_H__955604C6_297A_414D_8A20_86A380FE10A2__INCLUDED_)
#define AFX_EXTTABMODELMANAGER_H__955604C6_297A_414D_8A20_86A380FE10A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExtTabModelManager.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExtTabModelManager window
#include "ExtTabModel.h"

 
//===========================================================================
// Summary:
//     The CExtTabModelManager class derived from CFOTabModelManager
//      Extend Tab Model Manager
//===========================================================================

class CExtTabModelManager : public CFOTabModelManager
{
protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ S E R I A L, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CExtTabModelManager---Extend Tab Model Manager, Specifies a CExtTabModelManager object.
	DECLARE_SERIAL(CExtTabModelManager);
public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Extend Tab Model Manager, Constructs a CExtTabModelManager object.
	//		Returns A  value.
	CExtTabModelManager();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Extend Tab Model Manager, Destructor of class CExtTabModelManager
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CExtTabModelManager();

public:
	// Insert a new tab.
	// szLabel -- label of tab sheet.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Insert Tab, Inserts a child object at the given index..
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFOTabPageModel,or NULL if the call failed  
	// Parameters:
	//		szLabel---szLabel, Specifies A CString type value.
	virtual CFOTabPageModel* InsertTab(CString szLabel = _T(""));

	// Insert a new tab.
	// pModel -- a pointer to a new tab page model.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Insert Tab, Inserts a child object at the given index..
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFOTabPageModel,or NULL if the call failed  
	// Parameters:
	//		CFOTabPageModel*pModel---F O Tab Page Model*p Model, A pointer to the CFOTabPageModel or NULL if the call failed.
	virtual CFOTabPageModel* InsertTab(CFOTabPageModel*pModel);

	
	//-----------------------------------------------------------------------
	// Summary:
	// Serialize, Reads or writes this object from or to an archive.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&ar---Specifies a CArchive &ar object.
	virtual void Serialize(CArchive &ar);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Save Document, Call this function to save the specify data to a file.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszPathName---Path Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual BOOL SaveDocument(LPCTSTR lpszPathName);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Open Document, Open document from specify file.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszPathName---Path Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual BOOL OpenDocument(LPCTSTR lpszPathName);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get File, Returns the specified value.
	//		Returns a pointer to the object CFile ,or NULL if the call failed  
	// Parameters:
	//		lpszFileName---File Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.  
	//		nOpenFlags---Open Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		pError---pError, A pointer to the CFileException or NULL if the call failed.
	CFile *GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,CFileException* pError);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Release File, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pFile---pFile, A pointer to the CFile or NULL if the call failed.  
	//		bAbort---bAbort, Specifies A Boolean value.
	virtual void ReleaseFile(CFile* pFile, BOOL bAbort);
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

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTTABMODELMANAGER_H__955604C6_297A_414D_8A20_86A380FE10A2__INCLUDED_)
