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
    questiontypemodel.cpp \
    generatedtestmodel.cpp \
    availabletestmodel.cpp \
    questiontypedialog.cpp \
    themesdialog.cpp

HEADERS  += mainwindow.h \
    dbconnection.h \
    questiontypemodel.h \
    generatedtestmodel.h \
    availabletestmodel.h \
    questiontypedialog.h \
    themesdialog.h

FORMS    += mainwindow.ui \
    questiontypedialog.ui \
    themesdialog.ui
