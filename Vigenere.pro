TEMPLATE = app
CONFIG += console c++11 -Wall
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vigenere.cpp \
    clogger.cpp

HEADERS += \
    vigenere.h \
    clogger.h \
    utilities.h
