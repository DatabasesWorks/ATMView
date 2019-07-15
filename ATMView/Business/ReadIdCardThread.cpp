/***********************************************************************************
*								ReadCardThread.cpp
*
* Copyright(C):	�ǻ��ۿƼ��ɷ����޹�˾
*
* Author:  YCL
*
* Date: 2019-06
*
* Description: �����̣߳���ȡ���֤���籣����Ϣ
***********************************************************************************/

#include "ReadIdCardThread.h"
#include "AEyeIdReader.h"
#include "GlogManager.h"

#include <time.h>
#include <QLibrary>

ReadIdCardThread::ReadIdCardThread(QObject *parent)
    : QThread(parent)
    , m_idReader(NULL)
{
    loadDLL();
}

ReadIdCardThread::~ReadIdCardThread()
{

}

int ReadIdCardThread::readIdCard()
{
    AEIdCardInfo info;
    memset(&info, 0, sizeof(info));
    int ret = -1;

    LOG(INFO)<<"��ȡ���֤��Ϣ...";
    if (m_idReader != NULL) {
         ret = m_idReader->AEyeIdReader_ReadBaseMsg(&info);
    }
    else {
        return E_ID_LOAD_DLL_FAILED;
    }

    if (ret == E_READ_SUCCESS)
    {
        m_readCardResult.certificateNumber = info.idNumber;
        m_readCardResult.name = info.name;
    }

    return ret;
}

void ReadIdCardThread::run()
{
    const int tryTimes = 5;
    int errCode = -1;
    for (int i = 0; i < tryTimes; i++)
    {
        errCode = readIdCard();
        if (errCode == E_READ_SUCCESS)
        {
            emit readIdCardSuccessed(m_readCardResult);
            return;
        }
        msleep(100);
    }
    emit readIdCardFailed(errCode);
}

void ReadIdCardThread::loadDLL()
{
    QLibrary mainDll("AEyeIdReader.dll");
    if (mainDll.load()) {
        getObj obj = (getObj)mainDll.resolve("getDllObj");
        m_idReader = obj();
    }
}
