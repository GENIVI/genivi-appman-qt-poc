TEMPLATE = lib
CONFIG += qt plugin
QT += qml dbus

TARGET = geniviappfw
DESTDIR = ../imports/GeniviAppFw

INCLUDEPATH += ../franca/

SOURCES = plugin.cpp \
          geniviappman.cpp \
          ../franca/gen/appmanagercore.cpp

HEADERS = geniviappman.h \
          ../franca/gen/appmanagercore.h

qml_files = qmldir
OTHER_FILES += $$qml_files
