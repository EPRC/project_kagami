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
    cellwindow.cpp

HEADERS  += mainwindow.h \
    layerwindow.h \
    layer.h \
    layertablemodel.h \
    layermanger.h \
    cellwindow.h \
    cellmodel.h

CONFIG += c++11 \
           plugin

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AbstractShape/release/ -lAbstractShape
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AbstractShape/debug/ -lAbstractShape
else:unix: LIBS += -L$$OUT_PWD/../AbstractShape/ -lAbstractShape

INCLUDEPATH += $$PWD/../AbstractShape
DEPENDPATH += $$PWD/../AbstractShape
