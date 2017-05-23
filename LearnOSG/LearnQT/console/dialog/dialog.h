#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui/QDialog>
#include "ui_dialog.h"

class dialog : public QDialog
{
	Q_OBJECT

public:
	dialog(QWidget *parent = 0, Qt::WFlags flags = 0);
	~dialog();

private:
	Ui::dialogClass ui;
};

#endif // DIALOG_H
