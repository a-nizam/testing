#-------------------------------------------------
#
# Project created by QtCreator 2017-05-16T09:55:03
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testing
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    answersmodel.cpp \
    availabletestmodel.cpp \
    dbconnection.cpp \
    generatedtestmodel.cpp \
    main.cpp \
    mainwindow.cpp \
    questionsdelegate.cpp \
    questionsmodel.cpp \
    questiontypedialog.cpp \
    questiontypemodel.cpp \
    themesdialog.cpp \
    themesmodel.cpp

HEADERS  += \
    answersmodel.h \
    availabletestmodel.h \
    dbconnection.h \
    generatedtestmodel.h \
    mainwindow.h \
    questionsdelegate.h \
    questionsmodel.h \
    questiontypedialog.h \
    questiontypemodel.h \
    themesdialog.h \
    themesmodel.h

FORMS    += \
    mainwindow.ui \
    questiontypedialog.ui \
    themesdialog.ui
