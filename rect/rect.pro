QT      += widgets

TARGET = rect
TEMPLATE = lib

OTHER_FILES +=

HEADERS += \
    ../AbstractShape/abstractshape.h \
    ../AbstractShape/abstractshape_global.h \
    rect.h \
    ../AbstractShape/bbox.h \
    ../AbstractShape/point.h

SOURCES += \
    rect.cpp

CONFIG  += c++11

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AbstractShape/release/ -lAbstractShape
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AbstractShape/debug/ -lAbstractShape
else:unix: LIBS += -L$$OUT_PWD/../AbstractShape/ -lAbstractShape

INCLUDEPATH += $$PWD/../AbstractShape
DEPENDPATH += $$PWD/../AbstractShape
