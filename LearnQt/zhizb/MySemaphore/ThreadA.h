#ifndef THREADA_H
#define THREADA_H

#include <QThread>

class ThreadA : public QThread
{
    Q_OBJECT
public:
    explicit ThreadA(QObject *parent = 0);
    
protected:
    virtual void run();
};

#endif // THREADA_H
