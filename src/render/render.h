#ifndef RENDER_H
#define RENDER_H

#include <QtCore>
#include <QtOpenGL>

#include "gfx_primitives.h"
#include "texcoords_terrain.h"
//#include "../"

class Render
{
public:
    Render();
    static void drawGrid(GLfloat gridStep);
    static void drawTestCube(GLfloat x,GLfloat y,GLfloat z,GLfloat size);
};

#endif // RENDER_H
