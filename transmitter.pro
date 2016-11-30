#-------------------------------------------------
#
# Project created by QtCreator 2016-11-25T10:55:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = transmitter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h
HEADERS  += wiringSerial.h
FORMS    += mainwindow.ui
LIBS     += -lwiringPi

RESOURCES += \
    res.qrc
