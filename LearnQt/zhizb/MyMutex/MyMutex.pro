#-------------------------------------------------
#
# Project created by QtCreator 2017-07-19T10:01:46
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MyMutex
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += ThreadA.h \
    ThreadB.h

SOURCES += main.cpp \
    ThreadA.cpp \
    ThreadB.cpp
