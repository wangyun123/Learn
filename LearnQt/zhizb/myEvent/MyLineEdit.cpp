#include "MyLineEdit.h"
#include <QDebug>
#include <QKeyEvent>

MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void MyLineEdit::keyPressEvent(QKeyEvent *ev)
{
    QLineEdit::keyPressEvent(ev);
    qDebug() << ev->text();
}
