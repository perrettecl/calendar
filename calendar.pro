TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
CONFIG += sql
QT += sql

SOURCES += src/main.cpp \
    src/dbmanager.cpp \
    src/person.cpp

SUBDIRS += \
    calendar.pro

DISTFILES += \
    README.md

HEADERS += \
    src/dbmanager.h \
    src/person.h
