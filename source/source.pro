QT += qml quick

DESTDIR = $$_PRO_FILE_PWD_/../bin

CONFIG += c++11
CONFIG -= app_bundle

#unix:!android {

LIBS += -L/usr/local/lib -lzmq



INCLUDEPATH += \
    ../include \
    ../3rdparty/cppzmq \
    ../3rdparty/nzmqt \
    ../3rdparty/zmq \
    $(QTDIR)/include


HEADERS += \
    ../3rdparty/nzmqt/nzmqt.hpp \
    source_api.h


SOURCES += main.cpp \
    source_api.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
