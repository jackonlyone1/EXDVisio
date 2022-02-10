// ExtTabModelManager.cpp: implementation of the CExtTabModelManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ExtTabModelManager.h"
#include <afxpriv.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


/////////////////////////////////////////////////////////////////////////////
// CExtTabModelManager construction/destruction

IMPLEMENT_SERIAL(CExtTabModelManager, CFOTabModelManager, 0)
CExtTabModelManager::CExtTabModelManager()
{
	//FOTO:Add you code here.
}

CExtTabModelManager::~CExtTabModelManager()
{
	//FOTO:Add you code here.

}

void CExtTabModelManager::Serialize(CArchive& ar)
{
	CFOTabModelManager::Serialize(ar);
	if(ar.IsStoring())
	{
		//FOTO:Add you code here.

	}
	else
	{
		//FOTO:Add you code here.

	}
}

/////////////////////////////////////////////////////////////////////////////
// Serialization
CFile* CExtTabModelManager::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
							 CFileException* pError)
{
	CMirrorFile* pFile = new CMirrorFile;
	ASSERT(pFile != NULL);
	if (!pFile->Open(lpszFileName, nOpenFlags, pError))
	{
		delete pFile;
		pFile = NULL;
	}
	return pFile;
}

void CExtTabModelManager::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CExtTabModelManager::OpenDocument(LPCTSTR lpszPathName)
{
	CFileException fe;
	CFile* pFile = GetFile(lpszPathName,
		CFile::modeRead|CFile::shareDenyWrite, &fe);
	if (pFile == NULL)
	{
		return FALSE;
	}
	CArchive loadArchive(pFile, CArchive::load | CArchive::bNoFlushOnDelete);
	loadArchive.m_bForceFlat = FALSE;
	TRY
	{
		CWaitCursor wait;
		if (pFile->GetLength() != 0)
			Serialize(loadArchive);     // load me
		loadArchive.Close();
		ReleaseFile(pFile, FALSE);
	}
	CATCH_ALL(e)
	{
		ReleaseFile(pFile, TRUE);
		
		return FALSE;
	}
	END_CATCH_ALL
		
		
	return TRUE;
}

BOOL CExtTabModelManager::SaveDocument(LPCTSTR lpszPathName)
{
	CFileException fe;
	CFile* pFile = NULL;
	pFile = GetFile(lpszPathName, CFile::modeCreate |
		CFile::modeReadWrite | CFile::shareExclusive, &fe);
	
	if (pFile == NULL)
	{
		
		return FALSE;
	}
	CArchive saveArchive(pFile, CArchive::store | CArchive::bNoFlushOnDelete);
	saveArchive.m_bForceFlat = FALSE;
	TRY
	{
		CWaitCursor wait;
		Serialize(saveArchive);     // save me
		saveArchive.Close();
		ReleaseFile(pFile, FALSE);
	}
	CATCH_ALL(e)
	{
		ReleaseFile(pFile, TRUE);
		
		return FALSE;
	}
	END_CATCH_ALL
		
	return TRUE;        // success
}

/////////////////////////////////////////////////////////////////////////////
// CExtTabModelManager diagnostics

#ifdef _DEBUG
void CExtTabModelManager::AssertValid() const
{
	CFOTabModelManager::AssertValid();
}

void CExtTabModelManager::Dump(CDumpContext& dc) const
{
	CFOTabModelManager::Dump(dc);
}
#endif //_DEBUG


CFOTabPageModel* CExtTabModelManager::InsertTab(CString szLabel)
{
	if(szLabel.IsEmpty())
	{
		szLabel = GetUniquePageCaption();
	}

	CExtTabModel* pInfo = new CExtTabModel;

	pInfo->SetDataManager(this);

	pInfo->m_strCaption = szLabel;
	
	if (m_nCurrent == -1)
	{
		m_arTabs.SetAtGrow(m_nTabs, pInfo);
	}
	else
	{
		m_arTabs.InsertAt(m_nCurrent, pInfo, 1);
	}
	m_nTabs++;

	SetModifiedFlag();
	
	NotifyObserver(0,STATIC_DOWNCAST(CObject,(CObject*)pInfo));

	return pInfo;
}

CFOTabPageModel* CExtTabModelManager::InsertTab(CFOTabPageModel* pInfo)
{
	ASSERT(pInfo != NULL);
	if(pInfo->m_strCaption.IsEmpty())
	{
		pInfo->m_strCaption = GetUniquePageCaption();
	}

	pInfo->SetDataManager(this);

	if (m_nCurrent == -1)
	{
		m_arTabs.SetAtGrow(m_nTabs, pInfo);
	}
	else
	{
		m_arTabs.InsertAt(m_nCurrent, pInfo, 1);
	}
	m_nTabs++;

	SetModifiedFlag();

	NotifyObserver(0,STATIC_DOWNCAST(CObject,(CObject*)pInfo));

	return pInfo;
}
