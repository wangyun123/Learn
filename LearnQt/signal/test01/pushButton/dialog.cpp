#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(OnPushButton1()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(OnPushButton2()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(OnPushButton3()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(OnPushButton4()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::OnPushButton1()
{
    printf("click pushButton_1, call OnPushButton1");
}

void Dialog::OnPushButton2()
{
    printf("click pushButton_2, call OnPushButton2");
}

void Dialog::OnPushButton3()
{
    printf("click pushButton_3, call OnPushButton3");
}

void Dialog::OnPushButton4()
{
    printf("click pushButton_4, call OnPushButton4");
}
