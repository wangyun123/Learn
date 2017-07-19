#ifndef THREADA_H
#define THREADA_H

#include <QThread>
#include <QMutex>

class ThreadA : public QThread
{
    Q_OBJECT
public:
    explicit ThreadA(QObject *parent = 0);
    
protected:
    virtual void run();

private:
    QMutex mutex;
};

#endif // THREADA_H
