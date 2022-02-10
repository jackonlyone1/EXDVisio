// VisioAppView.cpp : implementation of the CVisioAppView class
//

#include "stdafx.h"
#include "VisioApp.h"
#include "MainFrm.h"
#include "VisioAppDoc.h"
#include "VisioAppView.h"
#include "ChildFrm.h"
#include "MyCorsssLineShape.h"
#include "LinePropDlg.h"
#include <io.h>
#include <direct.h>
#include <stdlib.h>
#include "OutputDlg.h"

#if _MSC_VER >= 1300
	#include <fstream>
	#include <iosfwd>
	using namespace std;
#else
	#include <fstream.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVisioAppView
static int nFontSizeExt[] = 
	{8, 9, 10, 11, 12, 14, 16, 18, 20, 22, 24, 26, 28, 36, 48, 72,80,88,96,128,168,272,405,524,624};

IMPLEMENT_DYNCREATE(CVisioAppView, CFOTabPageView)
BEGIN_MESSAGE_MAP(CVisioAppView,CFOTabPageView)
	//{{AFX_MSG_MAP(CVisioAppView)
	ON_CBN_SELCHANGE(IDC_COMBO_FONTNAME, OnFontFaceChange)
	ON_CBN_SELCHANGE(IDC_COMBO_FONTSIZE, OnFontSizeChange)
	ON_CBN_SELCHANGE(IDC_COMBO_ZOOMVALUE, OnFontScaleChange)
	ON_CBN_SELCHANGE(IDC_COMBO_LAYER, OnLayerChange)
	ON_UPDATE_COMMAND_UI(ID_FONT_FACENAME, OnUpdateFontFacename)
	ON_UPDATE_COMMAND_UI(ID_FONT_TYPESIZE, OnUpdateFontTypesize)
	ON_COMMAND(ID_FONT_STYLE_BOLD, OnFontStyleBold)
	ON_UPDATE_COMMAND_UI(ID_FONT_STYLE_BOLD, OnUpdateFontStyleBold)
	ON_COMMAND(ID_FONT_STYLE_ITALIC, OnFontStyleItalic)
	ON_UPDATE_COMMAND_UI(ID_FONT_STYLE_ITALIC, OnUpdateFontStyleItalic)
	ON_COMMAND(ID_FONT_STYLE_UNDERLINE, OnFontStyleUnderline)
	ON_UPDATE_COMMAND_UI(ID_FONT_STYLE_UNDERLINE, OnUpdateFontStyleUnderline)
	ON_COMMAND(ID_FONT_BIG, OnFontBig)
	ON_UPDATE_COMMAND_UI(ID_FONT_BIG, OnUpdateFontBig)
	ON_COMMAND(ID_FONT_SMALL, OnFontSmall)
	ON_UPDATE_COMMAND_UI(ID_FONT_SMALL, OnUpdateFontSmall)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_FONT_LEFT_ALIGN, OnFontLeftAlign)
	ON_UPDATE_COMMAND_UI(ID_FONT_LEFT_ALIGN, OnUpdateFontLeftAlign)
	ON_COMMAND(ID_FONT_RIGHT_ALIGN, OnFontRightAlign)
	ON_UPDATE_COMMAND_UI(ID_FONT_RIGHT_ALIGN, OnUpdateFontRightAlign)
	ON_COMMAND(ID_FONT_CENTER, OnFontCenter)
	ON_UPDATE_COMMAND_UI(ID_FONT_CENTER, OnUpdateFontCenter)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FONT_COLOR, OnUpdateFontColor)
	ON_UPDATE_COMMAND_UI(ID_LINE_COLOR, OnUpdateLineColor)
	ON_UPDATE_COMMAND_UI(ID_LINE_WIDTH, OnUpdateLineWidth)
	ON_UPDATE_COMMAND_UI(ID_LINE_TYPE, OnUpdateLineType)
	ON_UPDATE_COMMAND_UI(ID_FILL_COLOR, OnUpdateFillColor)
	ON_COMMAND(ID_NEW_SHAPE, OnNewShape)
	ON_UPDATE_COMMAND_UI(ID_NEW_SHAPE, OnUpdateNewShape)
	ON_COMMAND(ID_FO_CUSTOM_PROPERTIES, OnFoCustomProperties)
	ON_UPDATE_COMMAND_UI(ID_FO_CUSTOM_PROPERTIES, OnUpdateFoCustomProperties)
	ON_COMMAND(ID_SAVE_DATA, OnSaveData)
	ON_UPDATE_COMMAND_UI(ID_SAVE_DATA, OnUpdateSaveData)
	ON_COMMAND(ID_DROP_MENU, OnDropMenu)
	ON_COMMAND(ID_FONT_TOP_ALIGN, OnFontTopAlign)
	ON_UPDATE_COMMAND_UI(ID_FONT_TOP_ALIGN, OnUpdateFontTopAlign)
	ON_COMMAND(ID_FONT_BOTTOM_ALIGN, OnFontBottomAlign)
	ON_UPDATE_COMMAND_UI(ID_FONT_BOTTOM_ALIGN, OnUpdateFontBottomAlign)
	ON_COMMAND(ID_FONT_VCENTER_ALIGN, OnFontVcenterAlign)
	ON_UPDATE_COMMAND_UI(ID_FONT_VCENTER_ALIGN, OnUpdateFontVcenterAlign)
	ON_COMMAND(ID_INSERT_OBJECTS, OnInsertObjects)
	ON_UPDATE_COMMAND_UI(ID_INSERT_OBJECTS, OnUpdateInsertObjects)
	ON_COMMAND(ID_BRUSH_STYLE, OnBrushStyle)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_STYLE, OnUpdateBrushStyle)
	ON_COMMAND(ID_DRAG_DROP, OnDragDrop)
	ON_UPDATE_COMMAND_UI(ID_DRAG_DROP, OnUpdateDragDrop)
	ON_COMMAND(ID_INFO_SEARCH, OnInfoSearch)
	ON_UPDATE_COMMAND_UI(ID_INFO_SEARCH, OnUpdateInfoSearch)
	ON_COMMAND(ID_SPELLCHECK, OnSpellcheck)
	ON_UPDATE_COMMAND_UI(ID_SPELLCHECK, OnUpdateSpellcheck)
	ON_COMMAND(ID_SAVE_AS_HTML, OnSaveAsHtml)
	ON_UPDATE_COMMAND_UI(ID_SAVE_AS_HTML, OnUpdateSaveAsHtml)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_FO_UNDOREDO, OnUndoRedoOK)
	ON_CONTROL(FOP_MSG__COLOR_NONE,	  ID_FONT_ARROW0,	OnNoneTextColor)
	ON_CONTROL(FOP_MSG__COLOR_CYCLE,  ID_FONT_ARROW0,	OnAutoTextColor)
	ON_CONTROL(FOP_MSG__COLOR_CHANGE, ID_FONT_ARROW0,	OnTextColorChange)

	ON_CONTROL(FOP_MSG__COLOR_NONE,	  ID_LINE_ARROW0,	OnNoneLineColor)
	ON_CONTROL(FOP_MSG__COLOR_CYCLE,  ID_LINE_ARROW0,	OnAutoLineColor)
	ON_CONTROL(FOP_MSG__COLOR_CHANGE, ID_LINE_ARROW0,	OnLineColorChange)

	ON_CONTROL(FOP_MSG__COLOR_NONE,	  ID_FILL_ARROW0,	OnNoneFillColor)
	ON_CONTROL(FOP_MSG__COLOR_CYCLE,  ID_FILL_ARROW0,	OnAutoFillColor)
	ON_CONTROL(FOP_MSG__COLOR_CHANGE, ID_FILL_ARROW0,	OnFillColorChange)

	ON_CONTROL(FOP_MSG__LINEWIDTH_NONE, ID_LINE_WIDTH_ARROW0,	OnNoneLineWidth)
	ON_CONTROL(FOP_MSG__LINEWIDTH_CHANGE, ID_LINE_WIDTH_ARROW0,	OnLineWidthChange)

	ON_CONTROL(FOP_MSG__LINETYPE_CHANGE, ID_LINE_TYPE_ARROW0,	OnLineTypeChange)
	ON_COMMAND(ID_FILE_PRINT, CFOTabPageView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFOTabPageView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFOTabPageView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisioAppView construction/destruction

CVisioAppView::CVisioAppView()
{
	// TODO: add construction code here
}

CVisioAppView::~CVisioAppView()
{
}

BOOL CVisioAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREAFOAPPWIZARDRUCT cs

	return CFOTabPageView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CVisioAppView drawing

void CVisioAppView::OnDraw(CDC* pDC)
{
	CVisioAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	Draw(pDC);
	// TODO: add draw code for native data here
}

void CVisioAppView::OnInitialUpdate()
{
	CFOTabPageView::OnInitialUpdate();

	GetCurrentModel()->ShowPort(TRUE);
	GetCurrentModel()->SetGridColor(RGB(239,239,239));
	GetCurrentModel()->SetGridLineType(GRID_VISIO);
}

/////////////////////////////////////////////////////////////////////////////
// CVisioAppView printing

BOOL CVisioAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return CFOTabPageView::OnPreparePrinting(pInfo);
}

