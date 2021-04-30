QT       += core gui sql
QT       +=printsupport
QT       +=multimedia
QT       +=serialport charts printsupport
QT +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_Qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activite.cpp \
    connection.cpp \
    dialog_activite.cpp \
    dialog_home.cpp \
    dialog_inscription.cpp \
    dialog_personnel.cpp \
    dialog_salle.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp \
    salle.cpp \
    son.cpp

HEADERS += \
    activite.h \
    connection.h \
    dialog_activite.h \
    dialog_home.h \
    dialog_inscription.h \
    dialog_personnel.h \
    dialog_salle.h \
    mainwindow.h \
    personnel.h \
    salle.h \
    son.h

FORMS += \
    dialog_activite.ui \
    dialog_home.ui \
    dialog_inscription.ui \
    dialog_personnel.ui \
    dialog_salle.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
