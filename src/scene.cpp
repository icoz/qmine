#include "scene.h"

Scene::Scene(QWidget *parent) :
    QGLWidget(parent)//,camera(1.0,0.0,0.0,0.0)
{
    //xRot=yRot=zRot=0.0f;
    //nSca=1.0f;

    //grabMouse();
    camera.x= -5.0f;
    camera.y= -5.0f;
    camera.z= 5.0f;
    camera.xRot= 0.0f;
    camera.yRot= 0.0f;
    camera.zRot= 0.0f;
    camera.scale= 1.0f;
}

void Scene::initializeGL()
{
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
//    glShadeModel(GL_FLAT);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glFrontFace(GL_CW);

//    getVertexArray();
//    getColorArray();
//    getIndexArray();

    //glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);
    //glEnableClientState(GL_NORMAL_ARRAY);
    //glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Scene::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void Scene::paintGL()
{
//projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat ratio=(GLfloat)height()/(GLfloat)width();

    if (width() >= height())
       glOrtho(-10.0/ratio, 10.0/ratio, -10.0, 10.0, -10.0, 10.0);
    else
       glOrtho(-10.0, 10.0, -10.0*ratio, 10.0*ratio, -10.0, 10.0);
    glTranslatef(camera.x,camera.y,camera.z);
    //glTranslatef(-5.0f, -5.0f, 5.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//draw
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glRotatef(0.1, 1.0f, 0.0f, 0.0f);
    //        glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    //        glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    //        glRotatef(zRot, 0.0f, 0.0f, 1.0f);
    glRotatef(camera.xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(camera.yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(camera.zRot, 0.0f, 0.0f, 1.0f);
    glScalef(camera.scale,camera.scale,camera.scale);
//    glTranslatef(camera.x,camera.y,camera.z);
    Render::drawGrid(1);
    //Render::drawTestCube(1);
    Render::drawTestCube2(1);
    //Renderer::renderWorld();

//    glScalef(nSca, nSca, nSca);

//    drawAxis();
//    drawFigure();
}

void Scene::mousePressEvent(QMouseEvent* pe)
{
   ptrMousePosition = pe->pos();
}

void Scene::mouseReleaseEvent(QMouseEvent* pe)
{

}

void Scene::mouseMoveEvent(QMouseEvent* pe)
{
   //xRot += 180/nSca*(GLfloat)(pe->y()-ptrMousePosition.y())/height();
   //zRot += 180/nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width();

   camera.xRot += 180/camera.scale*(GLfloat)(pe->y()-ptrMousePosition.y())/height();
   camera.yRot += 180/camera.scale*(GLfloat)(pe->x()-ptrMousePosition.x())/width();

   ptrMousePosition = pe->pos();

   updateGL();
}

void Scene::wheelEvent(QWheelEvent* pe)
{
   if ((pe->delta())>0) camera.scale *= 1.1;
   else if ((pe->delta())<0) camera.scale /= 1.1;

   updateGL();
}
//*/
void Scene::keyPressEvent(QKeyEvent* pe)
{
    const GLfloat VELOCITY = 0.1f;
    switch (pe->key())
    {
    case Qt::Key_Escape:
        qApp->quit();
        break;
    case Qt::Key_1:
        grabMouse();
        break;
    case Qt::Key_2:
        releaseMouse();
        break;
    case Qt::Key_W:
        //camera.x -= sin(camera.yRot / 180.0 * M_PI) * VELOCITY;
        ///camera.y += camera.yRot * VELOCITY;
        //camera.z -= cos(camera.yRot / 180.0 * M_PI) * VELOCITY;
        break;
    case Qt::Key_S:
        //camera.x -= sin(camera.yRot + M_PI) * VELOCITY;
        //camera.y += camera.yRot * VELOCITY;
        //camera.z -= cos(camera.yRot + M_PI) * VELOCITY;
        break;
    case Qt::Key_A:
        break;
    case Qt::Key_D:
        break;
    case Qt::Key_Q:
        break;
    case Qt::Key_E:
        break;
   }

   updateGL();
}//*/
