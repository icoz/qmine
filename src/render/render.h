#ifndef RENDER_H
#define RENDER_H

#include <QtCore>
#include <QtOpenGL>

#include "gfx_primitives.h"
#include "texcoords_terrain.h"
#include "../world/chunk.h"

class Render
{
public:
    Render();
    ~Render();
    void initRender();
    static void drawGrid(GLfloat gridStep);
    void drawTestCube(GLfloat x,GLfloat y,GLfloat z,BlockType type);
    static GLuint allocateTexture(QString filename);
    void drawChunk(Chunk *ch);

protected:
    GLuint tex_id;
};

#endif // RENDER_H
