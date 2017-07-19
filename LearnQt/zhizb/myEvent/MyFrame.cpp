#include "MyFrame.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

MyFrame::MyFrame(QWidget *parent) :
    QFrame(parent)
{
}

void MyFrame::mousePressEvent(QMouseEvent *ev)
{
    QPoint pt = QPoint(ev->x(), ev->y());
    vec.push_back(pt);
    qDebug() << pt;
    update();
}

void MyFrame::mouseReleaseEvent(QMouseEvent *ev)
{
    QPoint pt = QPoint(ev->x(), ev->y());
    vec.push_back(pt);
    qDebug() << pt;
    update();
}

void MyFrame::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint pt = QPoint(ev->x(), ev->y());
    vec.push_back(pt);
    qDebug() << pt;
    update();
}

void MyFrame::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter;
    painter.begin(this);
    //painter.drawLine(QPoint(20,20), QPoint(60,60));
    if (vec.size() < 1)
        return ;
    QPoint start = vec.at(0);
    QVector<QPoint>::Iterator it;
    for (it=vec.begin(); it!=vec.end(); it++)
    {
        painter.drawLine(start, *it);
        start = *it;
    }

    painter.end();
}
