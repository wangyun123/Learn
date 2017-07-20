#include "ThreadA.h"
#include "MySingleton.h"
#include <QDebug>
#include <QMutexLocker>

ThreadA::ThreadA(QObject *parent) :
    QThread(parent)
{
}

void ThreadA::run()
{
    MySingleton* ps = MySingleton::getInstance();

    // ����QMutexLocker�����壬�������߳�ʼ���ò�������
    // ԭ���̵߳��л����õ�ʱ��ʼ�ձȺ������ڲ���forѭ������ʱ��Ҫ���ܶ࣡
    for(int i=0; i<5; i++)
    {
        QMutexLocker locker(&ps->mutex);
        qDebug() << "ThreadA" << i;
        sleep(1);
    }
}
