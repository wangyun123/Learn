/*
 * ���԰��� MyMutexLocker1 - QT���߳�
 * ְ���� Ƕ��ʽӦ�ÿ�������-QT��� >ͬ���뻥��
 * http://www.zhizuobiao.com
 *
 * ����QMutexLocker�࣬ʵ�������̵߳Ļ�������
 *
 * ʵ��Ŀ�꣺�����߳���ThreadA��ThreadB��
 * ��ThreadA��ӡʱ��ThreadB��������״̬��
 * ͬ������ThreadB��ӡʱ��ThreadA��������״̬
 *
 * �߳�ThreadA��ThreadB����ͬһ��������ı���QMutex mutex;
 * �����������һ��ȫ�ֵı����У����õ���ģʽsingleton��ʵ��
 *
 * ���߳����к����е���QMutexLocker locker(&mutex);
 * �ں���forѭ����lockerΪ�ֲ�������ÿ��ѭ��������֤locker�ͷ�
 *
 * ע������QMutexLocker�����壬�������߳�ʼ���ò�������
 * ԭ���̵߳��л����õ�ʱ��ʼ�ձȺ������ڲ���forѭ������ʱ��Ҫ���ܶ࣡
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
