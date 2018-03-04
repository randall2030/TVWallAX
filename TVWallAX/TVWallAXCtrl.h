#pragma once
#include"PlayerGroup.h"
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
		dispidSetScreenNum = 1L
	};
	//
	CPlayerGroup m_playerGroup;
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);


protected:
	void SetScreenNum(LONG Num);
	//---- window fullscreen and normal
	BOOL m_bFullScreenFlag;
	WINDOWPLACEMENT m_wpPrev;
	HWND m_hwndParent;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//!������Ӧ����
	void OnScreenBtnClicked(UINT uId);
	//��full screen
	void OnFullScreenBtnClicked();
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	///< ȡ����ʾ������
	void GetMaxMonitorRect(LPRECT prc);
	///< ��󻯴���
	int MaxiumWindow();
	///< �ָ�����
	int ResetWindowSize();
};

