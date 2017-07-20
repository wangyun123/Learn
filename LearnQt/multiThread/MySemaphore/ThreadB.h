#ifndef THREADB_H
#define THREADB_H

#include <QThread>

class ThreadB : public QThread
{
    Q_OBJECT
public:
    explicit ThreadB(QObject *parent = 0);

protected:
    virtual void run();
};

#endif // THREADB_H
