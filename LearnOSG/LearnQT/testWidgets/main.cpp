#include "testwidgets.h"
#include <QApplication>

void func()
{

}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	func();
	testWidgets w;
	w.show();
	return a.exec();
}