void CVisioAppView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add extra initialization before printing
	// E-XD++ Library Add line.
	CFOTabPageView::OnBeginPrinting(pDC,pInfo);
}

void CVisioAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CVisioAppView diagnostics

#ifdef _DEBUG
void CVisioAppView::AssertValid() const
{


//E-XD++ Library add lines.
	CFOTabPageView::AssertValid();
	//CView::AssertValid();
}

void CVisioAppView::Dump(CDumpContext& dc) const
{


//E-XD++ Library add lines.
	CFOTabPageView::Dump(dc);
	//CView::Dump(dc);
}

CVisioAppDoc* CVisioAppView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVisioAppDoc)));
	return (CVisioAppDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVisioAppView message handlers
//E-XD++ Library add line.
void CVisioAppView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CFOTabPageView::OnPrint(pDC, pInfo);
}

void CVisioAppView::OnFontFaceChange()
{
	CMainFrame *pParent = STATIC_DOWNCAST(CMainFrame,AfxGetMainWnd());
	ASSERT_VALID(pParent);
	if(pParent->IsWindowVisible())
	{
		int nCur = pParent->pFontNameBox->GetCurSel();
		if(nCur != -1)
		{
			CString strFace;
			pParent->pFontNameBox->GetLBText(nCur,strFace);
			GetCurrentModel()->ChangeShapesStringProp(&m_listSelectComp,strFace,P_ID_FONT_FACENAME);

			CFOWndDC dc(this);
			POSITION pos = m_listSelectComp.GetHeadPosition();
			while(pos != NULL)
			{
				((CFODrawShape *)m_listSelectComp.GetNext(pos))->AdjustTextBoxSize(&dc);
			}

			UpdateShapes(&m_listSelectComp);
		}
	}
}

void CVisioAppView::DoZoomScaleChanging()
{
	// Override this function to handle the zoom message.
	CMainFrame *pParent = STATIC_DOWNCAST(CMainFrame,AfxGetMainWnd());
	ASSERT_VALID(pParent);
	CString strText;
	strText.Format(_T("%d"),(int)(GetZoomScale()*100.00));
    
    pParent->pScaleBox->SetWindowText(strText);
}

void CVisioAppView::OnFontScaleChange()
{
	CMainFrame *pParent = STATIC_DOWNCAST(CMainFrame,AfxGetMainWnd());
	ASSERT_VALID(pParent);
    
    int nSelection = pParent->pScaleBox->GetCurSel();
    int nPercent = 100;
    
    switch (nSelection)
	{
    case 0:
		nPercent = 10;
		break;
    case 1:
		nPercent = 20;
		break;
    case 2:
		nPercent = 40;
		break;
    case 3:
		nPercent = 80;
		break;
    case 4:
		nPercent = 100;
		break;
    case 5:
		nPercent = 200;
		break;
    case 6:
		nPercent = 300;
		break;
    case 7:
		nPercent = 400;
		break;
    case 8:
		nPercent = 600;
		break;
    case 9:
		nPercent = 800;
		break;	
    }
	
    SetZoomScale(nPercent);
}

void CVisioAppView::OnFontSizeChange()
{
	CMainFrame *pParent = STATIC_DOWNCAST(CMainFrame,AfxGetMainWnd());
	ASSERT_VALID(pParent);
	if(pParent->IsWindowVisible())
	{
		int nCur = pParent->pFontSizeBox->GetCurSel();
		if(nCur != -1)
		{
			CString strSize;
			pParent->pFontSizeBox->GetLBText(nCur,strSize);
			GetCurrentModel()->ChangeShapesIntProp(&m_listSelectComp,atoi(strSize),P_ID_FONT_POINTSIZE);
			CFOWndDC dc(this);
			POSITION pos = m_listSelectComp.GetHeadPosition();
			while(pos != NULL)
			{
				((CFODrawShape *)m_listSelectComp.GetNext(pos))->AdjustTextBoxSize(&dc);
			}

			UpdateShapes(&m_listSelectComp);
		}
	}
}

