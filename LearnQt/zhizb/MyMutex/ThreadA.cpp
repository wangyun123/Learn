#include "ThreadA.h"
#include <QDebug>

ThreadA::ThreadA(QObject *parent) :
    QThread(parent)
{
}

void ThreadA::run()
{
    for(int i=0; i<5; i++)
    {
        mutex.lock();
        qDebug() << "ThreadA" << i;
        sleep(1);
        mutex.unlock();
    }

}
