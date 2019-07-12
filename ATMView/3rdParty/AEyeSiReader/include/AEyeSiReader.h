#ifndef AEYESIREADER_H
#define AEYESIREADER_H

#include "aeyesireader_global.h"

typedef struct _AESsCardOrgInfo
{
	char cardId[256];     //��ʶ����
	char cardType[256];   //�����
	char version[256];    //�淶�汾
	char orgNumber[256];  //��ʼ���������
	char issueDate[256];  //��������
	char validity[256];   //����Ч��
	char cardNumber[256]; //����
} AESsCardOrgInfo;

typedef struct _AESsCardPersonInfo
{
	char ssNumber[256];  //��ᱣ�Ϻ���
	char name[256];      //����
	char nameExt[256];   //������չ
	char sex[256];       //�Ա�
	char nation[256];    //����
	char birthland[256]; //������
	char birthday[256];  //��������
} AESsCardPersonInfo;

class AEYESIREADER_EXPORT AEyeSiReader
{
public:
	AEyeSiReader();
	~AEyeSiReader();

    virtual int AEyeSiReader_ReadOrgInfo(AESsCardOrgInfo* orgInfo);
	virtual int AEyeSiReader_ReadPersonInfo(AESsCardPersonInfo* personInfo);
	virtual int AEyeSiReader_ChangePin(char* oldPin, char* newPin);
	virtual int AEyeSiReader_VerifyPin(char* pin);
};

extern "C" {
	AEYESIREADER_EXPORT AEyeSiReader* getDllObj();
};

#endif // AEYESIREADER_H
