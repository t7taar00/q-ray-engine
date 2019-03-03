QT        += core gui

greaterThan(QT_MAJOR_VERSION, 4):
QT        += widgets

TARGET     = QRayEngine
TEMPLATE   = app

DEFINES   += QT_DEPRECATED_WARNINGS

CONFIG    += c++11

SOURCES   += src/main.cpp \
             src/mainview.cpp \
             src/viewplane.cpp \
             src/actorposition.cpp \
             src/rayprojectile.cpp \
             src/texturereader.cpp \
             src/userinput.cpp \
             src/scenemap.cpp \
             src/sceneview.cpp

HEADERS   += src/mainview.h \
             src/viewplane.h \
             src/actorposition.h \
             src/rayprojectile.h \
             src/texturereader.h \
             src/userinput.h \
             src/scenemap.h \
             src/sceneview.h

RESOURCES += resources/resources.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

