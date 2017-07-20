#ifndef THREADB_H
#define THREADB_H

#include <QThread>
#include <QMutex>

class ThreadB : public QThread
{
    Q_OBJECT
public:
    explicit ThreadB(QObject *parent = 0);

protected:
    virtual void run();

private:
    QMutex mutex;
};

#endif // THREADB_H
