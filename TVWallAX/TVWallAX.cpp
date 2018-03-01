// TVWallAX.cpp : CTVWallAXApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "TVWallAX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CTVWallAXApp theApp;

const GUID CDECL _tlid = { 0xB03F7467, 0xA270, 0x461D, { 0x95, 0x7D, 0x50, 0x39, 0x2D, 0xB5, 0x2C, 0xFA } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CTVWallAXApp::InitInstance - DLL ��ʼ��

BOOL CTVWallAXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CTVWallAXApp::ExitInstance - DLL ��ֹ

int CTVWallAXApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
