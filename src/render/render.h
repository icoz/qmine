#ifndef RENDER_H
#define RENDER_H

#include <QtCore>
#include <QtOpenGL>

class Render
{
public:
    Render();
    static void drawGrid(GLfloat gridStep);
};

#endif // RENDER_H
