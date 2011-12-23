#include "scene.h"

Scene::Scene(QWidget *parent) :
    QGLWidget(parent),camera(1.0,0.0,0.0,0.0)
{
    //xRot=yRot=zRot=0.0f;
    //nSca=1.0f;

    //grabMouse();
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
       glOrtho(-10.0/ratio, 10.0/ratio, -10.0, 10.0, -10.0, 10.0);
    else
       glOrtho(-10.0, 10.0, -10.0*ratio, 10.0*ratio, -10.0, 10.0);
    glTranslatef(-5.0f, -5.0f, 5.0f);

    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glRotatef(0.1, 1.0f, 0.0f, 0.0f);
    //        glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    //        glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    //        glRotatef(zRot, 0.0f, 0.0f, 1.0f);
    glRotatef(camera.x(), 1.0f, 0.0f, 0.0f);
    glRotatef(camera.y(), 0.0f, 1.0f, 0.0f);
    glRotatef(camera.z(), 0.0f, 0.0f, 1.0f);
    glScalef(camera.scalar(),camera.scalar(),camera.scalar());
    Render::drawGrid(1);
    Render::drawTestCube(1);
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

   camera.setX(camera.x() + 180/nSca*(GLfloat)(pe->y()-ptrMousePosition.y())/height());
   camera.setY(camera.y() + 180/nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width());

   ptrMousePosition = pe->pos();

   updateGL();
}

void Scene::wheelEvent(QWheelEvent* pe)
{
   if ((pe->delta())>0) camera.setScalar(camera.scalar()*1.1);
   else if ((pe->delta())<0) camera.setScalar(camera.scalar()/1.1);

   updateGL();
}
//*/
void Scene::keyPressEvent(QKeyEvent* pe)
{
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

/*      case Qt::Key_Plus:
         scale_plus();
      break;

      case Qt::Key_Equal:
         scale_plus();
      break;

      case Qt::Key_Minus:
         scale_minus();
      break;

      case Qt::Key_Up:
         rotate_up();
      break;

      case Qt::Key_Down:
         rotate_down();
      break;

      case Qt::Key_Left:
        rotate_left();
      break;

      case Qt::Key_Right:
         rotate_right();
      break;

      case Qt::Key_Z:
         translate_down();
      break;

      case Qt::Key_X:
         translate_up();
      break;

      case Qt::Key_Space:
         defaultScene();
      break;

      case Qt::Key_Escape:
         this->close();
      break;
      //*/
   }

   updateGL();
}//*/
