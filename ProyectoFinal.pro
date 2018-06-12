#-------------------------------------------------
#
# Project created by QtCreator 2018-06-06T19:02:19
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProyectoFinal
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


SOURCES += \
        main.cpp \
        menuprincipal.cpp \
    nivel1.cpp \
    about.cpp \
    nivel2.cpp \
    nivel3.cpp \
    nivel4.cpp \
    nivel6.cpp \
    multiplayer.cpp \
    nivel5.cpp \
    listaniveles.cpp \
    Backend/esferagraf.cpp \
    Backend/esferasim.cpp \
    Backend/esferasimmovcir.cpp \
    Backend/esferasimmovcirgraf.cpp \
    win1.cpp

HEADERS += \
        menuprincipal.h \
    nivel1.h \
    about.h \
    nivel2.h \
    nivel3.h \
    nivel4.h \
    nivel6.h \
    multiplayer.h \
    nivel5.h \
    listaniveles.h \
    Backend/esferagraf.h \
    Backend/esferasim.h \
    Backend/esferasimmovcirgraf.h \
    Backend/esferasimmovcir.h \
    win1.h

FORMS += \
        menuprincipal.ui \
    nivel1.ui \
    about.ui \
    nivel2.ui \
    nivel3.ui \
    nivel4.ui \
    nivel6.ui \
    multiplayer.ui \
    nivel5.ui \
    listaniveles.ui \
    win1.ui

RESOURCES += \
    res.qrc
