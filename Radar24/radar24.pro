#-------------------------------------------------
#
# Project created by QtCreator 2015-07-01T14:12:29
#
#-------------------------------------------------

QT       += core gui widgets printsupport serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPlotter
TEMPLATE = app


SOURCES += main.cpp widget.cpp qcustomplot/qcustomplot.cpp \
    sstest.cpp

HEADERS += widget.h qcustomplot/qcustomplot.h

FORMS   += widget.ui
unix:HEADERS  += wiringSerial.h
unix:LIBS     += -lwiringPi
