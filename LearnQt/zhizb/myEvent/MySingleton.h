#ifndef MYSINGLETON_H
#define MYSINGLETON_H

#include <QMutex>
#include <QSemaphore>

class MySingleton
{
public:
    static MySingleton* getInstance();

private:
    MySingleton();

    static MySingleton* instance;

public:
    QSemaphore semaphoreA;
    QSemaphore semaphoreB;
    QMutex mutex;
};

#endif // MYSINGLETON_H
