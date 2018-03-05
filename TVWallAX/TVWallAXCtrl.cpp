// TVWallAXCtrl.cpp : CTVWallAXCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "TVWallAX.h"
#include "TVWallAXCtrl.h"
#include "TVWallAXPropPage.h"
#include "afxdialogex.h"

#define WM_THREADFIREEVENT WM_APP+101

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CTVWallAXCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CTVWallAXCtrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CTVWallAXCtrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_CONTROL_RANGE(BN_CLICKED,IDC_ONESCREEN,IDC_SIXTEENSCREEN,OnScreenBtnClicked)
	ON_CONTROL(BN_CLICKED,IDC_FULLSCREEN,OnFullScreenBtnClicked)
	ON_CONTROL(BN_CLICKED,IDC_SCREENSHOT,OnScreenShotBtnClicked)
	ON_WM_WINDOWPOSCHANGING()
	ON_MESSAGE(WM_THREADFIREEVENT,OnFireEventForThread)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CTVWallAXCtrl, COleControl)
	DISP_FUNCTION_ID(CTVWallAXCtrl, "SetScreenNum", dispidSetScreenNum, SetScreenNum, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CTVWallAXCtrl, COleControl)
	EVENT_CUSTOM_ID("calljs", eventidcalljs, calljs, VTS_I2)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(CTVWallAXCtrl, 1)
	PROPPAGEID(CTVWallAXPropPage::guid)
END_PROPPAGEIDS(CTVWallAXCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CTVWallAXCtrl, "TVWALLAX.TVWallAXCtrl.1",
	0xc639e623, 0xf7c2, 0x445e, 0xb8, 0x89, 0x9d, 0x72, 0xb4, 0x67, 0xd4, 0xf4)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CTVWallAXCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DTVWallAX = { 0x287392D1, 0xCAFD, 0x4EBA, { 0x9B, 0x4C, 0xE8, 0x7C, 0x49, 0x1F, 0x36, 0x38 } };
const IID IID_DTVWallAXEvents = { 0x8E0C406E, 0xDBCD, 0x4EE0, { 0x8F, 0x89, 0x61, 0x8C, 0xBD, 0xEF, 0x47, 0x65 } };

// �ؼ�������Ϣ

static const DWORD _dwTVWallAXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTVWallAXCtrl, IDS_TVWALLAX, _dwTVWallAXOleMisc)

// CTVWallAXCtrl::CTVWallAXCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CTVWallAXCtrl ��ϵͳע�����

BOOL CTVWallAXCtrl::CTVWallAXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_TVWALLAX,
			IDB_TVWALLAX,
			afxRegApartmentThreading,
			_dwTVWallAXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CTVWallAXCtrl::CTVWallAXCtrl - ���캯��

CTVWallAXCtrl::CTVWallAXCtrl()
	: m_a(0)
{
	InitializeIIDs(&IID_DTVWallAX, &IID_DTVWallAXEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
	m_bFullScreenFlag = false;
}

// CTVWallAXCtrl::~CTVWallAXCtrl - ��������

CTVWallAXCtrl::~CTVWallAXCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CTVWallAXCtrl::OnDraw - ��ͼ����

void CTVWallAXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;
	//������ɫ
	pdc->FillSolidRect(rcBounds,RGB(0,0,0));

	if (m_playerGroup)
	{
		CRect rect = rcBounds;
		rect.DeflateRect(0, 0, 0, 50);
		m_playerGroup.MoveWindow(rect);///2
		
		int margin_left = 5, margin_top = 5 , width = 40, height = 40;

		for (int i = 0; i < 8; ++i){

			GetDlgItem(IDC_ONESCREEN+i)->MoveWindow(CRect(rect.left + margin_left*(i+1)+width*i, rect.bottom + margin_top, 
				rect.left + margin_left * (i + 1) + width* (i+1), rect.bottom + height+margin_top-2));
		}
		/*GetDlgItem(IDC_ONESCREEN)->MoveWindow(CRect(rect.left+2,rect.bottom+2,rect.left+52,rect.bottom+42));
		GetDlgItem(IDC_FOURSCREEN)->MoveWindow(CRect(rect.left + 2, rect.bottom + 2, rect.left + 52, rect.bottom + 42));
		GetDlgItem(IDC_SIXSCREEN)->MoveWindow(CRect(rect.left + 2, rect.bottom + 2, rect.left + 52, rect.bottom + 42));
		GetDlgItem(IDC_EIGHTSCREEN)->MoveWindow(CRect(rect.left + 2, rect.bottom + 2, rect.left + 52, rect.bottom + 42));
		GetDlgItem(IDC_NINESCREEN)->MoveWindow(CRect(rect.left + 2, rect.bottom + 2, rect.left + 52, rect.bottom + 42));
		GetDlgItem(IDC_SIXTEENSCREEN)->MoveWindow(CRect(rect.left + 2, rect.bottom + 2, rect.left + 52, rect.bottom + 42));*/
	}
	//DoSuperclassPaint(pdc, rcBounds);
}

