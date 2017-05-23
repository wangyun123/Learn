#ifndef TESTWIDGETS_H
#define TESTWIDGETS_H

#include <QMainWindow>
#include "ui_testwidgets.h"

class testWidgets : public QMainWindow
{
	Q_OBJECT

public:
	testWidgets(QWidget *parent = 0);
	~testWidgets();

private:
	Ui::testWidgetsClass ui;
};

#endif // TESTWIDGETS_H
