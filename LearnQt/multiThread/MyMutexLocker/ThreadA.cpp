#include "ThreadA.h"
#include <QDebug>
#include <QMutexLocker>

ThreadA::ThreadA(QObject *parent) :
    QThread(parent)
{
}

void ThreadA::run()
{
    for(int i=0; i<5; i++)
    {
        QMutexLocker locker(&mutex);
        qDebug() << "ThreadA" << i;
        sleep(1);
    }
}
