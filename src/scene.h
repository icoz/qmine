#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include "render/render.h"

class Scene : public QGLWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = 0);
    
signals:
    
public slots:
protected:
   void initializeGL();
   void resizeGL(int nWidth, int nHeight);
   void paintGL();
//   void mousePressEvent(QMouseEvent* pe);
//   void mouseMoveEvent(QMouseEvent* pe);
//   void mouseReleaseEvent(QMouseEvent* pe);
//   void wheelEvent(QWheelEvent* pe);
//   void keyPressEvent(QKeyEvent* pe);

};

#endif // SCENE_H
