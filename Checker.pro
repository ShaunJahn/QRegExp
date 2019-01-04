#-------------------------------------------------
#
# Project created by QtCreator 2013-07-17T14:02:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Checker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    readfile.cpp \
    regexchecker.cpp

HEADERS  += mainwindow.h \
    readfile.h \
    regexchecker.h

FORMS    += mainwindow.ui
