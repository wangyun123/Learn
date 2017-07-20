#include "ThreadB.h"
#include <QDebug>
#include <QMutexLocker>

ThreadB::ThreadB(QObject *parent) :
    QThread(parent)
{
}

void ThreadB::run()
{
    for(int i=0; i<5; i++)
    {
        QMutexLocker locker(&mutex);
        qDebug() << "ThreadB" << i;
        sleep(2);
//        // 疑问：错误中断运行，会不会导致死锁
//        return ;
    }
}
