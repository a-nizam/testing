#-------------------------------------------------
#
# Project created by QtCreator 2016-11-08T10:08:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Testing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbconnection.cpp \
    testwindow.cpp \
    testmodel.cpp

HEADERS  += mainwindow.h \
    dbconnection.h \
    testwindow.h \
    testmodel.h

FORMS    += mainwindow.ui \
    testwindow.ui
