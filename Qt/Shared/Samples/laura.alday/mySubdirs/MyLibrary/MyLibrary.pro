#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T17:31:17
#
#-------------------------------------------------

QT       -= gui

TARGET = MyLibrary
TEMPLATE = lib

DEFINES += MYLIBRARY_LIBRARY

SOURCES += mylibrary.cpp

HEADERS += mylibrary.h\
        mylibrary_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
