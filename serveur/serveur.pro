QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
CONFIG += release
QT += network
QT += sql
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += FenServeur.h \
    sqlconnection.h
SOURCES += FenServeur.cpp main.cpp \
    sqlconnection.cpp


