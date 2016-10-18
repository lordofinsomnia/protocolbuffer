TEMPLATE = app
CONFIG += console
CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    addressbook.pb.cc

DISTFILES += \
    addressbook.proto

HEADERS += \
    addressbook.pb.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lprotobuf
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lprotobuf
else:unix: LIBS += -L$$PWD/../../../../usr/lib/ -lprotobuf

#INCLUDEPATH += $$PWD/../../../../usr/include
#DEPENDPATH += $$PWD/../../../../usr/include
