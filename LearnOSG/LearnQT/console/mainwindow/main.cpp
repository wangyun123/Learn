#include "mainwindow.h"
#include <QtGui/QApplication>

void func()
{

}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	func();
	mainwindow w;
	w.show();
	return a.exec();
}
