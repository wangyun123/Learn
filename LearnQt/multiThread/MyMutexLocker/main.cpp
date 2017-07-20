/*
 * 测试案例 MyMutexLocker - QT多线程
 * 职坐标 嵌入式应用开发进阶-QT编程 >同步与互斥
 * http://www.zhizuobiao.com
 *
 * 利用QMutexLocker类，实现两个线程的互斥运行
 *
 * 实现目标：两个线程类ThreadA和ThreadB，
 * 当ThreadA打印时，ThreadB处于阻塞状态，
 * 同样，当ThreadB打印时，ThreadA处于阻塞状态
 *
 * 线程ThreadA和ThreadB中分别定义各自的互斥体变量QMutex mutex;
 *
 * 在线程运行函数中调用QMutexLocker locker(&mutex);
 * 在函数for循环中locker为局部变量，每次循环结束保证locker释放
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
