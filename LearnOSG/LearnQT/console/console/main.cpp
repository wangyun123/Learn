
#include <QtCore/QCoreApplication>

void func()
{

}
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	func();

	return a.exec();
}
