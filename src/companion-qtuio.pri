INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

QT += core gui widgets
#network

# Enable very detailed debug messages when compiling the debug version
CONFIG(debug, debug|release) {
    DEFINES += SUPERVERBOSE
}

HEADERS += $$PWD/qoscbundle_p.h \
           $$PWD/qoscmessage_p.h \
           $$PWD/qtuio_p.h \
           $$PWD/qtuiocursor_p.h \
           $$PWD/qtuiotoken_p.h \
           $$PWD/qtuiohandler.h
           
SOURCES += $$PWD/qoscbundle.cpp \
           $$PWD/qoscmessage.cpp \
           $$PWD/qtuiohandler.cpp