// CTVWallAXCtrl::DoPropExchange - �־���֧��

void CTVWallAXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CTVWallAXCtrl::GetControlFlags -
// �Զ��� MFC �� ActiveX �ؼ�ʵ�ֵı�־��
//
DWORD CTVWallAXCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// �ڻ�Ͳ��״̬֮�����ת��ʱ��
	// �������»��ƿؼ���
	dwFlags |= noFlickerActivate;
	return dwFlags;
}


// CTVWallAXCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CTVWallAXCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CTVWallAXCtrl::PreCreateWindow - �޸� CreateWindowEx �Ĳ���

BOOL CTVWallAXCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("STATIC");
	cs.style = SS_NOTIFY | WS_VISIBLE | WS_CHILD;
	m_hwndParent = cs.hwndParent;
	return COleControl::PreCreateWindow(cs);
}

// CTVWallAXCtrl::IsSubclassedControl - ����һ������ؼ�

BOOL CTVWallAXCtrl::IsSubclassedControl()
{
	return TRUE;
}

// CTVWallAXCtrl::OnOcmCommand - ����������Ϣ

LRESULT CTVWallAXCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO:  �ڴ˽�ͨ wNotifyCode��

	return 0;
}


// CTVWallAXCtrl ��Ϣ�������


int CTVWallAXCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_playerGroup.Create(NULL, _T(""), WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, IDC_PLAYERGROUP);
	//
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;

	CBitmapButton* OneScreen = new CBitmapButton();
	OneScreen->Create(_T("һ"), dwStyle, CRect(0,0,0,0), this, IDC_ONESCREEN);

	CBitmapButton* FourScreen = new CBitmapButton();
	FourScreen->Create(_T("��"), dwStyle, CRect(0, 0, 0, 0), this, IDC_FOURSCREEN);

	CBitmapButton* SixScreen = new CBitmapButton();
	SixScreen->Create(_T("��"), dwStyle, CRect(0, 0, 0, 0), this, IDC_SIXSCREEN);

	CBitmapButton* EightScreen = new CBitmapButton();
	EightScreen->Create(_T("��"), dwStyle, CRect(0, 0, 0, 0), this, IDC_EIGHTSCREEN);

	CBitmapButton* NineScreen = new CBitmapButton();
	NineScreen->Create(_T("��"), dwStyle, CRect(0, 0, 0, 0), this, IDC_NINESCREEN);

	CBitmapButton* SixteenScreen = new CBitmapButton();
	SixteenScreen->Create(_T("ʮ��"), dwStyle, CRect(0, 0, 0, 0), this, IDC_SIXTEENSCREEN);

	CBitmapButton* FullScreen = new CBitmapButton();
	FullScreen->Create(_T("ȫ��"), dwStyle, CRect(0, 0, 0, 0), this, IDC_FULLSCREEN);

	CBitmapButton* ScreenShot = new CBitmapButton();
	ScreenShot->Create(_T("��ͼ"), dwStyle, CRect(0, 0, 0, 0), this, IDC_SCREENSHOT);
	return 0;
}


void CTVWallAXCtrl::SetScreenNum(LONG Num)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������]
	m_playerGroup.SetScreenCount(Num);
}


void CTVWallAXCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//���������ÿͻ���js����
	Invoke(1);
	COleControl::OnLButtonDown(nFlags, point);
}


