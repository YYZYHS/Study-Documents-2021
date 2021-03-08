#-------------------------------------------------
#
# Project created by QtCreator 2016-07-05T23:10:38
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sqlmodel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        server.cpp

HEADERS  += mainwindow.h \
    server.h

FORMS    += mainwindow.ui
