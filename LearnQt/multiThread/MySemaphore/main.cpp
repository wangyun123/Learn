/*
 * 测试案例 MySemaphore - QT多线程
 * 职坐标 嵌入式应用开发进阶-QT编程 >同步与互斥
 * http://www.zhizuobiao.com
 *
 * 利用QSemaphore类，实现两个线程的互斥运行
 *
 * 实现目标：两个线程类ThreadA和ThreadB，
 * 当ThreadA打印时，ThreadB处于阻塞状态，
 * 同样，当ThreadB打印时，ThreadA处于阻塞状态
 *
 * 线程ThreadA和ThreadB中用信号量QSemaphore;
 * 将信号量全局的变量中，利用单例模式singleton来实现
 * 在MySingleton中建立两个信号量semaphoreA，semaphoreB
 *
 *
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
