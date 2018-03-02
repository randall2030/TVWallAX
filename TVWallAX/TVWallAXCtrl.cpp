// TVWallAXCtrl.cpp : CTVWallAXCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "TVWallAX.h"
#include "TVWallAXCtrl.h"
#include "TVWallAXPropPage.h"
#include "afxdialogex.h"

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
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CTVWallAXCtrl, COleControl)
	DISP_FUNCTION_ID(CTVWallAXCtrl, "SetScreenNum", dispidSetScreenNum, SetScreenNum, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CTVWallAXCtrl, COleControl)
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
{
	InitializeIIDs(&IID_DTVWallAX, &IID_DTVWallAXEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
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

	pdc->FillSolidRect(rcBounds,RGB(0,255,255));

	if (m_playerGroup)
	{
		CRect rect = rcBounds;
		rect.DeflateRect(0, 0, 0, 50);
		m_playerGroup.MoveWindow(rect, true);///2
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
	//cs.lpszClass = _T("STATIC");
	//cs.style = SS_NOTIFY | WS_VISIBLE | WS_CHILD;
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

	COleControl::OnLButtonDown(nFlags, point);
}


BOOL CTVWallAXCtrl::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_LBUTTONDOWN){
		/*CWnd*pWnd = FromHandle(pMsg->hwnd);
		::SendMessage(GetParent()->m_hWnd, WM_LBUTTONDOWN, 0, 0);*/
		return 0;
	}
	return COleControl::PreTranslateMessage(pMsg);
}
