#pragma once
#include"Player.h"
// TVWallAXCtrl.h : CTVWallAXCtrl ActiveX �ؼ����������


// CTVWallAXCtrl : �й�ʵ�ֵ���Ϣ������� TVWallAXCtrl.cpp��

class CTVWallAXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CTVWallAXCtrl)

// ���캯��
public:
	CTVWallAXCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();

// ʵ��
protected:
	~CTVWallAXCtrl();

	DECLARE_OLECREATE_EX(CTVWallAXCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CTVWallAXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CTVWallAXCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CTVWallAXCtrl)		// �������ƺ�����״̬

	// ����ؼ�֧��
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
	};
	CPlayer m_playerTest;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

