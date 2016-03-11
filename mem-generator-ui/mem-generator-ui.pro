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
    connection.cpp \
    peermanager.cpp \
    client.cpp \
    server.cpp \
    encrypt.cpp \
    qencrypt.cpp \
    imageops.cpp \
    memeGeneration.cpp \
    qtmemeGeneration.cpp

HEADERS  += mainwindow.h \
    chatdialog.h \
    connection.h \
    peermanager.h \
    client.h \
    server.h \
    encrypt.hpp \
    qencrypt.hpp \
    imageops.hpp \
    memeGeneration.hpp \
    qtmemeGeneration.hpp

FORMS    += mainwindow.ui \
    chatdialog.ui

QT      += network widgets

QMAKE_CXXFLAGS += -std=c++11

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += dri

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += gdlib
