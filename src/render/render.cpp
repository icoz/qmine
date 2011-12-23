#include "render.h"

Render::Render()
{
}

void Render::drawGrid(GLfloat gridStep)
{
    glPushMatrix();
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
    glPopMatrix();
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

void Render::drawTestCube2(GLfloat size)
{
    GLfloat vertex[] = {
        //0 --+
        -0.5, -0.5, +0.5,
        //1 -++
        -0.5, +0.5, +0.5,
        //2 +-+
        +0.5, -0.5, +0.5,
        //3 +++
        +0.5, +0.5, +0.5,
        //4 +--
        +0.5, -0.5, -0.5,
        //5 ++-
        +0.5, +0.5, -0.5,
        //6 ---
        -0.5, -0.5, -0.5,
        //7 -+-
        -0.5, +0.5, -0.5
    };
    GLubyte indx[] = {
        //front 0132
        0,1,3,2,
        //back 4576
        4,5,7,6,
        //right 2354
        2,3,5,4,
        //left 6710
        6,7,1,0,
        //top 1753
        1,7,5,3,
        //bottom 6024
        6,0,2,4
    };
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);
//	glBindTexture(GL_TEXTURE_2D, textures[block->type]);
    glTranslatef(2.0,2.0,2.0);
    glScalef(size,size,size);
    glColor3f(0.0, 0.0, 1.0);
    glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3,GL_FLOAT,0,vertex);
        glDrawElements(GL_QUADS, 6*4, GL_UNSIGNED_BYTE, indx);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_CULL_FACE);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

