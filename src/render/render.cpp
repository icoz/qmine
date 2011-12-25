#include "render.h"

Render::Render()
{
}

void Render::drawGrid(GLfloat gridStep)
{
    glLineWidth(1.0);
    glBegin(GL_LINES);
        glColor3f(0.0, 1.0, 0.0);
        /* Y-X */
        for (GLfloat y = 0.0; y <= 10; y += gridStep) {
            glVertex3f(0.0, y, 0.0);
            glVertex3f(10.0, y, 0.0);
        }
        for (GLfloat x = 0.0; x <= 10; x += gridStep) {
            glVertex3f(x, 0.0, 0.0);
            glVertex3f(x, 10.0, 0.0);
        }
        /* Z-X */
        for (GLfloat z = 0.0; z <= 10; z += gridStep) {
            glVertex3f(0.0, 0.0, z);
            glVertex3f(10.0, 0.0, z);
        }
        for (GLfloat x = 0.0; x <= 10; x += gridStep) {
            glVertex3f(x, 0.0, 0.0);
            glVertex3f(x, 0.0, 10.0);
        }
        /* Z-Y */
        for (GLfloat z = 0.0; z <= 10; z += gridStep) {
            glVertex3f(0.0, 0.0, z);
            glVertex3f(0.0, 10.0, z);
        }
        for (GLfloat y = 0.0; y <= 10; y += gridStep) {
            glVertex3f(0.0, y, 0.0);
            glVertex3f(0.0, y, 10.0);
        }
        glEnd();
}

void Render::drawTestCube(GLfloat x, GLfloat y, GLfloat z, GLfloat size)
{
    Q_UNUSED(size);
    QVector<avVertex3> v;
    QVector<avTexCube> t;
    for (unsigned int i = 0; i < sizeof(cube)/sizeof(GLfloat); i += 3){
        v.append(avVertex3(x + cube[i], y + cube[i+1], z + cube[i+2]));
    }
    //t.append(texture_by_id[btDirt]);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glTexCoordPointer(2, GL_FLOAT, 0, t.constData());
    glVertexPointer(3, GL_FLOAT, 0, v.constData());
    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

