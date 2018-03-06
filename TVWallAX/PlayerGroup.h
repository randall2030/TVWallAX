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
	int m_nCount;
	CRect m_rcWnd[16];
	CRect m_rcWndMax;
	CPlayer m_player[16];
	int m_nActivePlayer;
	
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
};


