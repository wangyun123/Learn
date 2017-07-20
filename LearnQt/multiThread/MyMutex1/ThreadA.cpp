#include "ThreadA.h"
#include "MySingleton.h"
#include <QDebug>

ThreadA::ThreadA(QObject *parent) :
    QThread(parent)
{
}

void ThreadA::run()
{
    MySingleton* ps = MySingleton::getInstance();

    for(int i=0; i<5; i++)
    {
        ps->mutex.lock();
        qDebug() << "ThreadA" << i;
        //sleep(1); // 运算消耗时间
        ps->mutex.unlock();
        sleep(1); // 让其他进程有时间来获取锁
    }
}
