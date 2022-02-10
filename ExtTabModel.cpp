// ExtTabModel.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ExtTabModel.h"
#include "MyCorsssLineShape.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CExtTabModel construction/destruction

IMPLEMENT_SERIAL(CExtTabModel, CFOTabPageModel, 0)

CExtTabModel::CExtTabModel()
{
	//FOTO:Add you code here.
}

CExtTabModel::CExtTabModel(const CExtTabModel& source)
{
	*this			= source;
}

CExtTabModel::~CExtTabModel()
{
	//FOTO:Add you code here.

}

CFODataModel* CExtTabModel::Copy() const
{
	return (new CExtTabModel(*this));
}

void CExtTabModel::DoInitData()
{
	CFOTabPageModel::DoInitData();

	//FOTO:Add you code here.
}

CFOToolBoxItem *CExtTabModel::DoGetSelectToolboxItem()
{
	CChildFrame* pChildFrame = (CChildFrame *)((CMDIFrameWnd*)::AfxGetMainWnd())->MDIGetActive();
	if (pChildFrame)
	{

		CFOToolBoxItem *pSelect = pChildFrame->m_FileBar.m_wndTool.GetToolBoxWnd()->GetSelected();
		return pSelect;
	}
	
	return NULL;
}

void CExtTabModel::NotifyObserver(LPARAM lHint, CObject*pHint)
{
	CFOTabPageModel::NotifyObserver(lHint,pHint);

	//FOTO:Add you code here.

}

void CExtTabModel::UpdateTitle()
{
	CFOTabPageModel::UpdateTitle();

//	if(m_pOwner == NULL)
//	{
//		return;
//	}
//
//	if(m_pOwner->GetSafeHwnd() != NULL)
//	{
//		if(m_pOwner ->IsKindOf(RUNTIME_CLASS(CFODrawView)))
//		{
//			CFODrawView *pView = (CFODrawView *) m_pOwner;
//			CDocument *m_pDocument = (CDocument *)pView->GetDocument();
//			if(m_pDocument != NULL)
//			{
//				if (m_strTitleOrg.IsEmpty() && !m_pDocument->GetTitle().IsEmpty())
//					m_strTitleOrg = m_pDocument->GetTitle();
//				
//				if (!m_strTitleOrg.IsEmpty())
//				{
//					TCHAR szStr[256+_MAX_PATH];
//					_tcscpy(szStr, m_strTitleOrg);
//					if (IsDirty())
//					{
//						if(m_strTitleOrg.Find(_T("*"))<0)
//						{
//							lstrcat(szStr, _T(" *"));
//						}
//					}
//					if (m_pDocument->GetTitle() != szStr)
//					{
//						m_pDocument->SetTitle(szStr);
//						m_pDocument->UpdateFrameCounts();
//					}
//				}
//			}
//		}
//	}
}

void CExtTabModel::DoActionChange(const CFOBaseAction* pAction)
{
	CFOTabPageModel::DoActionChange(pAction);
	
	// FODO:Add your own specify code here.

}

CString CExtTabModel::CreateBaseName(UINT nType)
{
	CString strReturn;
	strReturn = "nLine";
	if(nType == MY_LINE_TYPE)
	{
		return strReturn;
	}
	else
	{
		return CFOTabPageModel::CreateBaseName(nType);
	}
}

CString CExtTabModel::CreateBaseCaption(UINT nType)
{
	CString strReturn;
	strReturn = "Line";
	if(nType == MY_LINE_TYPE)
	{
		return strReturn;
	}
	else
	{
		return CFOTabPageModel::CreateBaseCaption(nType);
	}

}

CString CExtTabModel::GetUniqueName(UINT nType)
{
	return CFOTabPageModel::GetUniqueName(nType);
}

CString CExtTabModel::GetUniqueCaption(UINT nType)
{

	return CFOTabPageModel::GetUniqueCaption(nType);
}

