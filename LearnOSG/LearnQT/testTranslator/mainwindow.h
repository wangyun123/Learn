#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void changeEvent(QEvent * event);

public slots:
    void showLanguage();
    void showDialog();

private:
    Ui::MainWindow *ui;
    QPushButton* button;
    QPushButton* bnt_language;

	void retranslate();
};

#endif // MAINWINDOW_H
