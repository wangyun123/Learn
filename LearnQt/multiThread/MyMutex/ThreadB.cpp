#include "ThreadB.h"
#include <QDebug>

ThreadB::ThreadB(QObject *parent) :
    QThread(parent)
{
}

void ThreadB::run()
{
    for(int i=0; i<5; i++)
    {
        mutex.lock();
        qDebug() << "ThreadB" << i;
        sleep(2);
//        // 疑问：错误中断运行，会不会导致死锁
//        return ;
        mutex.unlock();
    }
}
