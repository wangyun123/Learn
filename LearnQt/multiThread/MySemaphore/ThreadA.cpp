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

    // semaphore
    for(int i=0; i<10; i++)
    {
        ps->semaphoreA.acquire(1);
        qDebug() << "ThreadA" << i;
        sleep(1);
        ps->semaphoreB.release(1);
    }
}
