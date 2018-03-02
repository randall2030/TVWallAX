// Player.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TVWallAX.h"
#include "Player.h"


// CPlayer

IMPLEMENT_DYNAMIC(CPlayer, CWnd)

CPlayer::CPlayer()
{
	//RegisterWindowClass();
}

CPlayer::~CPlayer()
{
}


BEGIN_MESSAGE_MAP(CPlayer, CWnd)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CPlayer ��Ϣ�������




BOOL CPlayer::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rt;
	GetClientRect(rt);
	pDC->FillSolidRect(rt, RGB(0, 0,0));
	//pDC->TextOut(10,10,_T("Test"));
	DrawEdge(pDC);
	return true;
}



// ���Ʊ�
void CPlayer::DrawEdge(CDC* dc)
{
	CRect rcWindow;
	CRect rcTemp;
	GetWindowRect(&rcWindow);
	rcWindow.OffsetRect(-rcWindow.TopLeft());
	rcTemp = rcWindow;
	//
	CPen penEdge(PS_SOLID, 1, RGB(255, 255, 0));
	CPen* cpTemp;
	cpTemp = dc->SelectObject(&penEdge);
	rcTemp.DeflateRect(1, 1);
   	dc->Draw3dRect(rcTemp, RGB(255, 255, 0), RGB(255, 255, 0));
	dc->SelectObject(cpTemp);
	
}
//BOOL CPlayer::RegisterWindowClass(HINSTANCE hInstance)
//{
//	LPCWSTR className = L"CPlayer";//"CMyWin"�ؼ��������   
//	WNDCLASS windowclass;
//
//	if (hInstance)
//		hInstance = AfxGetInstanceHandle();
//
//	if (!(::GetClassInfo(hInstance, className, &windowclass)))
//	{
//		windowclass.style = CS_DBLCLKS;
//		windowclass.lpfnWndProc = ::DefWindowProc;
//		windowclass.cbClsExtra = windowclass.cbWndExtra = 0;
//		windowclass.hInstance = hInstance;
//		windowclass.hIcon = NULL;
//		windowclass.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
//		windowclass.hbrBackground = ::GetSysColorBrush(COLOR_WINDOW);
//			windowclass.lpszMenuName = NULL;
//		windowclass.lpszClassName = className;
//
//		if (!AfxRegisterClass(&windowclass))
//		{
//			AfxThrowResourceException();
//			return FALSE;
//		}
//	}
//
//	return TRUE;
//}

int CPlayer::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_playerItem.Create(NULL, _T(""), WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, IDC_CUSTOMER + 1);
	return 0;
}


void CPlayer::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()
	CRect rect;
	GetClientRect(&rect);
	rect.DeflateRect(6, 6, 6, 6);
	if (m_playerItem){
		m_playerItem.MoveWindow(&rect);
	}
}
