/*
 * ���԰��� MyMutex - QT���߳�
 * ְ���� Ƕ��ʽӦ�ÿ�������-QT��� >ͬ���뻥��
 * http://www.zhizuobiao.com
 *
 * ����QMutex�࣬ʵ�������̵߳Ļ�������
 *
 * ʵ��Ŀ�꣺�����߳���ThreadA��ThreadB��
 * ��ThreadA��ӡʱ��ThreadB��������״̬��
 * ͬ������ThreadB��ӡʱ��ThreadA��������״̬
 *
 * �߳�ThreadA��ThreadB�зֱ�����ԵĻ��������QMutex mutex;
 *
 * ���ʣ�
 * ��1��������������Լ����Ĵ����
 *     ����mutex.lock()��mutex.unlock()֮��Ĵ���Σ�����Щʲô��
 *
 * ��2������߳�ThreadA��ThreadB��ͬһ��������Ļ�����ôʵ���أ�
 *
 * ��3�����߳�ThreadA��ThreadB���й����쳣�նˣ��᲻�ᵼ��������
 *     Ӧ�ò��ᣡ�����̷ֱ߳���ø��ԵĻ�����
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
