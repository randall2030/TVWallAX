// PlayerItem.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TVWallAX.h"
#include "PlayerItem.h"
#include "TCS_CommonData.h"
#include "TCS_Functions.h"

///�ⲿ����
//!��Ƶ���Żص�����
void CallBackMediaFunc(int sessionId, MediaData* data, void* pUserData);
//!YUV ת��ΪRGB
bool CONVERT_YUV420PtoRGB24(unsigned char* yuv_y, unsigned char* yuv_u, unsigned char* yuv_v, 
	unsigned char* rgb_dst, int nWidth, int nHeight);

void CallBackMediaFunc(int sessionId, MediaData* data, void* pUserData){
	if (data->errorcode == 0){

		char*pBGR24 = (char *)malloc(data->imageWidth*data->imageHeight * 3);
		//Ϊͼ����������ռ�  
		//str.Format("%s",data->yStride);
		//YV12ToBGR24_Native((char*)data->yData,(char*)data->vData,(char*)data->uData,pBGR24,data->imageWidth,data->imageHeight)
		if (CONVERT_YUV420PtoRGB24((unsigned char*)data->yData, (unsigned char*)data->vData, (unsigned char*)data->uData, (unsigned char*)pBGR24, data->imageWidth, data->imageHeight)){
			//��ʾͼ��  
			//BMP Header  
			BITMAPINFO m_bmphdr = { 0 };
			DWORD dwBmpHdr = sizeof(BITMAPINFO);
			m_bmphdr.bmiHeader.biBitCount = 24;
			m_bmphdr.bmiHeader.biClrImportant = 0;
			m_bmphdr.bmiHeader.biSize = dwBmpHdr;
			m_bmphdr.bmiHeader.biSizeImage = 0;
			m_bmphdr.bmiHeader.biWidth = data->imageWidth;
			//ע��BMP��y�����Ƿ��Ŵ洢�ģ�һ�α�������һ����ֵ������ʹͼ��������ʾ����  
			m_bmphdr.bmiHeader.biHeight = -data->imageHeight;
			m_bmphdr.bmiHeader.biXPelsPerMeter = 0;
			m_bmphdr.bmiHeader.biYPelsPerMeter = 0;
			m_bmphdr.bmiHeader.biClrUsed = 0;
			m_bmphdr.bmiHeader.biPlanes = 1;
			m_bmphdr.bmiHeader.biCompression = BI_RGB;
			//���ݴ���
			
			CWnd* pWnd;
			pWnd = CWnd::FromHandle((HWND)pUserData);
			
			if (pWnd){
				CRect rect;
				pWnd->GetClientRect(&rect);
				if (rect.Width()>0 && rect.Height()>0){
					//�쳣�ж�
					CDC *pDC = pWnd->GetDC();
					
					//pDC->Ellipse(rect);
					pDC->SetStretchBltMode(COLORONCOLOR);
					StretchDIBits(pDC->GetSafeHdc(), rect.left, rect.top, rect.Width(), rect.Height(), 0, 0,
						data->imageWidth, data->imageHeight, pBGR24, &m_bmphdr, DIB_RGB_COLORS, SRCCOPY);
					ReleaseDC(pWnd->m_hWnd, pDC->m_hDC);
				}
			}
		}
		//
		delete[] pBGR24;
		pBGR24 = NULL;
	}

}

inline unsigned char CONVERT_ADJUST(double tmp)
{
	return (unsigned char)((tmp >= 0 && tmp <= 255) ? tmp : (tmp < 0 ? 0 : 255));
}

bool CONVERT_YUV420PtoRGB24(unsigned char* yuv_y, unsigned char* yuv_u, unsigned char* yuv_v, unsigned char* rgb_dst, int nWidth, int nHeight)
{
	if (nWidth < 1 || nHeight < 1 || yuv_y == NULL || yuv_u == NULL || yuv_v == NULL || rgb_dst == NULL)
		return false;
	unsigned char *tmpbuf = (unsigned char *)malloc(nWidth*nHeight * 3);
	unsigned char Y, U, V, R, G, B;
	unsigned char* y_planar, *u_planar, *v_planar;
	int rgb_width, u_width;
	rgb_width = nWidth * 3;
	u_width = (nWidth >> 1);
	int ypSize = nWidth * nHeight;
	int upSize = (ypSize >> 2);
	int offSet = 0;

	y_planar = yuv_y;
	u_planar = yuv_u;
	v_planar = yuv_v;


	for (int i = 0; i < nHeight; i++)
	{
		for (int j = 0; j < nWidth; j++)
		{
			// Get the Y value from the y planar
			// Get the Y value from the y planar
			Y = *(y_planar + nWidth * i + j);
			// Get the V value from the u planar
			offSet = (i >> 1) * (u_width)+(j >> 1);
			V = *(u_planar + offSet);
			// Get the U value from the v planar
			U = *(v_planar + offSet);

			// Cacular the R,G,B values
			// Method 1
			R = CONVERT_ADJUST((Y + (1.4075 * (V - 128))));
			G = CONVERT_ADJUST((Y - (0.3455 * (U - 128) + 0.7169 * (V - 128))));
			B = CONVERT_ADJUST((Y + (1.7790 * (U - 128))));
			/*
			// The following formulas are from MicroSoft' MSDN
			int C,D,E;
			// Method 2
			C = Y - 16;
			D = U - 128;
			E = V - 128;
			R = CONVERT_ADJUST(( 298 * C + 409 * E + 128) >> 8);
			G = CONVERT_ADJUST(( 298 * C - 100 * D - 208 * E + 128) >> 8);
			B = CONVERT_ADJUST(( 298 * C + 516 * D + 128) >> 8);
			R = ((R - 128) * .6 + 128 )>255?255:(R - 128) * .6 + 128;
			G = ((G - 128) * .6 + 128 )>255?255:(G - 128) * .6 + 128;
			B = ((B - 128) * .6 + 128 )>255?255:(B - 128) * .6 + 128;
			*/

			offSet = rgb_width * i + j * 3;

			rgb_dst[offSet] = B;
			rgb_dst[offSet + 1] = G;
			rgb_dst[offSet + 2] = R;
		}
	}
	free(tmpbuf);
	return true;
}

// CPlayerItem

IMPLEMENT_DYNAMIC(CPlayerItem, CWnd)

CPlayerItem::CPlayerItem()
: m_nSessionID(-1)
, m_strCameraID(_T(""))
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


// ����ʵʱ��Ƶ
long CPlayerItem::StartRealPlay(long connectionId, CString cameraId)
{
	if (m_nSessionID <0)
	{
		//��¼���ID
		m_strCameraID = cameraId;
		//��������
		m_nSessionID = TCS_StartRealPlay(connectionId, cameraId,
			MainStream, CallBackMediaFunc, this->GetSafeHwnd());
	}
	else{
		//�ر���ǰ��
		TCS_StopRealPlay(m_nSessionID);
	}
	return m_nSessionID;
}
