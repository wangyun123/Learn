#include <QtGui/QApplication>
#include "mainwindow.h"
#include "MyClass.h"
#include "MyThread.h"

void testClass(void)
{
    // stack
    Derive2 d;
    d.vfunc1();
    // heap
    Derive2* pd = new Derive2();
    pd->vfunc1();
    delete pd;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    testClass();
//    MyThread t;
//    t.start();

    MainWindow w;
    w.show();
    
    return a.exec();
}
