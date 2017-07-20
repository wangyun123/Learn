/*
 * 测试案例 MyMutex - QT多线程
 * 职坐标 嵌入式应用开发进阶-QT编程 >同步与互斥
 * http://www.zhizuobiao.com
 *
 * 利用QMutex类，实现两个线程的互斥运行
 *
 * 实现目标：两个线程类ThreadA和ThreadB，
 * 当ThreadA打印时，ThreadB处于阻塞状态，
 * 同样，当ThreadB打印时，ThreadA处于阻塞状态
 *
 * 线程ThreadA和ThreadB中分别定义各自的互斥体变量QMutex mutex;
 *
 * 疑问：
 * （1）这两个互斥体对加锁的代码段
 *     （即mutex.lock()和mutex.unlock()之间的代码段）做了些什么？
 *
 * （2）如果线程ThreadA和ThreadB用同一个互斥体的话，怎么实现呢？
 *
 * （3）当线程ThreadA和ThreadB运行过程异常终端，会不会导致死锁？
 *     应该不会！两个线程分别采用各自的互斥体
*/

#include <QtCore/QCoreApplication>
#include "ThreadA.h"
#include "ThreadB.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadA ta;
    ThreadB tb;
    ta.start();
    tb.start();
    
    return a.exec();
}
