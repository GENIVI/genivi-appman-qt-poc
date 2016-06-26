TEMPLATE = lib
CONFIG += qt plugin
QT += qml

TARGET = geniviappfw
DESTDIR = ../imports/GeniviAppFw

SOURCES = geniviappman.cpp plugin.cpp
HEADERS = geniviappman.h

qml_files = qmldir
OTHER_FILES += $$qml_files
