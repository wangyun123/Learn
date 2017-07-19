/*
 * ���԰��� MyMutexLocker - QT���߳�
 * ְ���� Ƕ��ʽӦ�ÿ�������-QT��� >ͬ���뻥��
 * http://www.zhizuobiao.com
 *
 * ����QMutexLocker�࣬ʵ�������̵߳Ļ�������
 *
 * ʵ��Ŀ�꣺�����߳���ThreadA��ThreadB��
 * ��ThreadA��ӡʱ��ThreadB��������״̬��
 * ͬ������ThreadB��ӡʱ��ThreadA��������״̬
 *
 * �߳�ThreadA��ThreadB�зֱ�����ԵĻ��������QMutex mutex;
 *
 * ���߳����к����е���QMutexLocker locker(&mutex);
 * �ں���forѭ����lockerΪ�ֲ�������ÿ��ѭ��������֤locker�ͷ�
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
