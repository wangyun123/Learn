#-------------------------------------------------
#
# Project created by QtCreator 2017-07-19T10:59:55
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MyMutex1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += ThreadA.h \
    ThreadB.h \
    MySingleton.h

SOURCES += main.cpp \
    ThreadA.cpp \
    ThreadB.cpp \
    MySingleton.cpp
