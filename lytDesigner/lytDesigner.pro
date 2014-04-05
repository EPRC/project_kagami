#-------------------------------------------------
#
# Project created by QtCreator 2014-04-03T21:25:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lytDesigner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    layerwindow.cpp \
    layer.cpp \
    layertablemodel.cpp \
    layermanger.cpp \
    cellmodel.cpp \
    cellwindow.cpp \
    bbox.cpp

HEADERS  += mainwindow.h \
    layerwindow.h \
    layer.h \
    layertablemodel.h \
    layermanger.h \
    cellwindow.h \
    cellmodel.h

CONFIG += c++11 \
           plugin
