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

/*
void Scene3D::mousePressEvent(QMouseEvent* pe)
{
   ptrMousePosition = pe->pos();
}

void Scene3D::mouseReleaseEvent(QMouseEvent* pe)
{

}

void Scene3D::mouseMoveEvent(QMouseEvent* pe)
{
   xRot += 180/nSca*(GLfloat)(pe->y()-ptrMousePosition.y())/height();
   zRot += 180/nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width();

   ptrMousePosition = pe->pos();

   updateGL();
}

void Scene3D::wheelEvent(QWheelEvent* pe)
{
   if ((pe->delta())>0) scale_plus(); else if ((pe->delta())<0) scale_minus();

   updateGL();
}

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
