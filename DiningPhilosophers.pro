#-------------------------------------------------
#
# Project created by QtCreator 2016-02-12T22:44:50
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = DiningPhilosophers
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    threadworker.cpp \
    globals.cpp \
    waiter.cpp

HEADERS += \
    threadworker.h \
    globals.h \
    waiter.h
