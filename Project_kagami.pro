TEMPLATE = subdirs

SUBDIRS += \
    lytDesigner \
    AbstractShape \
    rect

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Shape/release/ -lShape
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Shape/debug/ -lShape
else:unix: LIBS += -L$$OUT_PWD/Shape/ -lShape

INCLUDEPATH += $$PWD/Shape
DEPENDPATH += $$PWD/Shape
