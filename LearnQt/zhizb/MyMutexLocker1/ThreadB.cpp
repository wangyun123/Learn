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

    // 利用QMutexLocker互斥体，其他的线程始终拿不到锁，
    // 原因：线程的切换所用的时间始终比函数体内部的for循环所用时间要长很多！
    for(int i=0; i<5; i++)
    {
        QMutexLocker locker(&ps->mutex);
        qDebug() << "ThreadB" << i;
        sleep(2);
//        // 疑问：错误中断运行，会不会导致死锁
//        return ;
    }
}
