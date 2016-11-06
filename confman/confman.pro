QT += qml quick

CONFIG += c++11
CONFIG -= app_bundle


DESTDIR = $$_PRO_FILE_PWD_/../bin

INCLUDEPATH += \
    ../include \
    ../3rdparty/cppzmq \
    ../3rdparty/nzmqt \
    ../3rdparty/zmq \
    $(QTDIR)/include


SOURCES += main.cpp

RESOURCES += \
    qml.qrc \
    imgs.qrc


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
