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
protected:
	//! ѡ��״̬
	bool m_bSelected;
	//! ���Ʊ߿�
	void DrawEdge(CDC* dc);
	//
	CRect rcWnd;
	//
	//!δѡ�б߿���ɫ
	COLORREF m_edgeColor;
	//!ѡ�б߿���ɫ
	COLORREF m_edgeSelColor;
	//!���ſؼ�
	CPlayerItem m_playerItem;
public:
	void SetSelected(bool Selected);
};


