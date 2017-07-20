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

    for(int i=0; i<10; i++)
    {
        ps->semaphoreB.acquire(1);
        qDebug() << "ThreadB" << i;
        sleep(1);
        ps->semaphoreA.release(1);
    }
}
