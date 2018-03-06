#pragma once
#include"PlayerItem.h"

// CPlayer

class CPlayer : public CWnd
{
	DECLARE_DYNAMIC(CPlayer)

public:
	CPlayer();
	virtual ~CPlayer();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//BOOL   RegisterWindowClass(HINSTANCE hInstance = NULL);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//!ԭ�еĴ�С
	CRect rcWnd;
protected:
	//! ѡ��״̬
	bool m_bSelected;
	//! ���Ʊ߿�
	void DrawEdge(CDC* dc);
	
	//
	//!δѡ�б߿���ɫ
	COLORREF m_edgeColor;
	//!ѡ�б߿���ɫ
	COLORREF m_edgeSelColor;
	//!���ſؼ�
	CPlayerItem m_playerItem;
public:
	void SetSelected(bool Selected);
protected:
	// �Ƿ������״̬
	bool m_bIsMaxsize;
public:
	// ��ȡ���״̬
	bool GetMaxSizeStatus();
	// �������״̬
	void SetMaxSizeStatus(bool bMaxSize);
	void SavePicture();
	bool GetSelectedStatus();
	// ����ʵʱ����
	long StartRealPlay(long connectionID, CString cameraId);
};


