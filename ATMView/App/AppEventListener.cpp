/***********************************************************************************
*								AppEventListener.cpp
*
* Copyright(C):	�����ǻ��ۿƼ��ɷ����޹�˾
*
* Author:  HJM,TZH
*
* Date: 2018-12
*
* Description: ��������App�¼���⣬���û������
***********************************************************************************/
#include "AppEventListener.h"
#include <QCoreApplication>
#include <QMouseEvent>
#include <QCursor>
#include <QTimer>
#include <Windows.h>

#include "UserConfig.h"
#include "SystemChecker.h"

AppEventListener::AppEventListener(QObject *parent)
	: QObject(parent)
{
   
}

AppEventListener::~AppEventListener()
{

}

bool AppEventListener::eventFilter(QObject *obj, QEvent *event)
{	

	return false;
}
