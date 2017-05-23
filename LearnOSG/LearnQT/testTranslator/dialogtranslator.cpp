#include "dialogtranslator.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QApplication>

QTranslator* DialogTranslator::translator = new QTranslator();

DialogTranslator::DialogTranslator(QWidget *parent) :
    QDialog(parent)
{
    this->setWindowTitle(tr("language"));
    label = new QLabel(tr("translator"));
    btn_english = new QPushButton(tr("english"), this);
    btn_china = new QPushButton(tr("china"), this);
    btn_japan = new QPushButton(tr("japan"), this);
    btn_franch = new QPushButton(tr("franch"), this);

    btn_accept = new QPushButton(tr("ok"), this);
    btn_cancel = new QPushButton(tr("cancel"), this);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(label);
    mainLayout->addWidget(btn_english);
    mainLayout->addWidget(btn_china);
    mainLayout->addWidget(btn_japan);
    mainLayout->addWidget(btn_franch);
    mainLayout->addWidget(btn_accept);
    mainLayout->addWidget(btn_cancel);
    this->setLayout(mainLayout);

    retranslate();

    connect(btn_english,SIGNAL(clicked()),this,SLOT(languageEnglish()));
    connect(btn_china,SIGNAL(clicked()),this,SLOT(languageChina()));
    connect(btn_japan,SIGNAL(clicked()),this,SLOT(languageJapan()));
    connect(btn_franch,SIGNAL(clicked()),this,SLOT(languageFranch()));

    connect(btn_accept,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btn_cancel,SIGNAL(clicked()),this,SLOT(cancel()));
}

DialogTranslator::~DialogTranslator()
{

}

void DialogTranslator::accept()
{
    qDebug()<<"DialogTranslator::accept";
    QDialog::accept();
}

void DialogTranslator::cancel()
{
    qDebug()<<"DialogTranslator::cancel";
    QDialog::reject();
}

void DialogTranslator::languageEnglish()
{
#if 1
    qDebug()<< "fuck english";
    //QCoreApplication * QCoreApplication::instance
    //QApplication::instance()->removeTranslator(translator);
    qApp->removeTranslator(translator);
#else
    ((MyApplication*)qApp)->languageEnglish();
    //MyApplication::instance()->languageEnglish();
#endif
}

void DialogTranslator::languageChina()
{
#if 1
    qDebug()<< "fuck china";
    //QString path = QApplication::instance()->applicationDirPath();
    QString path = qApp->applicationDirPath();
    qDebug()<< qPrintable(path);
    translator->load(path+QString("/zh_CN"));
    //QApplication::instance()->installTranslator(translator);
    qApp->installTranslator(translator);
#else
    ((MyApplication*)qApp)->languageChina();
    //MyApplication::instance()->languageChina();
#endif
}

void DialogTranslator::languageJapan()
{
    ;
}
void DialogTranslator::languageFranch()
{
    ;
}

void DialogTranslator::changeEvent(QEvent * e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        qDebug() << "DialogTranslator::changeEvent";
        retranslate();
        break;
    default:
        break;
    }
//    if (event->type() == QEvent::LanguageChange)
//    {
//        qDebug() << "DialogTranslator changeEvent";
//        retranslate();
//    } else
//        QDialog::changeEvent(event);
}

void DialogTranslator::retranslate()
{
    label->setText(tr("translator"));
    btn_english->setText(tr("english"));
    btn_china->setText(tr("china"));
    btn_japan->setText(tr("japan"));
    btn_franch->setText(tr("franch"));
}

