/********************************************************************************
** Form generated from reading UI file 'dialogtranslator.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTRANSLATOR_H
#define UI_DIALOGTRANSLATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogTranslator
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogTranslator)
    {
        if (DialogTranslator->objectName().isEmpty())
            DialogTranslator->setObjectName(QString::fromUtf8("DialogTranslator"));
        DialogTranslator->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogTranslator);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogTranslator);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogTranslator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogTranslator, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogTranslator);
    } // setupUi

    void retranslateUi(QDialog *DialogTranslator)
    {
        DialogTranslator->setWindowTitle(QApplication::translate("DialogTranslator", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogTranslator: public Ui_DialogTranslator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTRANSLATOR_H
