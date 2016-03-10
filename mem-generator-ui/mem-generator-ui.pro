#-------------------------------------------------
#
# Project created by QtCreator 2016-02-08T23:40:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mem-generator-ui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chatdialog.cpp \
    client.cpp \
    connection.cpp \
    peermanager.cpp \
    server.cpp

HEADERS  += mainwindow.h \
    chatdialog.h \
    client.h \
    connection.h \
    peermanager.h \
    server.h

FORMS    += mainwindow.ui \
    chatdialog.ui

QT      += network widgets
