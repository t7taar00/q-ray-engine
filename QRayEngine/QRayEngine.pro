QT      += core gui

greaterThan(QT_MAJOR_VERSION, 4):
QT      += widgets

TARGET   = QRayEngine
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG  += c++11

SOURCES += main.cpp \
           mainview.cpp \
           areamap.cpp \
           viewplane.cpp

HEADERS += mainview.h \
           areamap.h \
           viewplane.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
