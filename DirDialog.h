////////////////////////////////////////////////////////////////////////
// DirDialog.h: interface for the CDirDialog class.
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIRDIALOG_H__62FFAC92_1DEE_11D1_B87A_0060979CDF6D__INCLUDED_)
#define AFX_DIRDIALOG_H__62FFAC92_1DEE_11D1_B87A_0060979CDF6D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

 
//===========================================================================
// Summary:
//      To use a CDirDialog object, just call the constructor.
//      Directory Dialog
//===========================================================================

class CDirDialog
{
public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Directory Dialog, Constructs a CDirDialog object.
	//		Returns A  value.
    CDirDialog();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Directory Dialog, Destructor of class CDirDialog
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
    virtual ~CDirDialog();

	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Modal, Calls a modal dialog box and returns when done.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		*pwndParent---*pwndParent, A pointer to the CWnd  or NULL if the call failed.
    BOOL DoModal(CWnd *pwndParent = NULL);

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Window Title, Sets a specify value to current class CDirDialog
	// Parameters:
	//		title---Specifies A CString type value.
	void SetWindowTitle(CString title){m_strWindowTitle = title;}
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Title, Sets a specify value to current class CDirDialog
	// Parameters:
	//		title---Specifies A CString type value.
	void SetTitle(CString title){m_strTitle = title;}
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Sel Directory, Sets a specify value to current class CDirDialog
	// Parameters:
	//		Dir---Directory, Specifies A CString type value.
	void SetSelDir(CString Dir){m_strSelDir = Dir;}
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Root Directory, Sets a specify value to current class CDirDialog
	// Parameters:
	//		Dir---Directory, Specifies A CString type value.
	void SetRootDir(CString Dir){m_strInitDir = Dir;}

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Window Text, Returns the specified value.
	//		Returns a CString type value.
	CString GetWindowText(){return m_strWindowTitle;}
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Title, Returns the specified value.
	//		Returns a CString type value.
	CString GetTitle(){return m_strTitle;}
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Pathname, Returns the specified value.
	//		Returns a CString type value.
	CString GetPathname(){return m_strPath;}

protected:
 
	// Window Title, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
    CString m_strWindowTitle;
 
	// m_strPath, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
    CString m_strPath;
 
	// Initial Directory, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
    CString m_strInitDir;
 
	// Sel Directory, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
    CString m_strSelDir;
 
	// m_strTitle, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
    CString m_strTitle;
 
	// Image Index, This variable specifies a 32-bit signed integer on 32-bit platforms.  
    int  m_iImageIndex;
 
	// m_bStatus, This member sets TRUE if it is right.  
    BOOL m_bStatus;

private:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Sel Changed, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpcsSelection---lpcsSelection, Specifies a LPCSTR lpcsSelection object.  
	//		csStatusText---Status Text, Specifies A CString type value.
    virtual BOOL SelChanged(LPCSTR lpcsSelection, CString& csStatusText) { return TRUE; };
    static int __stdcall CDirDialog::BrowseCtrlCallback(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
};

#endif // !defined(AFX_DIRDIALOG_H__62FFAC92_1DEE_11D1_B87A_0060979CDF6D__INCLUDED_)

