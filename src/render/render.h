#ifndef RENDER_H
#define RENDER_H

#include <QtCore>
#include <QtOpenGL>

class Render
{
public:
    Render();
    static void drawGrid(GLfloat gridStep);
    static void drawTestCube(GLfloat size);
    static void drawTestCube2(GLfloat size);
//    void setProjection();
};

#endif // RENDER_H
