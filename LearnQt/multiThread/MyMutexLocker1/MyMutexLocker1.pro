#-------------------------------------------------
#
# Project created by QtCreator 2017-07-19T10:21:18
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MyMutexLocker1
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
