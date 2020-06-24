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
        mainwindow.cpp \
    c_config.cpp \
    tinyxml/tinyxml2.cpp

HEADERS  += mainwindow.h \
    c_config.h \
    tinyxml/tinyxml2.h
unix:HEADERS  += wiringSerial.h
FORMS    += mainwindow.ui
INCLUDEPATH += $$PWD/tinyxml/
unix:LIBS     += -lwiringPi

RESOURCES += \
    res.qrc