void CVisioAppView::OnUpdateFontFacename(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI;
}

void CVisioAppView::OnUpdateFontTypesize(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI;
}

void CVisioAppView::OnFontStyleBold() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			int nWeight = pObj->GetWeight();
			if(nWeight < 700)
			{
				GetCurrentModel()->ChangeShapesIntProp(&m_listSelectComp,700,P_ID_FONT_WEIGHT);
			}
			else
			{
				GetCurrentModel()->ChangeShapesIntProp(&m_listSelectComp,500,P_ID_FONT_WEIGHT);
			}
		}
		return;
	}
	
}

void CVisioAppView::OnUpdateFontStyleBold(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			pCmdUI->SetCheck(pObj->GetWeight() >= 700);
		}
		else
		{
			pCmdUI->SetCheck(FALSE);
		}
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CVisioAppView::OnFontStyleItalic() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			BOOL bItalic = pObj->GetItalic();
			GetCurrentModel()->ChangeShapesBoolProp(&m_listSelectComp,!bItalic,P_ID_FONT_ITALIC);
		}
		return;
	}
}

void CVisioAppView::OnUpdateFontStyleItalic(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			pCmdUI->SetCheck(pObj->GetItalic());
		}
		else
		{
			pCmdUI->SetCheck(FALSE);
		}
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CVisioAppView::OnFontStyleUnderline() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			BOOL bUnderline = pObj->GetUnderline();
			GetCurrentModel()->ChangeShapesBoolProp(&m_listSelectComp,!bUnderline,P_ID_FONT_UNDERLINE);
		}
		return;
	}
}

void CVisioAppView::OnUpdateFontStyleUnderline(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			pCmdUI->SetCheck(pObj->GetUnderline());
		}
		else
		{
			pCmdUI->SetCheck(FALSE);
		}
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

int CVisioAppView::GetNextFontSize(int nFont)
{
	for (int i = 0; i < 25; i++)
	{
		if(i < 24)
		{
			if(nFont >= nFontSizeExt[i] && nFont < nFontSizeExt[i+1])
			{
				return nFontSizeExt[i+1];
			}
		}
	}
	return nFontSizeExt[24];
}

int CVisioAppView::GetPrevFontSize(int nFont)
{
	for (int i = 0; i < 25; i++)
	{
		if(i > 0)
		{
			if(nFont > nFontSizeExt[i-1] && nFont <= nFontSizeExt[i])
			{
				return nFontSizeExt[i-1];
			}
		}
	}
	return nFontSizeExt[0];
}

void CVisioAppView::OnFontBig() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			int nFont = pObj->GetPointSize();
			
			GetCurrentModel()->ChangeShapesIntProp(&m_listSelectComp,GetNextFontSize(nFont),P_ID_FONT_POINTSIZE);
			CFOWndDC dc(this);
			POSITION pos = m_listSelectComp.GetHeadPosition();
			while(pos != NULL)
			{
				((CFODrawShape *)m_listSelectComp.GetNext(pos))->AdjustTextBoxSize(&dc);
			}

			UpdateShapes(&m_listSelectComp);
		}
		return;
	}
}

void CVisioAppView::OnUpdateFontBig(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI;
}

void CVisioAppView::OnFontSmall() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			int nFont = pObj->GetPointSize();
			
			GetCurrentModel()->ChangeShapesIntProp(&m_listSelectComp,GetPrevFontSize(nFont),P_ID_FONT_POINTSIZE);
			CFOWndDC dc(this);
			POSITION pos = m_listSelectComp.GetHeadPosition();
			while(pos != NULL)
			{
				((CFODrawShape *)m_listSelectComp.GetNext(pos))->AdjustTextBoxSize(&dc);
			}

			UpdateShapes(&m_listSelectComp);
		}
		return;
	}
}

void CVisioAppView::OnUpdateFontSmall(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI;
}

BOOL CVisioAppView::OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	BOOL bReturn =  CFOTabPageView::OnDrop(pDataObject, dropEffect, point);

	UpdateCells();

	return bReturn;
}

void CVisioAppView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CFOTabPageView::OnLButtonDown(nFlags, point);

	
}

void CVisioAppView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CFOTabPageView::OnLButtonUp(nFlags, point);
	UpdateCells();
}

void CVisioAppView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CFOTabPageView::OnRButtonDown(nFlags, point);

	UpdateCells();
}

void CVisioAppView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CFOTabPageView::OnUpdate(pSender,lHint,pHint);

	CMainFrame *pParent = STATIC_DOWNCAST(CMainFrame,AfxGetMainWnd());
	ASSERT_VALID(pParent);

	UpdateCells();

	if(pParent->IsWindowVisible())
	{
		pParent->m_UndoString.RemoveAll();
		pParent->m_RedoString.RemoveAll();

		GetCurrentModel()->GetUndoActionText(&pParent->m_UndoString);
		GetCurrentModel()->GetRedoActionText(&pParent->m_RedoString);
	}

	CChildFrame* pChildFrame = (CChildFrame *)((CMDIFrameWnd*)::AfxGetMainWnd())->MDIGetActive();
	if (pChildFrame)
	{
		pChildFrame->m_ListBar.InitShapes(GetCurrentModel());
	}
}

void CVisioAppView::OnFontLeftAlign() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesUINTProp(&m_listSelectComp,TextLeft,P_ID_TEXT_HORZ);
	}
}

void CVisioAppView::OnUpdateFontLeftAlign(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			pCmdUI->SetCheck(pObj->GetTextHorzAlignment() == TextLeft);
		}
		else
		{
			pCmdUI->SetCheck(FALSE);
		}
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CVisioAppView::OnFontRightAlign() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesUINTProp(&m_listSelectComp,TextRight,P_ID_TEXT_HORZ);
	}
}

void CVisioAppView::OnUpdateFontRightAlign(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			pCmdUI->SetCheck(pObj->GetTextHorzAlignment() == TextRight);
		}
		else
		{
			pCmdUI->SetCheck(FALSE);
		}
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CVisioAppView::OnFontCenter() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesUINTProp(&m_listSelectComp,TextMiddle,P_ID_TEXT_HORZ);
	}
}

void CVisioAppView::OnUpdateFontCenter(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			pCmdUI->SetCheck(pObj->GetTextHorzAlignment() == TextMiddle);
		}
		else
		{
			pCmdUI->SetCheck(FALSE);
		}
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

