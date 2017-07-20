#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
public:
    MyClass(QObject* parent=0);
    ~MyClass();

signals:
    void signalChangeValue0();
    void signalChangeValue1(int);
    void signalChangeValue2(int *);
    void signalChangeValue3();
    void signalChangeValue3(int);
    // 信号定义不能有返回值 ?
    // 原因：sender也负责发送信号，而不关心receiver是谁。
    // 定义返回值也没有作用
//    void* signalChangeValue12();
//    void* signalChangeValue13(int);

public slots:
//    void onChangeValue0();
//    void onChangeValue1(int);
//    void onChangeValue2(int*);

    //********************************//
    void onChangeValue3();
    void onChangeValue3(int a);
    // moc不支持如下槽函数的定义,(信号定义也一样)
    // void onChangeValue3(int a=0)等于两个函数的
    // 定义:void onChangeValue3()和 void onChangeValue3(int a)
    //void onChangeValue3();
    //void onChangeValue3(int a=0);
private:
    int age;
};

#endif // MYCLASS_H
