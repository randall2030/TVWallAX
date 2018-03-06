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
		dispidStartLocalRecord = 16L,
		dispidStopRealPlay = 15L,
		dispidStartRealPlay = 14L,
		dispidGetCameraList = 13L,
		dispidGetSupportedPlatform = 12L,
		dispidLogout = 11L,
		dispidLogin = 10L,
		dispidPlatformID = 9,
		dispidSocketType = 8,
		dispidPort = 7,
		dispidPassWd = 6,
		dispidUserName = 5,
		dispidIP = 4,
		dispidUnInit = 3L,
		dispidInit = 2L,
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
	//! shot
	void OnScreenShotBtnClicked();
	//!videoRecord
	void OnVideoRecordBtnClicked();
	//!
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	///< ȡ����ʾ������
	void GetMaxMonitorRect(LPRECT prc);
	///< ��󻯴���
	int MaxiumWindow();
	///< �ָ�����
	int ResetWindowSize();
protected:
	LONG Init();
	LONG UnInit();
	void OnIPChanged();
	CString m_strIP;
	void OnUserNameChanged();
	CString m_strUserName;
	void OnPassWdChanged();
	CString m_strPassWd;
	void OnPortChanged();
	LONG m_nPort;
	void OnSocketTypeChanged();
	LONG m_nSocketType;
	void OnPlatformIDChanged();
	LONG m_nPlatformID;
	LONG Login();
	LONG Logout();
	LONG m_nConnectionID;
	BSTR GetSupportedPlatform();
	BSTR GetCameraList();
	LONG StartRealPlay(LPCTSTR cameraId);
	LONG StopRealPlay();
	LONG StartLocalRecord();
};

