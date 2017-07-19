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

    // 利用QMutexLocker互斥体，其他的线程始终拿不到锁，
    // 原因：线程的切换所用的时间始终比函数体内部的for循环所用时间要长很多！
    for(int i=0; i<5; i++)
    {
        QMutexLocker locker(&ps->mutex);
        qDebug() << "ThreadA" << i;
        sleep(1);
    }
}
