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
    cell.cpp \
    point.cpp \
    cellmodel.cpp \
    pointmodel.cpp \
    cellwindow.cpp \
    bbox.cpp

HEADERS  += mainwindow.h \
    layerwindow.h \
    layer.h \
    layertablemodel.h \
    layermanger.h \
    cell.h \
    point.h \
    cellmodel.h \
    pointmodel.h \
    cellwindow.h \
    bbox.h

CONFIG += c++11 \
           plugin
