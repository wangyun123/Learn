#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialogtranslator.h"
#include <QDebug>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    button = new QPushButton(tr("dialog"), this);
    bnt_language = new QPushButton(tr("language"), this);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(button);
    mainLayout->addWidget(bnt_language);
    QWidget* widget = new QWidget(this);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);
//    setLayout(mainLayout);

	retranslate();
    connect(button, SIGNAL(clicked()), this, SLOT(showDialog()));
    connect(bnt_language, SIGNAL(clicked()), this, SLOT(showLanguage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLanguage()
{
    DialogTranslator dlg(this);
    dlg.exec();
}

void MainWindow::showDialog()
{
    Dialog dlg(this);
    dlg.exec();
}

void MainWindow::changeEvent(QEvent * e)
{
    QWidget::changeEvent(e);

    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
		retranslate();
        qDebug("MainWindow page");
        break;
    default:
        break;
    }

//    if (event->type() == QEvent::LanguageChange)
//    {
//        qDebug() << "MainWindow::changeEvent";
////        retranslate();
//        ui->retranslateUi(this);
//    } else
//        QMainWindow::changeEvent(event);
}

void MainWindow::retranslate()
{
	button->setText(tr("dialog"));
	bnt_language->setText(tr("language"));
}