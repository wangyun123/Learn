#ifndef MYCLASS_H
#define MYCLASS_H

#include <QDebug>

class MyClass
{
public:
    MyClass();
};

class Base
{
public:
    Base() {qDebug("the Base 's construct");}
    ~Base() {qDebug("the Base 's destruct");}

    virtual void vfunc1()=0;

private:
    int age;
};

class Derive1 : public Base
{
public:
    Derive1() {qDebug("the Derive-1 's construct");}
    ~Derive1() {qDebug("the Derive-1 's destruct");}

    virtual void vfunc1()
    {
        qDebug("the Derive-1 's vfunc1");
    }
};

class Derive2 : public Derive1
{
public:
    Derive2() {qDebug("the Derive-2 's construct");}
    ~Derive2() {qDebug("the Derive-2 's destruct");}

    virtual void vfunc1()
    {
        qDebug("the Derive-2 's vfunc1");
        Derive1::vfunc1();
    }
};

#endif // MYCLASS_H
