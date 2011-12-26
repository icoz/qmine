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
	src/render/render.cpp \
	src/world/entity.cpp \
	src/world/block.cpp \
	src/world/chunk.cpp \
	src/mainwindow.cpp

HEADERS  += \
	src/scene.h \
	src/render/render.h \
	src/world/entity.h \
	src/world/block.h \
	src/world/chunk.h \
	src/render/gfx_primitives.h \
	src/render/texcoords_terrain.h \
	src/mainwindow.h

FORMS    +=

RESOURCES += \
	src/res/res.qrc