BOOL CTVWallAXCtrl::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_LBUTTONDOWN){
		/*CWnd*pWnd = FromHandle(pMsg->hwnd);
		::SendMessage(GetParent()->m_hWnd, WM_LBUTTONDOWN, 0, 0);*/
		//return 0;
	}
	return COleControl::PreTranslateMessage(pMsg);
}
void CTVWallAXCtrl::OnScreenBtnClicked(UINT uId){
	int Num = 16;
	switch (uId){
	case IDC_ONESCREEN:
		Num = 1;
		break;
	case IDC_FOURSCREEN:
		Num = 4;
		break;
	case IDC_SIXSCREEN:
		Num = 6;
		break;
	case IDC_EIGHTSCREEN:
		Num = 8;
		break;
	case IDC_NINESCREEN:
		Num = 9;

		break;
	case IDC_SIXTEENSCREEN:
		Num = 16;
		break;

	}
	m_playerGroup.SetScreenCount(Num);
}
void CTVWallAXCtrl::OnFullScreenBtnClicked(){
	
	m_bFullScreenFlag = !m_bFullScreenFlag;
	if (m_bFullScreenFlag)
	{
		MaxiumWindow();
	}
	else
	{
		ResetWindowSize();
	}
}

void CTVWallAXCtrl::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{

	if (::GetParent(m_hWnd) != m_hwndParent)
	{
		CRect rc;
		GetMaxMonitorRect(&rc);
		lpwndpos->cx = rc.Width();
		lpwndpos->cy = rc.Height();
		lpwndpos->x = rc.left;
		lpwndpos->y = rc.top;
	}
	COleControl::OnWindowPosChanging(lpwndpos);

	// TODO:  �ڴ˴������Ϣ����������

}
///< ȡ����ʾ������  
void CTVWallAXCtrl::GetMaxMonitorRect(LPRECT prc)
{
	HMONITOR hMonitor;
	MONITORINFOEX mi;
	RECT rc;
	hMonitor = MonitorFromWindow(m_hWnd, MONITOR_DEFAULTTONEAREST);
	mi.cbSize = sizeof(mi);
	GetMonitorInfo(hMonitor, &mi);
	rc = mi.rcMonitor;
	*prc = rc;
}
///< ��󻯴���  
int CTVWallAXCtrl::MaxiumWindow()
{
	HWND hwnd = GetSafeHwnd();
	RECT rc;
	// ȡ����ʾ���Ŀ���  
	GetMaxMonitorRect(&rc);
	// ���㻭�����  
	int nWidth = rc.right - rc.left;
	int nHeight = rc.bottom - rc.top;
	// ȡ��ԭʼλ�ò�����  
	m_wpPrev.length = sizeof(WINDOWPLACEMENT);
	::GetWindowPlacement(m_hWnd, &m_wpPrev);
	// ����ȫ��  
	SetParent(NULL);
	DWORD dwFlag = SWP_DRAWFRAME;
	BOOL bSucceed = ::SetWindowPos(m_hWnd, HWND_TOPMOST, rc.left, rc.top, nWidth, nHeight, dwFlag);
	return 1;
}
///< �ָ�����  
int CTVWallAXCtrl::ResetWindowSize()
{
	if (NULL != m_hwndParent)
	{
		::SetParent(m_hWnd, m_hwndParent);
		m_wpPrev.flags = SW_SHOWMAXIMIZED;
		::SetWindowPlacement(m_hWnd, &m_wpPrev);
	}
	HWND hWnd = ::FindWindow(_T("Shell_TrayWnd"), NULL);
	HWND hStar = ::FindWindow(_T("Button"), NULL);
	::ShowWindow(hWnd, SW_SHOW);
	::ShowWindow(hStar, SW_SHOW);
	return 1;
}
void CTVWallAXCtrl::OnScreenShotBtnClicked(){
	m_playerGroup.SavePicture();
}
//
void f(void*r){

	CTVWallAXCtrl*p = (CTVWallAXCtrl*)r;
	Sleep(5000);
	p->m_a += 10;
	PostMessage(p->m_hWnd, WM_THREADFIREEVENT, (WPARAM)NULL, (LPARAM)NULL);
	return;
}
// ���Ժ���
void CTVWallAXCtrl::Invoke(short a)
{
	m_a = a;
	_beginthread(f, 0, (void*)this);
}
//�����¼�������
LRESULT CTVWallAXCtrl::OnFireEventForThread(WPARAM wParam, LPARAM lParam)
{
	this->calljs(m_a);
	return TRUE;
}