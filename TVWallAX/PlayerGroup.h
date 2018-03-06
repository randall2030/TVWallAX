#pragma once
#include"Player.h"

// CPlayerGroup

class CPlayerGroup : public CWnd
{
	DECLARE_DYNAMIC(CPlayerGroup)

public:
	CPlayerGroup();
	virtual ~CPlayerGroup();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void RecalWndPos();
private:
	int m_nplayWindowCount;
	//!������Ŀ
	int m_nCount;
	CRect m_rcWnd[16];
	CRect m_rcWndMax;
	CPlayer m_player[16];
	int m_nActivePlayer;
	//!����ID
	int m_nConnectionID;
	
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	// ���÷���
	void SetScreenCount(int nCount);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	
	// ��ͼ
	void SavePicture();
	// ����ʵʱ��Ƶ
	long StartRealPlay(long connectionID, CString cameraId);
	// ֹͣʵʱ���
	long StopRealPlay();
	// ¼��
	long StartLocalRecord();
	// ��ȡ������Ŀ
	long GetScreenCount();
	//�ַ����ָ�
	void StringSplit(CString source, CStringArray& dest, char division);
	//����б�
	CStringArray m_strArrCameras;
	//�ֲ����
	int m_nPlayBatchTime;
	// �����ֲ�ʱ��
	void SetInterval(long  millisecond);
	//
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	// ��ʼ�ֲ�
	void StartBatchPlay(int connectionID);
	// ��������б�
	void SetCamerasIDS(CString camerasIds);
	// ֹͣ�ֲ�
	void StopPlayBatch();
	// �ֲ�
	void BatchPlay(int connectionID);
	// ��������ID
	void SetConnectionID(int connectionID);
	// �����һ���ֲ�������
	int m_nCurrentIndex;
};


