#-------------------------------------------------
#
# Project created by QtCreator 2014-04-04T14:08:21
#
#-------------------------------------------------

QT       += widgets

TARGET = AbstractShape
TEMPLATE = lib

DEFINES += ABSTRACTSHAPE_LIBRARY

SOURCES += abstractshape.cpp \
    bbox.cpp \
    point.cpp

HEADERS += abstractshape.h\
        abstractshape_global.h \
    bbox.h \
    point.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG  += c++11
