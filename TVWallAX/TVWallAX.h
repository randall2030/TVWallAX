#pragma once

// TVWallAX.h : TVWallAX.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������


// CTVWallAXApp : �й�ʵ�ֵ���Ϣ������� TVWallAX.cpp��

class CTVWallAXApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
	static LRESULT CALLBACK GetMessageProc(int nCode, WPARAM wParam, LPARAM lParam);
	HHOOK m_hHook;
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

