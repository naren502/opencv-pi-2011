#-------------------------------------------------
#
# Project created by QtCreator 2011-11-30T11:18:05
#
#-------------------------------------------------

QT       += core gui

TARGET = Interface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    laplacianzc.cpp \
    morphofeatures.cpp

HEADERS  += mainwindow.h \
    laplacianzc.h \
    morphofeatures.h

FORMS    += mainwindow.ui
CONFIG += link_pkgconfig
PKGCONFIG += opencv




