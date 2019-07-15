#ifndef READIDCARDTHREAD_H
#define READIDCARDTHREAD_H

#include <QObject>
#include <QThread>
#include <QLibrary>

#include "HttpStructData.h"
#include "EnumData.h"
#include "AEyeIdReader.h"

typedef AEyeIdReader* (*getObj)();

class ReadIdCardThread : public QThread
{
	Q_OBJECT

public:
    ReadIdCardThread(QObject *parent);
    ~ReadIdCardThread();

protected:
	//��ʼ����
    int readIdCard();
	//�߳�����
	virtual void run();

private:
    void loadDLL();

signals:
	//�����ɹ�
    void readIdCardSuccessed(AuthReadCardResult readCardResult);
    //����ʧ��
    void readIdCardFailed(int errCode);

private:
	AuthReadCardResult m_readCardResult;
    AEyeIdReader* m_idReader;
};

#endif // READIDCARDTHREAD_H
