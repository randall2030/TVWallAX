#pragma once


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
	// ���Ʊ�
	void DrawEdge(CDC* dc);
	//
	CRect rcWnd;
};