CFODrawShape *CExtTabModel::DoCreateShapeByType(UINT m_drawshape,
														CRect &rcCreate,
														CString strFileName,
														CFOToolBoxItem *pCurItem)
{
	CFODrawShape *pReturn = NULL;
	CString strCaption;
	CString strName;
	strCaption = "";
	strName = "";
	CPoint ptTrack = rcCreate.TopLeft();
	if(m_drawshape != FO_COMP_NONE)
	{
		CRect rc(rcCreate);
		rc.NormalizeRect();
		if(rc.IsRectEmpty()||(rc.Width()<=10 && rc.Height()<20))
		{
			if(m_drawshape == MY_LINE_TYPE)
			{
				rc = CRect(ptTrack.x-70,ptTrack.y-70,ptTrack.x+70,ptTrack.y+70);
			}
		}
		if(m_drawshape == MY_LINE_TYPE)
		{
			pReturn = new CMyCorsssLineShape;
			pReturn->AddRef();
			pReturn->Create(rc,"");
			strCaption = GetUniqueCaption(pReturn->GetType());
			strName = GetUniqueName(pReturn->GetType());
			pReturn->SetObjectCaption(strCaption);
			pReturn->SetObjectName(strName);
		}
		else
		{
			pReturn = CFOTabPageModel::DoCreateShapeByType(m_drawshape,rcCreate,strFileName);
		}
	}
	return pReturn;
}


CFOCompositeShape *CExtTabModel::DoCreateCompositeShapeByType(UINT m_drawshape,
																  CRect &rcCreate,
																  CArray<FOPORTVALUE,FOPORTVALUE> *arInitPorts,
																  CString strFileName,
																  UINT nResID,
																  CFOToolBoxItem *pCurItem)
{
	CFOCompositeShape *pReturn = CFOTabPageModel::DoCreateCompositeShapeByType(m_drawshape,
															rcCreate,
															arInitPorts,
															strFileName,
															nResID,
															pCurItem);
	// FODO: Add your own specify code here.

	return pReturn;
}


void CExtTabModel::SetModifiedFlag(BOOL b)
{
	CFOTabPageModel::SetModifiedFlag(b);
	
	//FOTO:Add you code here.

}

BOOL CExtTabModel::IsModified()
{

	//FOTO:Add you code here.

	return CFOTabPageModel::IsModified();
}

void CExtTabModel::Serialize(CArchive& ar)
{
	CFOTabPageModel::Serialize(ar);
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
// CPrintBaseJob serialization
CFile* CExtTabModel::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CExtTabModel::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CExtTabModel::OpenDocument(LPCTSTR lpszPathName)
{
	CFileException fe;
	CFile* pFile = GetFile(lpszPathName,
		CFile::modeRead|CFile::shareDenyWrite, &fe);
	if (pFile == NULL)
	{
		return FALSE;
	}
	strCurOpenFormFile = CString(lpszPathName);
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

BOOL CExtTabModel::SaveDocument(LPCTSTR lpszPathName)
{
	CFileException fe;
	CFile* pFile = NULL;
	pFile = GetFile(lpszPathName, CFile::modeCreate |
		CFile::modeReadWrite | CFile::shareExclusive, &fe);
	
	if (pFile == NULL)
	{
		
		return FALSE;
	}
	strCurOpenFormFile = CString(lpszPathName);
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

void CExtTabModel::OnDrawShape(CDC *pDC,const CRect &rcView)
{
	CFOTabPageModel::OnDrawShape(pDC,rcView);
	//FOTO:Add you code here.

}

void CExtTabModel::OnDrawBack(CDC *pDC,const CRect &rcClip)
{
	CFOTabPageModel::OnDrawBack(pDC,rcClip);
	//FOTO:Add you code here.

}


/////////////////////////////////////////////////////////////////////////////
// CExtTabModel diagnostics

#ifdef _DEBUG
void CExtTabModel::AssertValid() const
{
	CFOTabPageModel::AssertValid();
}

void CExtTabModel::Dump(CDumpContext& dc) const
{
	CFOTabPageModel::Dump(dc);
}
#endif //_DEBUG

CFODrawShape* CExtTabModel::FindShapeWithName(CString str)
{
	CFODrawShape* pObj = NULL;
	int xy = 0;
	for(xy = 0; xy < m_ShapeList.GetCount(); xy ++)
	{
		pObj = (CFODrawShape*)(m_ShapeList.GetObject(xy));
		if(pObj->GetObjectName() == str)
		{
			return pObj;
		}
	}
	
	return NULL;
	
}
