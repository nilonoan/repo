TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MyLibrary/release/ -lMyLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MyLibrary/debug/ -lMyLibrary
else:unix: LIBS += -L$$OUT_PWD/../MyLibrary/ -lMyLibrary

INCLUDEPATH += $$PWD/../MyLibrary
DEPENDPATH += $$PWD/../MyLibrary
