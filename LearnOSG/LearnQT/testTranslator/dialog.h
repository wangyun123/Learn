#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QTranslator>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    virtual void changeEvent(QEvent *);

public slots:
    void languageChina();
    void languageEnglish();

private:
    Ui::Dialog *ui;

    QLabel* label;
    QPushButton* button01;
    QPushButton* button02;
    QTranslator translator;

    void retranslate();
};

#endif // DIALOG_H