// Do update ruler.
void CVisioAppView::DoUpdateRuler()
{
	CChildFrame* pChildFrame = (CChildFrame *)((CMDIFrameWnd*)::AfxGetMainWnd())->MDIGetActive();
	if (pChildFrame)
	{
	}
}

void CVisioAppView::OnFilePrintPreview() 
{
	// TODO: Add your command handler code here
	FOPrintPreview(this);
}

LONG CVisioAppView::OnUndoRedoOK(UINT wParam, LONG lParam)
{
	int nTotalActions = (int)wParam;
	int nType = (int)lParam;
	AfxGetApp()->BeginWaitCursor();
	if(nType == 5000)
	{
		GetCurrentModel()->UndoMacro(nTotalActions);
	}
	else
	{
		GetCurrentModel()->RedoMacro(nTotalActions);
	}
	AfxGetApp()->EndWaitCursor();
	return 0L;
}

void CVisioAppView::OnNoneTextColor()
{
	COLORREF color;
	color = RGB(0,0,0);
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesColorProp(&m_listSelectComp,color,P_ID_FONT_COLOR);
	}

}

void CVisioAppView::OnAutoTextColor()
{
	COLORREF color;
	color = RGB(0,128,0);
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesColorProp(&m_listSelectComp,color,P_ID_FONT_COLOR);
	}

}

void CVisioAppView::OnTextColorChange()
{
	COLORREF color;
	CMainFrame* pFrameWnd = (CMainFrame*) AfxGetMainWnd();
	pFrameWnd->m_wndFontBar.SendMessageToButtons(ID_FONT_COLOR,CFOPDropColorPickerWellButton::IGetColor, &color);

	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesColorProp(&m_listSelectComp,color,P_ID_FONT_COLOR);
	}

}

void CVisioAppView::OnNoneLineColor()
{
	COLORREF color;
	color = RGB(0,0,0);
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesBoolProp(&m_listSelectComp,TRUE,P_ID_NULL_PEN);
	}
}

void CVisioAppView::OnAutoLineColor()
{
	COLORREF color;
	color = RGB(0,128,0);
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFOMultiShapePropAction* pAction = GetCurrentModel()->GetShapesPropAction();
		
		pAction->AddShapesBool(m_listSelectComp,FALSE,P_ID_NULL_PEN);
		pAction->AddShapesColor(m_listSelectComp,color,P_ID_LINE_COLOR);	
		GetCurrentModel()->Do(pAction, TRUE);
		GetCurrentModel()->SetModifiedFlag();

	}

}

void CVisioAppView::OnLineColorChange()
{
	COLORREF color;
	CMainFrame* pFrameWnd = (CMainFrame*) AfxGetMainWnd();
	pFrameWnd->m_wndFontBar.SendMessageToButtons(ID_LINE_COLOR,CFOPDropColorPickerWellButton::IGetColor, &color);

	if(m_listSelectComp.GetCount() >= 1)
	{
		CFOMultiShapePropAction* pAction = GetCurrentModel()->GetShapesPropAction();
		
		pAction->AddShapesBool(m_listSelectComp,FALSE,P_ID_NULL_PEN);
		pAction->AddShapesColor(m_listSelectComp,color,P_ID_LINE_COLOR);	
		GetCurrentModel()->Do(pAction, TRUE);
		GetCurrentModel()->SetModifiedFlag();

	}

}

void CVisioAppView::OnNoneFillColor()
{
	COLORREF color;
	color = RGB(255,255,255);
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesIntProp(&m_listSelectComp,0,P_ID_BURSHTYPE);
	}
	else
	{
		GetCurrentModel()->ChangeModelColorProp(color,M_ID_BK_COLOR);
	}
}


void CVisioAppView::OnAutoFillColor()
{
	COLORREF color;
	color = RGB(0,128,0);
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFOMultiShapePropAction* pAction = GetCurrentModel()->GetShapesPropAction();
		
		pAction->AddShapesInt(m_listSelectComp,1,P_ID_BURSHTYPE);
		pAction->AddShapesColor(m_listSelectComp,color,P_ID_BK_COLOR);	
		GetCurrentModel()->Do(pAction, TRUE);
		GetCurrentModel()->SetModifiedFlag();
	}
	else
	{
		GetCurrentModel()->ChangeModelColorProp(color,M_ID_BK_COLOR);
	}
}

void CVisioAppView::OnFillColorChange()
{
	COLORREF color;
	CMainFrame* pFrameWnd = (CMainFrame*) AfxGetMainWnd();
	pFrameWnd->m_wndFontBar.SendMessageToButtons(ID_FILL_COLOR,CFOPDropColorPickerWellButton::IGetColor, &color);

	if(m_listSelectComp.GetCount() >= 1)
	{
		CFOMultiShapePropAction* pAction = GetCurrentModel()->GetShapesPropAction();
		
		pAction->AddShapesInt(m_listSelectComp,1,P_ID_BURSHTYPE);
		pAction->AddShapesColor(m_listSelectComp,color,P_ID_BK_COLOR);	
		GetCurrentModel()->Do(pAction, TRUE);
		GetCurrentModel()->SetModifiedFlag();
	}
	else
	{
		GetCurrentModel()->ChangeModelColorProp(color,M_ID_BK_COLOR);
	}
}


void CVisioAppView::OnNoneLineWidth()
{
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesBoolProp(&m_listSelectComp,TRUE,P_ID_NULL_PEN);
	}
}

void CVisioAppView::OnLineWidthChange()
{
	int nWidth;
	CMainFrame* pFrameWnd = (CMainFrame*) AfxGetMainWnd();
	pFrameWnd->m_wndFontBar.SendMessageToButtons(ID_LINE_WIDTH,CFOPDropLineWidthPickerWellButton::IGetLineWidth, &nWidth);

	if(m_listSelectComp.GetCount() >= 1)
	{
		CFOMultiShapePropAction* pAction = GetCurrentModel()->GetShapesPropAction();
		
		pAction->AddShapesBool(m_listSelectComp,FALSE,P_ID_NULL_PEN);
		pAction->AddShapesInt(m_listSelectComp,nWidth,P_ID_LINE_WIDTH);	
		GetCurrentModel()->Do(pAction, TRUE);
		GetCurrentModel()->SetModifiedFlag();

	}
}

