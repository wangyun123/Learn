#include "MyClass.h"
#include <QDebug>

MyClass::MyClass(QObject* parent)
    : QObject(parent)
{
    qDebug() << "MyClass destruct, this:" << this << endl;
}

MyClass::~MyClass()
{
    qDebug() << "MyClass destruct, this:" << this << endl;
}

//void MyClass::onChangeValue0()
//{
//    qDebug() << "MyClass::onChangeValue0()'s this:" << endl;
//}

//void MyClass::onChangeValue1(int a)
//{
//    qDebug() << "MyClass::onChangeValue1(int)'s this:" << a << endl;
//}

//void MyClass::onChangeValue2(int* pa)
//{
//    qDebug() << "MyClass::onChangeValue2(int*)'s this:" << *pa << endl;
//}

void MyClass::onChangeValue3()
{
    qDebug() << "MyClass::onChangeValue3(int)'s this:" << endl;
}
void MyClass::onChangeValue3(int a)
{
    qDebug() << "MyClass::onChangeValue3(int)'s this:" << a << endl;
}
