#-------------------------------------------------
#
# Project created by QtCreator 2017-10-26T19:00:25
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += sql
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = video
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    tcpclient.cpp \
    tcpserver.cpp \
    mypushbutton.cpp \
    titlewidget.cpp \
    messagetile.cpp \
    login.cpp \
    register.cpp \
    brow.cpp

HEADERS  += widget.h \
    tcpclient.h \
    tcpserver.h \
    mypushbutton.h \
    titlewidget.h \
    messagetile.h \
    login.h \
    register.h \
    brow.h

FORMS    += widget.ui \
    tcpclient.ui \
    tcpserver.ui \
    messagetile.ui \
    login.ui \
    register.ui \
    brow.ui

RESOURCES += \
    img.qrc
