#-------------------------------------------------
#
# Project created by QtCreator 2011-12-20T12:30:29
#
#-------------------------------------------------

QT       = core gui opengl

TARGET = qmine
TEMPLATE = app
MOC_DIR = build
OBJECTS_DIR = build
RCC_DIR = build
UI_DIR = build

SOURCES += src/main.cpp \
    src/scene.cpp \
    src/render/render.cpp

HEADERS  += \
    src/scene.h \
    src/render/render.h

FORMS    +=