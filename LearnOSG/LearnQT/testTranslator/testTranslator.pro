QT += core gui opengl

TARGET = testTranslator
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    dialog.cpp \
	mainwindow.cpp \
	dialogtranslator.cpp \
	myapplication.cpp

FORMS += \
    dialog.ui \
	mainwindow.ui \
	dialogtranslator.ui

HEADERS += \
    dialog.h \
	mainwindow.h \
	dialogtranslator.h \
	myapplication.h

TRANSLATIONS += zh_cn.ts \
				zh_jp.ts \
				zh_fr.ts
