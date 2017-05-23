#include "dialog.h"
#include "ui_dialog.h"
#include <QVBoxLayout>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    label = new QLabel(tr("translator"));
    button01 = new QPushButton(tr("english"), this);
    button02 = new QPushButton(tr("china"), this);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(label);
    mainLayout->addWidget(button01);
    mainLayout->addWidget(button02);
    //centralWidget->setLayout(mainLayout);
    this->setLayout(mainLayout);

    retranslate();

    connect(button01,SIGNAL(clicked()),this,SLOT(languageChina()));
    connect(button02,SIGNAL(clicked()),this,SLOT(languageEnglish()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::languageChina()
{
    qDebug()<< "fuck up";
    QString path = qApp->applicationDirPath();
    qDebug()<< qPrintable(path);
    translator.load(path+QString("/zh_CN"));
    qApp->installTranslator(&translator);
}

void Dialog::languageEnglish()
{
    qDebug()<< "fuck down";
    qApp->removeTranslator(&translator);
}

void Dialog::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        qDebug() << "event";
        retranslate();
    } else
        QDialog::changeEvent(event);
}

void Dialog::retranslate()
{
    label->setText(tr("translator"));
    button02->setText(tr("china"));
    button01->setText(tr("english"));
}
