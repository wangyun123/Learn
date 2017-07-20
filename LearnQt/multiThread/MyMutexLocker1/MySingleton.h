#ifndef MYSINGLETON_H
#define MYSINGLETON_H

#include <QMutex>

class MySingleton
{
public:
    static MySingleton* getInstance();

private:
    MySingleton();

    static MySingleton* instance;

public:
    QMutex mutex;
};

#endif // MYSINGLETON_H
