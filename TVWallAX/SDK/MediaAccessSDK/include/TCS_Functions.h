#ifndef _TCS_FUNCTIONS_H_
#define _TCS_FUNCTIONS_H_

#ifdef __cplusplus
#define CEXTERN extern "C"
#else
#define CEXTERN
#endif

#ifdef  TERRAVISIONSDK_EXPORTS
#define DLLEXPORT CEXTERN __declspec(dllexport)
#else
#define DLLEXPORT CEXTERN __declspec(dllimport)
#endif

#define STDCALL __stdcall


#include "TCS_CommonData.h"

/**
* @brief ��ʼ��DLL
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_Init();

/**
* @brief �˳�DLL
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_UnInit();

/**
* @brief ��¼������
* @author xty ligd
* @date  2017/3/20
* @param LOGININFO:��½��Ϣ
* @return �ɹ� ����ID
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_Login(PlatformId pt, LOGININFO* pInfo);

/**
* @brief �ǳ�������
* @author xty ligd
* @date  2017/1/19
* @param coid : ����ID
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_Logout(int connectId);

/**
* @brief
* @author xty ligd
* @date  2017/3/20
* @param minsNo: ������
		 pMins: �������[0/1...]
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention �������������0 or 1
* @Modified
**/
DLLEXPORT int STDCALL TCS_RecordSearch(int connectId,
	const char* cameraId, __int64 beginTime, int minsNo, char* pMins);

/**
* @brief ����һ·ʵʱ��Ƶ
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� SessionId
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_StartRealPlay(int connectId, const char* cameraId,
	StreamType streamType, MEDIADATA_CALLBACK func, void* pUserData);

/**
* @brief �ر�һ·ʵʱ��Ƶ
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_StopRealPlay(int sessionId);

/**
* @brief ��ͣһ·ʵʱ��Ƶ
* @author ligd
* @date  2018/8/28
* @param
* @return �ɹ� TCSResult::Success
          ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_PauseRealPlay(int sessionId);

/**
* @brief �̳�һ·ʵʱ��Ƶ
* @author ligd
* @date  2018/8/28
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_ContinueRealPlay(int sessionId);

/**
* @brief ¼��ط�
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� SessionId
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_StartPlayback(int connectId, const char* cameraId,
	StreamType streamType, __int64 beginTime, __int64 endTime,
	MEDIADATA_CALLBACK func, void* pUserData);

/**
* @brief ֹͣ¼��ط�
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_StopPlayback(int sessionId);

/**
* @brief ��ͣ¼��ط�
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_PausePlay(int sessionId);

/**
* @brief ����¼��ط�
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_ContiuePlay(int sessionId);

/**
* @brief ����¼�񲥷��ٶ�
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_SetPlaySpeed(int sessionId, PLAY_SPEED speed);

/**
* @brief ����¼�񲥷�˳��
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_SetPlaySequence(int sessionId, PlaySequence playType);

/**
* @brief ¼�񲥷�ʱ��ת
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_SkipPlay(int sessionId, __int64 timestamp);

/**
* @brief  ��ʼ¼������
* @author xty ligd
* @date  2017/3/20
* @param pathName : �ļ�ȫ·��
* @return �ɹ� SessionId
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_StartDownload(int connectId, const char* cameraId,
	const char* pathName, __int64 begTime, __int64 endTime,
	StreamType streamType);

/**
* @brief ֹͣ¼������
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_StopDownload(int sessionId);

/**
* @brief  ��ȡ¼�����ؽ���
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� ���ؽ��ȣ�0-100��
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_GetDownloadProgress(int sessionId);

/**
* @brief  ��ʼ����¼��
* @author xty ligd
* @date  2017/3/20
* @param pathName : �ļ�ȫ·��
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_StartLocalRecord(int sessionId, const char* pathName);

/**
* @brief  ֹͣ����¼��
* @author xty ligd
* @date  2017/3/20
* @param
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_StopLocalRecord(int sessionId);

/**
* @brief ��̨�ƶ�����
* @author xty ligd
* @date  2017/3/20
* @param
	connectId	: ����ID����TCS_Login�ķ���ֵ
	cameraId	: ���ID
	op			: PTZ����, ��TCS_PTZMoveOp
	speed		: �ٶ�ֵ��1-10��
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_PTZControl(int connectId, const char* cameraId, TCS_PTZMoveOp op, int speed);

/**
* @brief ��̨Ԥ��λ����
* @author xty ligd
* @date  2017/3/20
* @param
	connectId	: ����ID����TCS_Login�ķ���ֵ
	cameraId	: ���ID
	id			: Ԥ��λID
	name		: Ԥ��λ�����ƣ���Ҫ����20�ַ���
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_PresetSet(int connectId, const char* cameraId, int id, const char* name);

/**
* @brief ��̨Ԥ��λ����
* @author xty ligd
* @date  2017/1/18
* @param
	connectId	: ����ID����TCS_Login�ķ���ֵ
	cameraId	: ���ID
	id			: Ԥ��λID
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_PresetCall(int connectId, const char* cameraId, int id);

/**
* @brief ��̨Ԥ��λɾ��
* @author xty ligd
* @date  2017/1/18
* @param
	connectId	: ����ID����TCS_Login�ķ���ֵ
	cameraId	: ���ID
	id			: Ԥ��λID
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_PresetDel(int connectId, const char* cameraId, int id);

/**
* @brief ��ȡ�豸�б������
* @author xty
* @date  2017/3/3
* @param
* @return �ɹ� �����
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_GetCameraAmount(int connectId);

/**
* @brief ��ȡ�豸�б�
* @author xty ligd
* @date  2017/1/19
* @param
	connectId : ����ID
	CameraInfo : �ڴ���
	cameraAmount : �ڴ�������
* @return �ɹ� TCSResult::Success
		  ʧ�� TCSResult::Failed
		  ���TCS_GetLastError
* @attention
* @Modified
**/
DLLEXPORT int STDCALL TCS_GetCameraList(int connectId, CameraInfo* pCameras, int cameraAmount);

/**
* @brief ��ȡ֧�ֵ�ƽ̨��Ϣ
* @author xty ligd
* @date  2017/1/16
* @param
* @return �ο�PlatformInfoSet����
* @attention
* @Modified
**/
DLLEXPORT PlatformInfoSet STDCALL TCS_GetSupportedPlatform();

/**
* @brief ��ȡ������
* @author xty ligd
* @date  2017/1/16
* @param
* @return �ο�TCSErrorCode����
* @attention
* @Modified
**/
DLLEXPORT TCSErrorCode STDCALL TCS_GetLastError();

#endif