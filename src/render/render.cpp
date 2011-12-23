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

void Render::drawTestCube(GLfloat size)
{
    glPushMatrix();
//	glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
//	glBindTexture(GL_TEXTURE_2D, textures[block->type]);
    //glTranslatef(0.0,0.0,0.0);
    GLfloat x,y,z;
    x=y=z=0.0f;
    glScalef(size,size,size);
    glColor3f(1.0, 1.0, 1.0);
    //glCallList(listBlock);
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 1.0);
            // front face
            glNormal3f( 0.0f, 0.0f, 1.0f);
            //glTexCoord2f(0.0, 0.0);
            glVertex3f(x - size/2, y - size/2, z + size/2);
            //glTexCoord2f(1.0, 0.0);
            glVertex3f(x + size/2, y - size/2, z + size/2);
            //glTexCoord2f(1.0, 1.0);
            glVertex3f(x + size/2, y + size/2, z + size/2);
            //glTexCoord2f(0.0, 1.0);
            glVertex3f(x - size/2, y + size/2, z + size/2);
            // back face
            glNormal3f( 0.0f, 0.0f, -1.0f);
            //glTexCoord2f(1.0, 0.0);
            glVertex3f(x - size/2, y - size/2, z - size/2);
            //glTexCoord2f(1.0, 1.0);
            glVertex3f(x - size/2, y + size/2, z - size/2);
            //glTexCoord2f(0.0, 1.0);
            glVertex3f(x + size/2, y + size/2, z - size/2);
            //glTexCoord2f(0.0, 0.0);
            glVertex3f(x + size/2, y - size/2, z - size/2);
            // left face
            glNormal3f( -1.0f, 0.0f, 0.0f);
            //glTexCoord2f(0.0, 0.0);
            glVertex3f(x - size/2, y - size/2, z - size/2);
            //glTexCoord2f(1.0, 0.0);
            glVertex3f(x - size/2, y - size/2, z + size/2);
            //glTexCoord2f(1.0, 1.0);
            glVertex3f(x - size/2, y + size/2, z + size/2);
            //glTexCoord2f(0.0, 1.0);
            glVertex3f(x - size/2, y + size/2, z - size/2);
            // right face
            glNormal3f( 1.0f, 0.0f, 0.0f);
            //glTexCoord2f(1.0, 0.0);
            glVertex3f(x + size/2, y - size/2, z - size/2);
            //glTexCoord2f(1.0, 1.0);
            glVertex3f(x + size/2, y + size/2, z - size/2);
            //glTexCoord2f(0.0, 1.0);
            glVertex3f(x + size/2, y + size/2, z + size/2);
            //glTexCoord2f(0.0, 0.0);
            glVertex3f(x + size/2, y - size/2, z + size/2);
            // top face
            glNormal3f( 0.0f, 1.0f, 0.0f);
            //glTexCoord2f(0.0, 1.0);
            glVertex3f(x - size/2, y + size/2, z - size/2);
            //glTexCoord2f(0.0, 0.0);
            glVertex3f(x - size/2, y + size/2, z + size/2);
            //glTexCoord2f(1.0, 0.0);
            glVertex3f(x + size/2, y + size/2, z + size/2);
            //glTexCoord2f(1.0, 1.0);
            glVertex3f(x + size/2, y + size/2, z - size/2);
            // bottom face
            glNormal3f( 0.0f, -1.0f, 0.0f);
            //glTexCoord2f(0.0, 0.0);
            glVertex3f(x - size/2, y - size/2, z - size/2);
            //glTexCoord2f(1.0, 0.0);
            glVertex3f(x + size/2, y - size/2, z - size/2);
            //glTexCoord2f(1.0, 1.0);
            glVertex3f(x + size/2, y - size/2, z + size/2);
            //glTexCoord2f(0.0, 1.0);
            glVertex3f(x - size/2, y - size/2, z + size/2);
        glEnd(); //*/
    glDisable(GL_CULL_FACE);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

