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
//        // ���ʣ������ж����У��᲻�ᵼ������
//        return ;
        mutex.unlock();
    }
}
