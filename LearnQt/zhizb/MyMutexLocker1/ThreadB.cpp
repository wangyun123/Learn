#include "ThreadB.h"
#include "MySingleton.h"
#include <QDebug>
#include <QMutexLocker>

ThreadB::ThreadB(QObject *parent) :
    QThread(parent)
{
}

void ThreadB::run()
{
    MySingleton* ps = MySingleton::getInstance();

    // ����QMutexLocker�����壬�������߳�ʼ���ò�������
    // ԭ���̵߳��л����õ�ʱ��ʼ�ձȺ������ڲ���forѭ������ʱ��Ҫ���ܶ࣡
    for(int i=0; i<5; i++)
    {
        QMutexLocker locker(&ps->mutex);
        qDebug() << "ThreadB" << i;
        sleep(2);
//        // ���ʣ������ж����У��᲻�ᵼ������
//        return ;
    }
}
