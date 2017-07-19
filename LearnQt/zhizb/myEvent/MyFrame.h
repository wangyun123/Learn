#ifndef MYFRAME_H
#define MYFRAME_H

#include <QFrame>
#include <QPoint>
#include <QVector>

class MyFrame : public QFrame
{
    Q_OBJECT
public:
    explicit MyFrame(QWidget *parent = 0);
    
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    void paintEvent(QPaintEvent *);
private:
    QVector<QPoint> vec;

signals:
    
public slots:
    
};

#endif // MYFRAME_H
