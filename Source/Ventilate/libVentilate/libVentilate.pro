#-------------------------------------------------
#
# Project created by QtCreator 2015-10-30T00:05:29
#
#-------------------------------------------------

QT       += network sql

QT       -= gui

CONFIG += c++11
TARGET = libVentilate
TEMPLATE = lib

DEFINES += LIBVENTILATE_LIBRARY

SOURCES += \
    server.cpp \
    connectionhandler.cpp \
    account.cpp \
    chatroom.cpp \
    message.cpp \
    accountdatabase.cpp

HEADERS +=\
        libventilate_global.h \
    server.h \
    connectionhandler.h \
    commands.h \
    account.h \
    chatroom.h \
    message.h \
    databaseinterface.h \
    accountdatabase.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
