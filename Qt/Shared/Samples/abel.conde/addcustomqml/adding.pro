QT = core qml

SOURCES += main.cpp \
           person.cpp \
           car.cpp \
    item.cpp
HEADERS += person.h \
           car.h \
    item.h
RESOURCES += adding.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/qml/referenceexamples/adding
INSTALLS += target
