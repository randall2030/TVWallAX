#pragma once


// CPlayerItem

class CPlayerItem : public CWnd
{
	DECLARE_DYNAMIC(CPlayerItem)

public:
	CPlayerItem();
	virtual ~CPlayerItem();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	// ��ͼ����
	void SavePicture();
	CString saveFilePath;
	// ����ʵʱ��Ƶ
	long StartRealPlay(long connectionId, CString cameraId);
	// ��ǰ�Ự
	long m_nSessionID;
	// ���ID
	CString m_strCameraID;
	// ֹͣʵʱ����
	long StopRealPlay();
	// ��ʼ����¼��
	long StartLocalRecord();
	// ¼��״̬
	bool m_bVideoStart;
};


