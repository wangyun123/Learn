/*
*	学习QT的国际化
*
*	参考：Qt实现动态切换语言
*	http://blog.csdn.net/csf111/article/details/7752839
*
*	利用QEvent::LanguageChange()信号函数实现语言动态切换
*	
*	两种方式
*	
*	1）使用UI编辑器来自动生成界面的情况。
*	ui->retranslateUi(this);//在此处刷新语言的
*
*	2)不使用UI编辑器，自己通过亲自编程来设计应用程序界面的情况
*	自己实现函数void retranslate(QWidget *parent=0);
*	如：DialogTranslator::retranslate()
*
*	注：
*	如果将QTranslator* translator;作为对话框类的成员变量，
*	用installTranslator给QApplication翻译链表中时，此translator为局部变量，
*	当窗口退出时该变量被销毁，将会触发changeEvent(QEvent * event)函数，
*	语言又会变回原来模样。
*
*	解决方法：将QTranslator* translator作为对话框类的静态成员变量
*	static QTranslator* translator; 定义
*	QTranslator* DialogTranslator::translator = new QTranslator();初始化
*
*/
#include <QApplication>
#include <QDebug>
#include <QTranslator>

#include "dialog.h"
#include "mainwindow.h"
#include "myapplication.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    MyApplication a(argc, argv);

//    QString path = qApp->applicationDirPath();
//    qDebug()<< qPrintable(path);

//    QTranslator translator;
//    translator.load(path+QString("/zh_CN"),"." );
//    a.installTranslator(&translator);

    MainWindow dlg;
    dlg.show();

    return a.exec();
}
