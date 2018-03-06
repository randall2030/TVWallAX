// Player.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TVWallAX.h"
#include "Player.h"


// CPlayer

IMPLEMENT_DYNAMIC(CPlayer, CWnd)

CPlayer::CPlayer()
: m_bSelected(false)
, m_bIsMaxsize(false)
{
	//RegisterWindowClass();
	m_edgeColor = RGB(255,255,255);
	m_edgeSelColor = RGB(255, 255, 0);
	m_bSelected = false;
	m_bIsMaxsize = false;
}

CPlayer::~CPlayer()
{
}


BEGIN_MESSAGE_MAP(CPlayer, CWnd)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
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
	CPen penEdge(PS_SOLID, 1, m_edgeColor);
	CPen* cpTemp;
	cpTemp = dc->SelectObject(&penEdge);
	rcTemp.DeflateRect(1, 1);
	if (!m_bSelected)
		dc->Draw3dRect(rcTemp, m_edgeColor, m_edgeColor);
	else
		dc->Draw3dRect(rcTemp, m_edgeSelColor, m_edgeSelColor);
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
	UINT id = this->GetDlgCtrlID() - IDC_PLAYER;
	m_playerItem.Create(NULL, _T(""), WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this,IDC_PLAYERITEM+id);
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


void CPlayer::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
}


BOOL CPlayer::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	// TODO:  �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_LBUTTONDOWN){
		
		::SendMessage(GetParent()->m_hWnd, WM_LBUTTONDOWN, 0, 0);
		//return 0;
	}
	if (pMsg->message == WM_LBUTTONDBLCLK){

		::SendMessage(GetParent()->m_hWnd, WM_LBUTTONDBLCLK, 0, 0);
	}
	return CWnd::PreTranslateMessage(pMsg);
}


void CPlayer::SetSelected(bool Selected)
{
	m_bSelected = Selected;
	Invalidate();
}


// ��ȡ���״̬
bool CPlayer::GetMaxSizeStatus()
{
	return m_bIsMaxsize;
}


// �������״̬
void CPlayer::SetMaxSizeStatus(bool bMaxSize)
{
	m_bIsMaxsize = bMaxSize;
}


void CPlayer::SavePicture()
{
	m_playerItem.SavePicture();
}


bool CPlayer::GetSelectedStatus()
{
	return m_bSelected;
}


// ����ʵʱ����
long CPlayer::StartRealPlay(long connectionID, CString cameraId)
{
	return m_playerItem.StartRealPlay(connectionID,cameraId);
}


// ֹͣʵʱ����
long CPlayer::StopRealPlay()
{
	return m_playerItem.StopRealPlay();
}


// ¼����
long CPlayer::StartLocalRecord()
{
	return m_playerItem.StartLocalRecord();
}
