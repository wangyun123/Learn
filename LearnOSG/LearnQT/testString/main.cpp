/*
*	学习QString stdwstring中编码的使用
*	参考1： QString与中文，QString与std::wstring的相互转换
*	https://my.oschina.net/jthmath/blog/521458
*
*	参考2：Qt 编码 QObject::tr()
*	http://blog.csdn.net/yueye30121/article/details/16114713
*
*	注意： QT
*	
*	1、尽量避免在源码中使用中文字符;
*
*		原因：无法保证使用正确的字符编码格式，windows下默认采用GBK/GB2312。
*
*	2、如果源码中使用了中文字符，可采用两种方式解决;
*
*	（1）全局设置。明确告诉编译器使用哪种编码格式
*		QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"))；
*
*	（2）局部设置。明确指定当前字符串所采用的编码格式
*		QString::fromStdWString(L"啊中文");
*
*	2017-03-22
*/

#include <string>
#include <QtCore/QCoreApplication>

void func()
{

}
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	func();
// 	printf("Hello world!\n");
// 	char* str10 = "授权激活";//"啊";//
// 	char str11[] = "授权激活";
// 	QString str1("授权激活");
// 	QString str2(QString::fromStdWString(L"啊"));
// 	QString str3(QString::fromUtf8(u8"啊"));	//c++11
// 	QString str4(QObject::tr("啊"));

// 	char* str1 = "china";
// 	char* str2 = "啊中文";
// 	printf("%s\n%s\n", str1, str2);

#if 0
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
	QString s1 = "啊中文";
	QString s2("啊中文");
	QString s3;
	s3 = "啊中文";
	QMessageBox::information(NULL, "Title", s1+"\n"+s2+"\n"+s3, QMessageBox::Ok);
#endif

#if 0
	QString t1 = QObject::tr("china");
	QString t2 = QString::fromStdWString(L"啊中文");
	QString t3 = "啊中文";
	QMessageBox::information(NULL, "Title", t1+"\n"+t2+"\n"+t3, QMessageBox::Ok);
#endif

// 	getchar();
	//system("pause");

	return a.exec();
}
