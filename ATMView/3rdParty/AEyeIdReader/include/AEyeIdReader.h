#ifndef AEYEIDREADER_H
#define AEYEIDREADER_H

#include "aeyeidreader_global.h"

typedef struct _AEIdCardInfo
{
	char name[50];		 //����     
	char sex[10];		 //�Ա�
	char nation[10];     //����
	char birthday[30];      //��������
	char address[100];	 //סַ	
	char idNumber[50];	 //���֤��	
	char grantDept[50];  //��֤����
	char startDate[30];	 //��Ч��ʼ����
	char endDate[30];	 //��Ч��ֹ����
	char reserved[38];	 //����
	char photoPath[255]; //��Ƭ·��
}AEIdCardInfo;

class AEYEIDREADER_EXPORT AEyeIdReader
{
public:
	AEyeIdReader();
	~AEyeIdReader();

	virtual int AEyeIdReader_ReadBaseMsg(AEIdCardInfo* cardInfo);
	virtual int AEyeIdReader_Read(char* pName, char* pCertNo);
};

extern "C" {
	AEYEIDREADER_EXPORT AEyeIdReader* getDllObj();
};

#endif // AEYEIDREADER_H
