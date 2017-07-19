/*
 * 测试案例 MyMutexLocker1 - QT多线程
 * 职坐标 嵌入式应用开发进阶-QT编程 >同步与互斥
 * http://www.zhizuobiao.com
 *
 * 利用QMutexLocker类，实现两个线程的互斥运行
 *
 * 实现目标：两个线程类ThreadA和ThreadB，
 * 当ThreadA打印时，ThreadB处于阻塞状态，
 * 同样，当ThreadB打印时，ThreadA处于阻塞状态
 *
 * 线程ThreadA和ThreadB中用同一个互斥体的变量QMutex mutex;
 * 将互斥体放入一个全局的变量中，利用单例模式singleton来实现
 *
 * 在线程运行函数中调用QMutexLocker locker(&mutex);
 * 在函数for循环中locker为局部变量，每次循环结束保证locker释放
 *
 * 注：利用QMutexLocker互斥体，其他的线程始终拿不到锁，
 * 原因：线程的切换所用的时间始终比函数体内部的for循环所用时间要长很多！
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
