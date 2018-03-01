// TVWallAXPropPage.cpp : CTVWallAXPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "TVWallAX.h"
#include "TVWallAXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CTVWallAXPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CTVWallAXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CTVWallAXPropPage, "TVWALLAX.TVWallAXPropPage.1",
	0x8a6d9234, 0x171a, 0x4b37, 0x95, 0x2e, 0x26, 0x59, 0x82, 0x95, 0x2e, 0xed)

// CTVWallAXPropPage::CTVWallAXPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CTVWallAXPropPage ��ϵͳע�����

BOOL CTVWallAXPropPage::CTVWallAXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TVWALLAX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CTVWallAXPropPage::CTVWallAXPropPage - ���캯��

CTVWallAXPropPage::CTVWallAXPropPage() :
	COlePropertyPage(IDD, IDS_TVWALLAX_PPG_CAPTION)
{
}

// CTVWallAXPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CTVWallAXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CTVWallAXPropPage ��Ϣ�������
