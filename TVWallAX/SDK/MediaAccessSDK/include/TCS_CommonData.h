#ifndef TCS_COMMONDATA_H
#define TCS_COMMONDATA_H

#pragma pack(push,1) 

#define MAX_STRINGLEN 64	//������ID����
#define MAX_PLATFOMRCNT 64	//���֧��ƽ̨����

//�ײ���������
typedef enum _SocketType
{
	TCS_UDP = 0,
	TCS_TCP
}SocketType;

//ƽ̨����
typedef int PlatformId;

//ƽ̨��Ϣ�ṹ
typedef struct _PlatformInfo
{
	PlatformId id;
	char description[128];
}PlatformInfo;

//ƽ̨��Ϣ����
typedef struct _PlatformInfoSet
{
	unsigned cnt;							//ƽ̨����
	PlatformInfo infos[MAX_PLATFOMRCNT];	//ƽ̨��Ϣ����
}PlatformInfoSet;

//����˳��
typedef enum _PlaySequence
{
	SequencePlay = 0,	//˳�򲥷�
	RewindPlay,			//���򲥷�
}PlaySequence;

//��������
typedef enum _StreamType
{
	MainStream = 0, 
	SubStream
}StreamType;

//PTZ�ƶ���������
typedef enum _TCS_PTZ_
{
	PTZCTL_UP =0,				/** �� */
	PTZCTL_DOWN ,				/** �� */
	PTZCTL_RIGHT ,				/** �� */
	PTZCTL_LEFT ,				/** ��*/
	PTZCTL_IRIS_OPEN ,			/** ��Ȧ�� */
	PTZCTL_IRIS_CLOSE ,			/** ��Ȧ��*/
	PTZCTL_ZOOM_WIDE ,			/** ��Զ*/
	PTZCTL_ZOOM_TELE ,			/** ����*/
	PTZCTL_FOCUS_NEAR ,			/** ����*/
	PTZCTL_FOCUS_FAR ,			/** Զ��*/
	PTZCTL_STOP ,				/** ֹͣ*/
}TCS_PTZMoveOp;

//�����ٶȶ���
typedef enum _PLAY_SPEED_
{
	SPEED_1X = 0,
	FAST_2X, 
	FAST_4X, 
	FAST_8X, 
	FAST_16X, 
	SLOW_2X, 
	SLOW_4X, 
	SLOW_8X, 
	SLOW_16X,
}PLAY_SPEED;

//���ӻص������������Ͷ���
typedef enum _ConnectionNotifyType
{
	STATE_DISCONNECT = 0,
} ConnectionNotifyType;

//���ӻص���������
typedef struct _ConnectionNotify
{
	ConnectionNotifyType type;
} ConnectionNotify;

//���ӻص���������
typedef void(*CONNECTION_CALLBACK)(int connectionId, ConnectionNotify data, void* pUserData);

//���ӻص��ṹ
typedef struct _ConnectionCallback
{
	CONNECTION_CALLBACK m_func;
	void* pUserData;
} ConnectionCallback;

//��½��Ϣ
typedef struct _LoginInfo
{
	const char* ip;
	unsigned short port;
	const char* username;
	const char* password; 
	SocketType st;
	ConnectionCallback callback;
}LOGININFO, *PLOGININFO;

//��ѯ¼��Ľ���ṹ(��������)
#define MAX_QUERY_MINITES 1440
typedef struct _QUERY_RECORD_RESULT
{
	unsigned int nNum;					/*��������(the length of records)*/
	char records[MAX_QUERY_MINITES];	/*ÿ���ֽڱ�ʾһ���ӣ�0��ʾû����Ƶ��1��ʾ����Ƶ*/
}QUERY_RECORD_RESULT;

//ý�������ݰ�
typedef struct _MediaData
{
	int errorcode;		//0 ������1 �쳣����
	int imageWidth;		//ͼ���
	int imageHeight;	//ͼ���
	int yStride;		//���(ͬlinesize)
	void* yData;		//Y��������
	void* uData;		//U��������
	void* vData;		//V��������
	__int64 timestamp;	//ʱ���(����)
}MediaData;

//�����Ϣ
typedef struct _CameraInfo
{
	char cameraId[MAX_STRINGLEN];	//�����ʶ
	char name[MAX_STRINGLEN];		//�������
	char ip[MAX_STRINGLEN];			//IP��ַ
	char firm[MAX_STRINGLEN];		//����
	char model[MAX_STRINGLEN];		//�ͺ�
	unsigned char enabled;			//�Ƿ���� 0�� 1�� ����δ֪
	unsigned char bPTZ;				//�ܷ����PTZ���� 0�� 1�� ����δ֪
}CameraInfo;


//ý�����ص���������
typedef void(*MEDIADATA_CALLBACK)(int sessionId, MediaData* data, void* pUserData);

//������
typedef enum _TCSErrorCode
{
	OK = 0,						//�ɹ�
	SystemError,				//ϵͳ���صĴ���
	InvalidConnection,			//��Ч����
	ConfigFileError,			//�����ļ�����
	InvalidSession,				//��Чsession
	StatusError,				//״̬����
	ParamError,					//��������
	PlatformNotSupport = 101,	//ƽ̨��֧��
	InvalidCamera,				//��ЧCamera
	ExecFaild,					//ִ��ʧ��
	FilePathError,				//·������
	PlatformError				//ƽ̨�����Ĵ���
}TCSErrorCode;

enum TCSResult
{
	Success = 0,
	Failed = -1
};

//������Ϣ
typedef struct _TrError_
{
	TCSErrorCode error_code;	//������
	const char* error_msg;		//��������
}TrError;


#pragma pack(pop)

#endif