void CVisioAppView::OnLineTypeChange()
{
	int nLineType;
	CMainFrame* pFrameWnd = (CMainFrame*) AfxGetMainWnd();
	pFrameWnd->m_wndFontBar.SendMessageToButtons(ID_LINE_TYPE,CFOPDropLineTypePickerWellButton::IGetLineType, &nLineType);

	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesIntProp(&m_listSelectComp,nLineType,P_ID_PEN_STYLE);
	}
}

void CVisioAppView::OnUpdateFontColor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();

	pCmdUI->Enable(bDesign);
}

void CVisioAppView::OnUpdateLineColor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();

	pCmdUI->Enable(bDesign);
}

void CVisioAppView::OnUpdateLineWidth(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();

	pCmdUI->Enable(bDesign);
}

void CVisioAppView::OnUpdateLineType(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();

	pCmdUI->Enable(bDesign);
}

void CVisioAppView::OnUpdateFillColor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();

	pCmdUI->Enable(bDesign);
}

void CVisioAppView::AddToSelection(CFODrawShape *pShape)
{
	CFODrawView::AddToSelection(pShape);
	UpdateCells();
}

void CVisioAppView::RemoveFromSelection(CFODrawShape *pShape)
{
	CFODrawView::RemoveFromSelection(pShape);
	UpdateCells();
}

void CVisioAppView::RemoveAllFromSelection()
{
	CFODrawView::RemoveAllFromSelection();
	UpdateCells();
}

void CVisioAppView::UpdateCells()
{
	CMainFrame *pParent = STATIC_DOWNCAST(CMainFrame,AfxGetMainWnd());
	ASSERT_VALID(pParent);
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			if(pParent->IsWindowVisible())
			{
				CString strVer;
				strVer.Format("%u",pObj->GetPointSize());
				pParent->pFontSizeBox->SelectString(-1,strVer);
				
				pParent->pFontNameBox->SelectString(-1,pObj->GetFaceName());
				COLORREF color;
				color = pObj->GetFontColor();
				pParent->m_wndFontBar.SendMessageToButtons(ID_FONT_COLOR,CFOPDropColorPickerWellButton::ISetColor, &color);
				pParent->m_wndFontBar.SendMessageToButtons(ID_FONT_COLOR,CFOPDropColorPickerWellButton::ISetWellColor, &color);

				color = pObj->GetLineColor();
				pParent->m_wndFontBar.SendMessageToButtons(ID_LINE_COLOR,CFOPDropColorPickerWellButton::ISetColor, &color);
				pParent->m_wndFontBar.SendMessageToButtons(ID_LINE_COLOR,CFOPDropColorPickerWellButton::ISetWellColor, &color);

				color = pObj->GetBkColor();
				pParent->m_wndFontBar.SendMessageToButtons(ID_FILL_COLOR,CFOPDropColorPickerWellButton::ISetColor, &color);
				pParent->m_wndFontBar.SendMessageToButtons(ID_FILL_COLOR,CFOPDropColorPickerWellButton::ISetWellColor, &color);

				int nWidth = pObj->GetLineWidth();
				pParent->m_wndFontBar.SendMessageToButtons(ID_LINE_WIDTH,CFOPDropLineWidthPickerWellButton::ISetLineWidth, &nWidth);
				pParent->m_wndFontBar.SendMessageToButtons(ID_LINE_WIDTH,CFOPDropLineWidthPickerWellButton::ISetWellLineWidth, &nWidth);

				int nPenStyle = pObj->GetPenStyle();
				pParent->m_wndFontBar.SendMessageToButtons(ID_LINE_TYPE,CFOPDropLineTypePickerWellButton::ISetLineType, &nPenStyle);
				pParent->m_wndFontBar.SendMessageToButtons(ID_LINE_TYPE,CFOPDropLineTypePickerWellButton::ISetWellLineType, &nPenStyle);

				pParent->m_crSaveFontColor = pObj->GetFontColor();
				pParent->m_crSaveLineColor = pObj->GetLineColor();
				pParent->m_crSaveFillColor = pObj->GetBkColor();
				pParent->m_nSaveLineType = pObj->GetPenStyle();
				pParent->m_nSaveLineWidth = pObj->GetLineWidth();

				UINT nLayer = GetLayer();
				if(nLayer <= 0)
				{
					pParent->pLayerBox->SelectString(-1,_T("{No Layer}"));
				}
				else
				{
					CFOPLayer *pLay = GetCurrentModel()->FindLayer(nLayer);
					if(pLay != NULL)
					{
						pParent->pLayerBox->SelectString(-1,pLay->GetObjectName());
					}
				}
			}
		}
	}
	else
	{
		pParent->m_crSaveFillColor = GetCurrentModel()->GetBkColor();
		COLORREF color;
		color = GetCurrentModel()->GetBkColor();
		pParent->m_wndFontBar.SendMessageToButtons(ID_FILL_COLOR,CFOPDropColorPickerWellButton::ISetColor, &color);
		pParent->m_wndFontBar.SendMessageToButtons(ID_FILL_COLOR,CFOPDropColorPickerWellButton::ISetWellColor, &color);
		
		UINT nLayer = GetLayer();
		if(nLayer <= 0)
		{
			pParent->pLayerBox->SelectString(-1,_T("{No Layer}"));
		}
		else
		{
			CFOPLayer *pLay = GetCurrentModel()->FindLayer(nLayer);
			if(pLay != NULL)
			{
				pParent->pLayerBox->SelectString(-1,pLay->GetObjectName());
			}
		}
	}

}

UINT CVisioAppView::GetLayer()
{
	UINT nLayer = 0;
	if(m_listSelectComp.GetCount() == 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			return pObj->GetLayer();
		}
	}
	else if(m_listSelectComp.GetCount() > 1)
	{
		BOOL bFirst = TRUE;
		POSITION pos = m_listSelectComp.GetHeadPosition();
		CFODrawShape *pShape = NULL;
		while(pos != NULL)
		{
			pShape = (CFODrawShape *)m_listSelectComp.GetNext(pos);
			if(bFirst)
			{
				nLayer = pShape->GetLayer();
				bFirst = FALSE;
			}
			else
			{
				if(pShape->GetLayer() != nLayer)
				{
					return 0;
				}
			}
		}
	}

	return nLayer;
}

