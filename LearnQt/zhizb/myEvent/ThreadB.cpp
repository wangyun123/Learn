#include "ThreadB.h"
#include "MySingleton.h"
#include <QDebug>

ThreadB::ThreadB(QObject *parent) :
    QThread(parent)
{
}

void ThreadB::run()
{
    MySingleton* ps = MySingleton::getInstance();

#if 0
    for(int i=0; i<10; i++)
    {
        ps->semaphoreB.acquire(1);
        qDebug() << "ThreadB" << i;
        sleep(1);
        ps->semaphoreA.release(1);
    }
#else
    for(int i=0; i<5; i++)
    {
        mutex.lock();
        qDebug() << "ThreadB" << i;
        sleep(2);
        mutex.unlock();
    }
#endif
}
