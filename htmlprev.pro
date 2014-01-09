#-------------------------------------------------
#
# Project created by QtCreator 2013-12-05T21:34:51
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = htmlprev
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    preview.cpp \
    codeeditor.cpp

HEADERS  += mainwindow.h \
    preview.h \
    codeeditor.h

RESOURCES += \
    res.qrc
