// PlayerItem.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TVWallAX.h"
#include "PlayerItem.h"


// CPlayerItem

IMPLEMENT_DYNAMIC(CPlayerItem, CWnd)

CPlayerItem::CPlayerItem()
{
	saveFilePath = _T("C:\\Capture\\");
}

CPlayerItem::~CPlayerItem()
{
}


BEGIN_MESSAGE_MAP(CPlayerItem, CWnd)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CPlayerItem ��Ϣ�������




BOOL CPlayerItem::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rcWindow;
	GetWindowRect(&rcWindow);
	rcWindow.OffsetRect(-rcWindow.TopLeft());
	pDC->FillSolidRect(&rcWindow,RGB(120,120,120));
	CString str;
	str.Format(_T("%d"),this->GetDlgCtrlID()-IDC_PLAYERITEM+1);
	pDC->DrawText(str, rcWindow, DT_SINGLELINE | DT_VCENTER|DT_CENTER);
	return true;
	//return CWnd::OnEraseBkgnd(pDC);
}


void CPlayerItem::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
}


void CPlayerItem::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//::SendMessage(GetParent()->m_hWnd, WM_LBUTTONDOWN, 0, 0);
	CWnd::OnLButtonDown(nFlags, point);
}


BOOL CPlayerItem::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_LBUTTONDOWN){
		
		::SendMessage(GetParent()->m_hWnd, WM_LBUTTONDOWN, 0, 0);
	}
	if (pMsg->message == WM_LBUTTONDBLCLK){
		
		::SendMessage(GetParent()->m_hWnd,WM_LBUTTONDBLCLK,0,0);
	}
	return CWnd::PreTranslateMessage(pMsg);
}


// ��ͼ����
void CPlayerItem::SavePicture()
{
	CClientDC dc(this);
	CRect rect;
	//BOOL  showMsgTag;                  //�Ƿ�Ҫ������ͼ�񱣴�ɹ��Ի���"   
	GetClientRect(&rect);                  //��ȡ������С  
	HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
	//��������λͼ  
	HDC hdc = CreateCompatibleDC(dc);      //��������DC���Ա㽫ͼ�񱣴�Ϊ��ͬ�ĸ�ʽ  
	HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap);
	//��λͼѡ��DC�������淵��ֵ   
	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0, SRCCOPY);
	//����ĻDC��ͼ���Ƶ��ڴ�DC��  
	ATL::CImage image;
	image.Attach(hbitmap);                //��λͼת��Ϊһ��ͼ��  

	CString  strFilter = _T("λͼ�ļ�(*.bmp)|*.bmp|JPEG ͼ���ļ�|*.jpg|GIFͼ���ļ� | *.gif | PNGͼ���ļ� | *.png |������ʽ(*.*) | *.* || ");  
	CFileDialog dlg(FALSE, _T("bmp"), _T("unknown.bmp"), NULL, strFilter);
	if (dlg.DoModal() != IDOK)
		return;
	CString strFileName;          //����û�û��ָ���ļ���չ������Ϊ�����һ��  
	CString strExtension;
	strFileName = dlg.m_ofn.lpstrFile;

	if (dlg.m_ofn.nFileExtension = 0)               //��չ����ĿΪ0  
	{
		switch (dlg.m_ofn.nFilterIndex)
		{
		case 1:
			strExtension = "bmp"; break;
		case 2:
			strExtension = "jpg"; break;
		case 3:
			strExtension = "gif"; break;
		case 4:
			strExtension = "png"; break;
		default:
			break;
		}
		strFileName = strFileName +_T( ".") + strExtension;

	}

	saveFilePath = strFileName;     //saveFilePathΪ�����е�ȫ�ֱ���,����ΪCString  
	//AfxMessageBox(saveFilePath); //��ʾͼ�񱣴��ȫ·��(�����ļ���)  

	HRESULT hResult = image.Save(saveFilePath);     //����ͼ��  
	if (FAILED(hResult))
	{
		MessageBox(_T("����ͼ���ļ�ʧ�ܣ�"),_T("��ʾ"));

	}
	else
	{
		MessageBox(_T("�ļ�����ɹ���"),_T("��ʾ"));

	}
	image.Detach();
	SelectObject(hdc, hOldMap);
}
