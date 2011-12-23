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
