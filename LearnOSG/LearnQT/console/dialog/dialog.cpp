#include "dialog.h"

dialog::dialog(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
}

dialog::~dialog()
{

}