void CVisioAppView::InitLayersComboBox()
{
	CMainFrame* pFrameWnd = (CMainFrame*) AfxGetMainWnd();
	pFrameWnd->pLayerBox->ResetContent();
	pFrameWnd->pLayerBox->AddString(_T("{No Layer}"));
	CFOPLayer *pLay = NULL;
	unsigned short j;
	for (j = 0; j < GetCurrentModel()->GetLayerCount(); j++)
	{
		pLay = GetCurrentModel()->GetLayer(j);
		
		if(pLay != NULL)
		{
			int nIndex = pFrameWnd->pLayerBox->AddString(pLay->GetObjectName());
			pFrameWnd->pLayerBox->SetItemData(nIndex,(DWORD)pLay);
		}
	}

    UINT nLayer = GetLayer();
	if(nLayer <= 0)
	{
		pFrameWnd->pLayerBox->SelectString(-1,_T("{No Layer}"));
	}
	else
	{
		CFOPLayer *pLay = GetCurrentModel()->FindLayer(nLayer);
		if(pLay != NULL)
		{
			pFrameWnd->pLayerBox->SelectString(-1,pLay->GetObjectName());
		}
	}
}

void CVisioAppView::DoLayersChanged(LPARAM lHint)
{
	lHint;
	InitLayersComboBox();
}

void CVisioAppView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	// TODO: Add your specialized code here and/or call the base class
	BOOL bUpdate = FALSE;
	if (m_bActive != bActivate)
	{
		bUpdate = TRUE;
	}

	CFOTabPageView::OnActivateView(bActivate, pActivateView, pDeactiveView);

	if(bUpdate)
	{
		InitLayersComboBox();
	}
}

void CVisioAppView::OnLayerChange()
{
	CMainFrame *pParent = STATIC_DOWNCAST(CMainFrame,AfxGetMainWnd());
	ASSERT_VALID(pParent);
	if(pParent->IsWindowVisible() && m_listSelectComp.GetCount() > 0)
	{
		int nCur = pParent->pLayerBox->GetCurSel();
		if(nCur != -1)
		{
			CString strLayer;
			pParent->pLayerBox->GetLBText(nCur,strLayer);
			ChangeShapesLayer(&m_listSelectComp,strLayer);
			GetCurrentModel()->ActiveLayer(strLayer);
			pParent->pLayerBox->SelectString(-1,strLayer);
		}
	}
}

void CVisioAppView::ChangeShapesLayer(CFODrawShapeList *pList,const CString &strName)
{
	CString strLayer = strName;
	CFOPLayer* pLayer = GetCurrentModel()->GetLayer(strLayer);
	if(pLayer != NULL)
	{
		if(pList->GetCount() > 0)
		{
			CFODirectActionMacro *pAction = new CFODirectActionMacro(GetCurrentModel());

			CString strDescri;
			strDescri.LoadString(IDS_FO_CMD_CHANGELAYER);
			pAction->SetActionDescription(strDescri);

			CFODrawShape *pShape = NULL;
			POSITION pos = pList->GetHeadPosition();
			while(pos != NULL)
			{
				pShape = (CFODrawShape *)pList->GetNext(pos);

				CFOShapeIntAction* pNewAction = new CFOShapeIntAction(GetCurrentModel(),pShape);
				pNewAction->ChangePropValue(P_ID_LAYER_ID,pLayer->GetID());

		//		CFOPChangeLayerAction *pNewAction = new CFOPChangeLayerAction(GetCurrentModel(),pShape,pLayer->GetID());
				pAction->AddAction(pNewAction);
			}
			
			CFOMultiShapePropAction* pSingleAction = GetCurrentModel()->GetShapesPropAction();

			pSingleAction->AddShapesBool(*pList,pLayer->IsVisible(),P_ID_VISIBLE);
			pSingleAction->AddShapesBool(*pList,pLayer->IsLock(),P_ID_LOCK);
			pSingleAction->AddShapesBool(*pList,pLayer->IsPrintProtect(),P_ID_PRINTPROTECT);

			pAction->AddMacroAction(pSingleAction);
			
			pAction->m_bUpdateAll = TRUE;
			pAction->m_bRemoveAllSelection = TRUE;

			if(!GetCurrentModel()->Do(pAction, TRUE))
			{
				delete pAction;
			}
		}
	}
}

void CVisioAppView::OnNewShape() 
{
	// TODO: Add your command handler code here
	m_drawshape = MY_LINE_TYPE;
	SetCurrentDrawingCursor(IDC_FO_DRAW_COMP_CURSOR);
	m_action_state = State_DrawRect;
}

void CVisioAppView::OnUpdateNewShape(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_drawshape == MY_LINE_TYPE);
}

void CVisioAppView::OnFoCustomProperties() 
{
	// TODO: Add your command handler code here
	CFODrawShapeList lstUpdate;

	CFODrawShapeList m_ListTemp;
	int nCount = 0;
	BOOL bFirst = TRUE;
	CFODrawShape *pShape = NULL;
	CMyCorsssLineShape *pFirst = NULL;
	POSITION pos = m_listSelectComp.GetHeadPosition();
	while(pos != NULL)
	{
		pShape = (CFODrawShape *)m_listSelectComp.GetNext(pos);
		if(HAS_BASE(pShape,CMyCorsssLineShape))
		{
			if(bFirst)
			{
				pFirst = static_cast<CMyCorsssLineShape *>(pShape);
				bFirst = FALSE;
			}
			m_ListTemp.AddTail(pShape);
			nCount ++;
		}
		lstUpdate.AddTail(pShape);
	}

	if(nCount > 0)
	{
		CMyCustomProperties *pProp = pFirst->GetLineProperty();
		CLinePropDlg dlg;
		dlg.m_strOldDescription = dlg.m_strDescription = pProp->GetDescription();
		dlg.m_nOldLineWidth = dlg.m_nLineWidth = pFirst->GetLineWidth();
		dlg.m_strOldProductName = dlg.m_strProductName = pProp->GetProductName();
		dlg.m_strOldItem = dlg.m_strItem = pProp->GetItem();
		dlg.m_fOldUnitPrice = dlg.m_fUnitPrice = pProp->GetUnitPrice();
		if(dlg.DoModal() == IDOK)
		{
			if(dlg.m_bModify)
			{
				CFOMultiShapePropAction* pAction = GetCurrentModel()->GetShapesPropAction();

				pAction->AddShapesString(m_ListTemp,dlg.m_strDescription,M_ID_DESCRIPTION);
				pAction->AddShapesInt(m_ListTemp,dlg.m_nLineWidth,P_ID_LINE_WIDTH);
				pAction->AddShapesString(m_ListTemp,dlg.m_strProductName,M_ID_PRODUCTNAME);
				pAction->AddShapesString(m_ListTemp,dlg.m_strItem,M_ID_ITEM);
				pAction->AddShapesFloat(m_ListTemp,dlg.m_fUnitPrice,M_ID_UNITPRICE);	
				
				GetCurrentModel()->Do(pAction, TRUE);
				GetCurrentModel()->SetModifiedFlag();
			}
		}
	}
	else
	{
		OnFOPFoCustomProperties();
	}

	if(lstUpdate.GetCount()>0)
	{
		UpdateShapes(&lstUpdate);
	}
}

