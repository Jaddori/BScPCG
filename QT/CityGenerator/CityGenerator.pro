#-------------------------------------------------
#
# Project created by QtCreator 2017-04-03T22:08:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = CityGenerator
TEMPLATE = app

win32: LIBS += -L$$OUT_PWD/../../BScPCG/lib -L$$OUT_PWD/../../BScPCG/build -lglew32s -lopengl32 -lelicras
else:unix: LIBS += -L$$OUT_PWD/../../BScPCG/build -lelicras

win32: INCLUDEPATH += $$OUT_PWD/../../BScPCG/include \
                $$OUT_PWD/../../BScPCG/BScPCG
else:unix: INCLUDEPATH += $$OUT_PWD/../../BScPCG/include \
                $$OUT_PWD/../../BScPCG/BScPCG

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS \
            GLEW_STATIC

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui

DESTDIR = $$OUT_PWD/../../BScPCG/build
