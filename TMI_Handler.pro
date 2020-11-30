#-------------------------------------------------
#
# Project created by QtCreator 2019-07-01T13:52:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
win32:RC_ICONS += zikl.ico
#TARGET = Ziklogramma2
TARGET = TMI_Handler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    secondwindow.cpp \
    tinyxmlparser.cpp \
    tinyxmlerror.cpp \
    tinystr.cpp \
    tinyxml.cpp
#LIBS += qwindows.dll
#INCLUDEPATH += D:\qt\5.6\mingw49_32\plugins1\

HEADERS  += mainwindow.h \
    secondwindow.h \
    tinyxml.h

FORMS    += mainwindow.ui \
    secondwindow.ui
