#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->spinBox, SIGNAL(valueChanged(int)), &receiver, SLOT(onChangeValue3(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), &receiver, SLOT(onChangeValue3()));
    //connect(ui->spinBox, SIGNAL(valueChanged()), &receiver, SLOT(onChangeValue1(int)));
}

Dialog::~Dialog()
{
    delete ui;
}
