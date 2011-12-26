#include "scene.h"

Scene::Scene(QWidget *parent) :
    QGLWidget(parent)
{
//    test_chunk.randomGenerate(100);
//    test_chunk.setChunkPosition(QPointF(0,16));
//    test_chunk.saveToFile("out_0_1.chunk");
//    test_chunk.randomGenerate(50);
//    test_chunk.setChunkPosition(QPointF(16,0));
//    test_chunk.saveToFile("out_1_0.chunk");
    //test_chunk.randomGenerate(150);
    //test_chunk.setChunkPosition(QPointF(0,0));
    test_chunk.loadFromFile("out_0_0.chunk");
}

void Scene::initializeGL()
{
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);

    camera.x = camera.y = -5;
    camera.z = -5;
    camera.xRot = camera.yRot = camera.zRot = 0;
    camera.scale = 1;

    render.initRender();
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
    //gluPerspective(45, nWidth/nHeight, 1.0, 100.0);
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat ratio=(GLfloat)height()/(GLfloat)width();

    if (width()>=height())
       glOrtho(-10.0/ratio, 10.0/ratio, -10.0, 10.0, -10.0, 10.0);
    else
       glOrtho(-10.0, 10.0, -10.0*ratio, 10.0*ratio, -10.0, 10.0);

    glScalef(camera.scale, camera.scale, camera.scale);
    glRotatef(camera.xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(camera.yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(camera.zRot, 0.0f, 0.0f, 1.0f);
    glTranslatef(camera.x, camera.y, camera.z);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

//    glTranslatef(-5.0f, -5.0f, 7.0f);
//    glRotatef(0.01, 1.0f, 0.0f, 0.0f);
    render.drawGrid(1);
//    render.drawTestCube(0,0,0,btDirt);
//    render.drawTestCube(1,1,1,btDirt);
//    render.drawTestCube(2,2,2,btDirt);
//    render.drawTestCube(2,3,2,btStone);
//    render.drawTestCube(2,4,2,btStone);
    render.drawChunk(&test_chunk);

//    drawAxis();
//    drawFigure();
}

void Scene::mousePressEvent(QMouseEvent* pe)
{
   ptrMousePosition = pe->pos();
}

void Scene::mouseReleaseEvent(QMouseEvent* pe)
{
    Q_UNUSED(pe);
}

void Scene::mouseMoveEvent(QMouseEvent* pe)
{
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

/*
void Scene3D::keyPressEvent(QKeyEvent* pe)
{
   switch (pe->key())
   {
      case Qt::Key_Plus:
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
   }

   updateGL();
}//*/
