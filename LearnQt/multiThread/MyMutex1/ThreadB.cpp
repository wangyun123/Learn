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

    for(int i=0; i<5; i++)
    {
        ps->mutex.lock();
        qDebug() << "ThreadB" << i;
        //sleep(2); // ��������ʱ��
        ps->mutex.unlock();
        sleep(2); // ������������ʱ������ȡ��
    }

}
