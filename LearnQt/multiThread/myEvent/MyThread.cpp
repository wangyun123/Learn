#include "MyThread.h"
#include <QDebug>

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
}

void MyThread::run()
{
    for(int i=0; i<10; i++)
    {
        qDebug() << i;
        sleep(1);
    }
}
