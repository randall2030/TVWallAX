#pragma once

// TVWallAXPropPage.h : CTVWallAXPropPage ����ҳ���������


// CTVWallAXPropPage : �й�ʵ�ֵ���Ϣ������� TVWallAXPropPage.cpp��

class CTVWallAXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTVWallAXPropPage)
	DECLARE_OLECREATE_EX(CTVWallAXPropPage)

// ���캯��
public:
	CTVWallAXPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_TVWALLAX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

