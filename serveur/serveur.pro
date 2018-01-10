QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


LIBS += -LC:\wamp\bin\mysql\mysql5.7.19\lib -llibmysql
LIBS += -LC:\wamp\bin\mysql\mysql5.7.19\lib -llibmysqld
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