void CVisioAppView::OnUpdateFoCustomProperties(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	
	pCmdUI->Enable(m_listSelectComp.GetCount()>0 && bDesign);
}

CMenu* CVisioAppView::CreateContextMenu()
{
	// load the menu resource
	if (m_pContextMenu)
	{
		delete m_pContextMenu;
	}
	
	CMenu* pMenu;
	m_pContextMenu = new CMenu();
	m_pContextMenu->LoadMenu(IDR_NEW_MENU);
	
	if(m_listSelectComp.GetCount() == 1)
	{
		pMenu = m_pContextMenu->GetSubMenu(0);
		AddOleToMenu(pMenu->m_hMenu);
	}
	else
	{
		pMenu = m_pContextMenu->GetSubMenu(0);
	}
	
	ASSERT_VALID(pMenu);
	return pMenu;
}

int CVisioAppView::GetCustomCount()
{
	int nCount = 0;
	CFODrawShape *pShape;
	POSITION pos = m_listSelectComp.GetHeadPosition();
	while(pos != NULL)
	{
		pShape = (CFODrawShape *)m_listSelectComp.GetNext(pos);
		if(HAS_BASE(pShape,CMyCorsssLineShape))
		{
			nCount ++;
		}
	}

	return nCount;
}


void CVisioAppView::OnSaveData() 
{
	// TODO: Add your command handler code here
	CFODrawShapeList m_ListTemp;
	int nCount = 0;
	CFODrawShape *pShape = NULL;
	int xy = 0;
	for(xy = 0; xy < GetCurrentModel()->GetFormObjects()->GetCount(); xy ++)
	{
		pShape = (CFODrawShape*)(GetCurrentModel()->GetFormObjects()->GetObject(xy));
		if(HAS_BASE(pShape,CMyCorsssLineShape))
		{
			m_ListTemp.AddTail(pShape);
			nCount ++;
		}
	}

	if(nCount > 0)
	{
		COutputDlg dlg;
		if(dlg.DoModal() == IDOK)
		{
			CString strPath = dlg.m_strPath;
			
			CString strFileName;
			strFileName = strPath +"output.txt";// File name
			
			CFile cfile;
			if (!cfile.Open(strFileName,CFile::modeCreate|CFile::modeWrite))
				return;
			cfile.Close();
			ofstream dc((const char *)strFileName);
			
			CMyCorsssLineShape *pCustShape = NULL;
			POSITION posnew = m_ListTemp.GetHeadPosition();
			while(posnew != NULL)
			{
				pCustShape = (CMyCorsssLineShape *)m_ListTemp.GetNext(posnew);
				CMyCustomProperties *pProp = pCustShape->GetLineProperty();
				dc<<"\n";
				dc<<"Name = " << pCustShape->GetObjectName() << "\n";
				dc<<"Caption = " << pCustShape->GetObjectCaption() << "\n";
				dc<<"Product Name = " << pProp->GetProductName() << "\n";
				dc<<"Item = " << pProp->GetItem() << "\n";
				dc<<"Unit Price = " << pProp->GetUnitPrice() << "\n";
				dc<<"Description = " << pProp->GetDescription() << "\n";
				dc<<"\n";

				int y = 0;
				int nPtCount = pCustShape->GetSpotCount();
				for( int x = 0; x < nPtCount; x++)
				{
					CPoint pt = pCustShape->GetPointAt(x);
					dc<<"{" << pt.x << "," << pt.y << "}, ";
					y ++;
					if( y >= 5)
					{
						dc<<"\n";
						y = 0;
					}
				}
				dc<<"\n";			
			}

			AfxGetApp()->BeginWaitCursor();
			Sleep(1000);
			
			ShellExecute(0, "open", strFileName, 0, 0, SW_SHOWNORMAL);
			
			AfxGetApp()->EndWaitCursor();
		}
	}
}

void CVisioAppView::OnUpdateSaveData(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	int nCount = GetCustomCount();
	pCmdUI->Enable(nCount > 0 && bDesign);
}

void CVisioAppView::AsignCustomProperties(CString strShapeName,const CMyCustomProperties &prop)
{
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());

	CFODrawShape *pShape = pModel->FindShapeWithName(strShapeName);
	if(pShape != NULL)
	{
		if(HAS_BASE(pShape,CMyCorsssLineShape))
		{
			CMyCorsssLineShape *pCustShape = static_cast<CMyCorsssLineShape *>(pShape);
			CMyCustomProperties *pProp = pCustShape->GetLineProperty();
			pProp->SetProductName(prop.GetProductName());
			pProp->SetItem(prop.GetItem());
			pProp->SetDescription(prop.GetDescription());
			pProp->SetUnitPrice(prop.GetUnitPrice());
		}
	}
}

void CVisioAppView::OnDropMenu() 
{
	// TODO: Add your command handler code here
	
}

void CVisioAppView::OnMovePrevious() 
{
	// TODO: Add your command handler code here
	CFODrawShapeList lstUpdate;
	POSITION posx = m_listSelectComp.GetHeadPosition();
	while(posx != NULL)
	{
		lstUpdate.AddTail(m_listSelectComp.GetNext(posx));
	}
		
	CFODrawShape *pCurrent = GetCurrentSelectShape();
	if(pCurrent != NULL)
	{
		m_listSelectComp.RemoveAll();

		int nTabOrder = pCurrent->GetTabOrder();
		CFODrawShape *pObj = GetCurrentModel()->GetPrevTabOrderShape(*GetCurrentModel()->GetFormObjects(),nTabOrder);
		m_listSelectComp.AddTail(pObj);
		lstUpdate.AddTail(pObj);

		UpdateShapes(&lstUpdate);
	}
}

void CVisioAppView::OnUpdateMovePrevious(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	CFODrawShapeList m_listDelete;
	GetDeletingShapes(&m_listDelete);
	pCmdUI->Enable(m_listDelete.GetCount() == 1 && bDesign);
}

