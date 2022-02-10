// StdioFileEx.h: interface for the CStdioFileEx class.

#if !defined(AFX_STDIOFILEEX_H__41AFE3CA_25E0_482F_8B00_C40775BCDB81__INCLUDED_)
#define AFX_STDIOFILEEX_H__41AFE3CA_25E0_482F_8B00_C40775BCDB81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	nUNICODE_BOM						0xFEFF		// Unicode "byte order mark" which goes at start of file
#define	sNEWLINE								_T("\r\n")	// New line characters
#define	sDEFAULT_UNICODE_FILLER_CHAR	"#"			// Filler char used when no conversion from Unicode to local code page is possible

 
//===========================================================================
// Summary:
//     The CStdioFileEx class derived from CStdioFile
//      Stdio File Ex
//===========================================================================

class CStdioFileEx: public CStdioFile
{
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Stdio File Ex, Constructs a CStdioFileEx object.
	//		Returns A  value.
	CStdioFileEx();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Stdio File Ex, Constructs a CStdioFileEx object.
	//		Returns A  value.  
	// Parameters:
	//		lpszFileName---File Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.  
	//		nOpenFlags---Open Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	CStdioFileEx( LPCTSTR lpszFileName, UINT nOpenFlags );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Open, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszFileName---File Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.  
	//		nOpenFlags---Open Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		pError---pError, A pointer to the CFileException or NULL if the call failed.
	virtual BOOL	Open( LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Read String, Call this function to read the specify data from an archive.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		rString---rString, Specifies A CString type value.
	virtual BOOL	ReadString(CString& rString);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Write String, Writes a specified number of bytes to the archive. The archive does not format the bytes.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		lpsz---Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual void	WriteString( LPCTSTR lpsz );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Is File Unicode Text, Determines if the given value is correct or exist.
	//		Returns A Boolean value.
	bool				IsFileUnicodeText()	{ return m_bIsUnicodeText; }	
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Char Count, Returns the specified value.
	//		Returns A 32-bit signed integer.
	unsigned long	GetCharCount();

	// Additional flag to allow Unicode text writing
 
	// Write Unicode, This member can be sets with A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	static const UINT modeWriteUnicode;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Code Page, Sets a specify value to current class CStdioFileEx
	// Parameters:
	//		nCodePage---Code Page, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	void				SetCodePage(IN const UINT nCodePage);

	// static utility functions

	// --------------------------------------------------------------------------------------------
	//
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Unicode String From Multiple Byte String, Returns the specified value.
	// This member function is a static function.
	//		Returns a int type value.  
	// Parameters:
	//		szMultiByteString---Multiple Byte String, Specifies a IN LPCSTR szMultiByteString object.  
	//		szUnicodeString---Unicode String, A pointer to the OUT wchar_t or NULL if the call failed.  
	//		nUnicodeBufferSize---Unicode Buffer Size, Specifies A integer value.  
	//		nCodePage---Code Page, Specifies A integer value.
	//	CStdioFileEx::GetUnicodeStringFromMultiByteString()
	//
	// --------------------------------------------------------------------------------------------
	// Returns:    int - num. of chars written (0 means error)
	// Parameters: char *		szMultiByteString		(IN)		Multi-byte input string
	//					wchar_t*		szUnicodeString		(OUT)		Unicode outputstring
	//					int			nUnicodeBufferSize	(IN)		Size of Unicode output buffer (chars) (IN)
	//					int			nCodePage				(IN)		Code page used to perform conversion
	//																			Default = -1 (Get local code page).
	//
	// Purpose:		Gets a Unicode string from a MultiByte string.
	// Notes:		None.
	// Exceptions:	None.
	//
	static int		GetUnicodeStringFromMultiByteString(IN LPCSTR szMultiByteString, OUT wchar_t* szUnicodeString, IN int nUnicodeBufferSize, IN int nCodePage=-1);

	// --------------------------------------------------------------------------------------------
	//
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Multiple Byte String From Unicode String, Returns the specified value.
	// This member function is a static function.
	//		Returns a int type value.  
	// Parameters:
	//		szUnicodeString---Unicode String, A pointer to the wchar_t  or NULL if the call failed.  
	//		szMultiByteString---Multiple Byte String, A pointer to the char or NULL if the call failed.  
	//		nMultiByteBufferSize---Multiple Byte Buffer Size, Specifies A integer value.  
	//		nCodePage---Code Page, Specifies A integer value.
	//	CStdioFileEx::GetMultiByteStringFromUnicodeString()
	//
	// --------------------------------------------------------------------------------------------
	// Returns:    int - number of characters written. 0 means error
	// Parameters: wchar_t *	szUnicodeString			(IN)	Unicode input string
	//					char*			szMultiByteString			(OUT)	Multibyte output string
	//					int			nMultiByteBufferSize		(IN)	Multibyte buffer size
	//					int			nCodePage					(IN)	Code page used to perform conversion
	//																			Default = -1 (Get local code page).
	//
	// Purpose:		Gets a MultiByte string from a Unicode string.
	// Notes:		.
	// Exceptions:	None.
	//
	static int			GetMultiByteStringFromUnicodeString(wchar_t * szUnicodeString,char* szMultiByteString,
																			int nMultiByteBufferSize,int nCodePage=-1);

	//---------------------------------------------------------------------------------------------------
	//
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Required Multiple Byte Length For Unicode String, Returns the specified value.
	// This member function is a static function.
	//		Returns a int type value.  
	// Parameters:
	//		szUnicodeString---Unicode String, A pointer to the wchar_t  or NULL if the call failed.  
	//		nCodePage---Code Page, Specifies A integer value.
	//	CStdioFileEx::GetRequiredMultiByteLengthForUnicodeString()
	//
	//---------------------------------------------------------------------------------------------------
	// Returns:    int
	// Parameters: wchar_t * szUnicodeString,int nCodePage=-1
	//
	// Purpose:		Obtains the multi-byte buffer size needed to accommodate a converted Unicode string.
	//	Notes:		We can't assume that the buffer length is simply equal to the number of characters
	//					because that wouldn't accommodate multibyte characters!
	//
	static int			GetRequiredMultiByteLengthForUnicodeString(wchar_t * szUnicodeString,int nCodePage=-1);


	// --------------------------------------------------------------------------------------------
	//
	
	//-----------------------------------------------------------------------
	// Summary:
	// Is File Unicode, Determines if the given value is correct or exist.
	// This member function is a static function.
	//		Returns A Boolean value.  
	// Parameters:
	//		sFilePath---File Path, Specifies A CString type value.
	//	CStdioFileEx::IsFileUnicode()
	//
	// --------------------------------------------------------------------------------------------
	// Returns:    bool
	// Parameters: const CString& sFilePath
	//
	// Purpose:		Determines whether a file is Unicode by reading the first character and detecting
	//					whether it's the Unicode byte marker.
	// Notes:		None.
	// Exceptions:	None.
	//
	static bool IsFileUnicode(const CString& sFilePath);

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Current Locale Code Page, Returns the specified value.
	// This member function is a static function.
	//		Returns a UINT type value.
	static UINT	GetCurrentLocaleCodePage();

protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Process Flags, Call the Process member function to translate a caught exception.
	//		Returns a UINT type value.  
	// Parameters:
	//		sFilePath---File Path, Specifies A CString type value.  
	//		nOpenFlags---Open Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	UINT	ProcessFlags(const CString& sFilePath, UINT& nOpenFlags);

 
	// Is Unicode Text, Specify A Boolean value.  
	bool		m_bIsUnicodeText;
 
	// m_nFlags, This member can be sets with A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	UINT		m_nFlags;
 
	// File Code Page, This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int		m_nFileCodePage;
};

#endif // !defined(AFX_STDIOFILEEX_H__41AFE3CA_25E0_482F_8B00_C40775BCDB81__INCLUDED_)
