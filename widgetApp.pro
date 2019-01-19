# Copyright(C) 2019 Andrey Yaromenok, ayaromenok@gmail.com
# MIT License: https://github.com/ayaromenok/YaSchengenCalc/blob/master/LICENSE

QT       += core gui widgets

TARGET = widgetApp
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        src/mainWdt.cpp \
        src/mainwindow.cpp \
        src/yaschengencalc.cpp \
    src/yaschengenwidget.cpp

HEADERS += \
        src/mainwindow.h \
        src/yaschengencalc.h \
    src/yaschengenwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
