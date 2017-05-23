#ifndef DIALOGTRANSLATOR_H
#define DIALOGTRANSLATOR_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QTranslator>

class DialogTranslator : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTranslator(QWidget *parent = 0);
    ~DialogTranslator();

    virtual void changeEvent(QEvent *);

public slots:
    virtual void accept();
    virtual void cancel();

    void languageEnglish();
    void languageChina();
    void languageJapan();
    void languageFranch();

private:
    QPushButton* btn_accept;
    QPushButton* btn_cancel;

    QLabel* label;
    QPushButton* btn_english;
    QPushButton* btn_china;
    QPushButton* btn_japan;
    QPushButton* btn_franch;
    static QTranslator* translator;

    void retranslate();
};

#endif // DIALOGTRANSLATOR_H
