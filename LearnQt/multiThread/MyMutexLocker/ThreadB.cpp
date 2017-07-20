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
//        // ���ʣ������ж����У��᲻�ᵼ������
//        return ;
    }
}
