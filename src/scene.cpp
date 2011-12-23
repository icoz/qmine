#include "scene.h"

Scene::Scene(QWidget *parent) :
    QGLWidget(parent)
{
}

void Scene::initializeGL()
{
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);

//    getVertexArray();
//    getColorArray();
//    getIndexArray();

    //glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);
}

void Scene::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat ratio=(GLfloat)nHeight/(GLfloat)nWidth;

    if (nWidth>=nHeight)
       glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -10.0, 10.0);
    else
       glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -10.0, 10.0);

    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(-5.0f, -5.0f, 7.0f);
    glRotatef(0.01, 1.0f, 0.0f, 0.0f);
    Render::drawGrid(0.1);
    //Renderer::renderWorld();

//    glScalef(nSca, nSca, nSca);
//    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
//    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
//    glRotatef(zRot, 0.0f, 0.0f, 1.0f);

//    drawAxis();
//    drawFigure();
}
