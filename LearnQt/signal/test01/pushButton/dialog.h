#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void OnPushButton1();
    void OnPushButton2();
    void OnPushButton3();
    void OnPushButton4();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
