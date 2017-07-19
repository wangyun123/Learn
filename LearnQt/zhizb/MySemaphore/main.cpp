/*
 * ���԰��� MySemaphore - QT���߳�
 * ְ���� Ƕ��ʽӦ�ÿ�������-QT��� >ͬ���뻥��
 * http://www.zhizuobiao.com
 *
 * ����QSemaphore�࣬ʵ�������̵߳Ļ�������
 *
 * ʵ��Ŀ�꣺�����߳���ThreadA��ThreadB��
 * ��ThreadA��ӡʱ��ThreadB��������״̬��
 * ͬ������ThreadB��ӡʱ��ThreadA��������״̬
 *
 * �߳�ThreadA��ThreadB�����ź���QSemaphore;
 * ���ź���ȫ�ֵı����У����õ���ģʽsingleton��ʵ��
 * ��MySingleton�н��������ź���semaphoreA��semaphoreB
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
