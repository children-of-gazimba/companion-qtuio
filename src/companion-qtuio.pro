#-------------------------------------------------
#
# Project created by QtCreator 2018-05-08T17:32:05
#
#-------------------------------------------------

QT       += core gui widgets network

TARGET = companion-qtuio
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../sockets/src/companion-qt-sockets.pri)

SOURCES += \
    main_widget.cpp \
    main_window.cpp \
    main.cpp \
    qoscbundle.cpp \
    qoscmessage.cpp \
    qtuiohandler.cpp



HEADERS += \
    main_widget.h \
    main_window.h \
    qoscbundle_p.h \
    qoscmessage_p.h \
    qtuio_p.h \
    qtuiocursor_p.h \
    qtuiohandler.h \
    qtuiotoken_p.h \
    qtuioblob_p.h