void CVisioAppView::OnMoveNext() 
{
	// TODO: Add your command handler code here
	CFODrawShapeList lstUpdate;
	POSITION posx = m_listSelectComp.GetHeadPosition();
	while(posx != NULL)
	{
		lstUpdate.AddTail(m_listSelectComp.GetNext(posx));
	}
		
	CFODrawShape *pCurrent = GetCurrentSelectShape();
	if(pCurrent != NULL)
	{
		m_listSelectComp.RemoveAll();

		int nTabOrder = pCurrent->GetTabOrder();
		CFODrawShape *pObj = GetCurrentModel()->GetNextTabOrderShape(*GetCurrentModel()->GetFormObjects(),nTabOrder);
		m_listSelectComp.AddTail(pObj);
		lstUpdate.AddTail(pObj);

		UpdateShapes(&lstUpdate);
	}
}

void CVisioAppView::OnUpdateMoveNext(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	CFODrawShapeList m_listDelete;
	GetDeletingShapes(&m_listDelete);
	pCmdUI->Enable(m_listDelete.GetCount() == 1 && bDesign);
}

void CVisioAppView::OnFontTopAlign() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesUINTProp(&m_listSelectComp,TextTop,P_ID_TEXT_VERT);
	}
}

void CVisioAppView::OnUpdateFontTopAlign(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			pCmdUI->SetCheck(pObj->GetTextVertAlignment() == TextTop);
		}
		else
		{
			pCmdUI->SetCheck(FALSE);
		}
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}

	BOOL bDesign = GetCurrentModel()->IsDesignMode();

	pCmdUI->Enable(bDesign);
}

void CVisioAppView::OnFontBottomAlign() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesUINTProp(&m_listSelectComp,TextBottom,P_ID_TEXT_VERT);
	}
}

void CVisioAppView::OnUpdateFontBottomAlign(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			pCmdUI->SetCheck(pObj->GetTextVertAlignment() == TextBottom);
		}
		else
		{
			pCmdUI->SetCheck(FALSE);
		}
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}

	BOOL bDesign = GetCurrentModel()->IsDesignMode();

	pCmdUI->Enable(bDesign);
}

void CVisioAppView::OnFontVcenterAlign() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		GetCurrentModel()->ChangeShapesUINTProp(&m_listSelectComp,TextCenter,P_ID_TEXT_VERT);
	}
}

void CVisioAppView::OnUpdateFontVcenterAlign(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_listSelectComp.GetCount() >= 1)
	{
		CFODrawShape *pObj = GetCurrentSelectShape();
		if(pObj != NULL)
		{
			pCmdUI->SetCheck(pObj->GetTextVertAlignment() == TextCenter);
		}
		else
		{
			pCmdUI->SetCheck(FALSE);
		}
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}

	BOOL bDesign = GetCurrentModel()->IsDesignMode();

	pCmdUI->Enable(bDesign);
}

void CVisioAppView::OnInsertObjects() 
{
	// TODO: Add your command handler code here
	OnFOPInsertObject();
}

void CVisioAppView::OnUpdateInsertObjects(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	pCmdUI->Enable(bDesign);

}

void CVisioAppView::OnBrushStyle() 
{
	// TODO: Add your command handler code here
	
}

void CVisioAppView::OnUpdateBrushStyle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CVisioAppView::OnDragDrop() 
{
	// TODO: Add your command handler code here
	m_drawshape = FO_DROP_TOOLBOX_SHAPE_TYPE;
	SetCurrentDrawingCursor(IDC_FO_DRAWSHAPE_CURSOR);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CVisioAppView::OnUpdateDragDrop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
	CChildFrame* pChildFrame = (CChildFrame *)((CMDIFrameWnd*)::AfxGetMainWnd())->MDIGetActive();
	if (pChildFrame)
	{
		if(pChildFrame->m_FileBar.IsWindowVisible())
		{
			if(pChildFrame->m_FileBar.m_wndTool.GetToolBoxWnd()->GetSelected() != NULL)
			{
				pCmdUI->Enable(TRUE);
			}
		}
	}
}

void CVisioAppView::OnInfoSearch() 
{
	// TODO: Add your command handler code here
	AfxMessageBox(_T("This feature is not implemented at this time, contact support@ucancode.net"), MB_OK|MB_ICONINFORMATION);
}

void CVisioAppView::OnUpdateInfoSearch(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CVisioAppView::OnSpellcheck() 
{
	// TODO: Add your command handler code here
	AfxMessageBox(_T("This feature is not implemented at this time, contact support@ucancode.net"), MB_OK|MB_ICONINFORMATION);
}

void CVisioAppView::OnUpdateSpellcheck(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CVisioAppView::OutputHtml(CString strRootPath,CSize szChart)
{
	CString strPath;
	strPath = strRootPath;
	
	CString strFileName;
	strFileName = strPath +"output.htm";// File name
	
	CFile cfile;
	if (!cfile.Open(strFileName,CFile::modeCreate|CFile::modeWrite))
		return;
	cfile.Close();
	ofstream dc((const char *)strFileName);
	
	dc<<"<html>\n";
	dc<<"\n";
	dc<<"<head>\n";
	dc<<"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">\n";
	dc<<"<meta name=\"GENERATOR\" content=\"Microsoft FrontPage 4.0\">\n";
	dc<<"<meta name=\"ProgId\" content=\"FrontPage.Editor.Document\">\n";
	dc<<"<title>This is just a test!</title>\n";
	dc<<"</head>\n";
	dc<<"\n";
	dc<<"<body>\n";
	dc<<"\n";
	
	dc<<"<p><img border=\"0\" src=\"output.bmp\" width=\""<<szChart.cx<<"\" height=\""<<szChart.cy<<"\"></p>\n";
	
	dc<<" \n";
	dc<<"</body> \n";
	dc<<" \n";
	dc<<"</html> \n";
	
	AfxGetApp()->BeginWaitCursor();
	Sleep(1000);
	
	AfxGetApp()->EndWaitCursor();
	
	ShellExecute(0, "open", strFileName, 0, 0, SW_SHOWNORMAL);
	
}

void CVisioAppView::OnSaveAsHtml() 
{
	// TODO: Add your command handler code here
	COutputDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		CString strPath = dlg.m_strPath;
		CString strImage = strPath +"output.bmp";
		
		GetCurrentModel()->ShowMargin(FALSE);
		GetCurrentModel()->ShowGrid(FALSE);
		ExportAsBmpfile(strImage);
		
		CRect rcForm = GetCurrentModel()->GetPagePosition();
		CSize szBitmap(rcForm.Width(), rcForm.Height());
		OutputHtml(strPath,szBitmap);
	}
}

void CVisioAppView::OnUpdateSaveAsHtml(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
