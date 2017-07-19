#-------------------------------------------------
#
# Project created by QtCreator 2017-07-19T10:03:59
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MySemaphore
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
