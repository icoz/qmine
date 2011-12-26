#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include "render/render.h"

struct Camera {
    GLfloat x,y,z;
    GLfloat xRot, yRot, zRot;
    GLfloat scale;
};

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
    void mousePressEvent(QMouseEvent* pe);
    void mouseMoveEvent(QMouseEvent* pe);
    void mouseReleaseEvent(QMouseEvent* pe);
    void wheelEvent(QWheelEvent* pe);
    void keyPressEvent(QKeyEvent* pe);
    void keyReleaseEvent(QKeyEvent* pe);
    inline void moveCamera(int direction);
    Camera camera;
    QPoint ptrMousePosition;
    Render render;
    Chunk test_chunk;
    // for  multi-keypress
    QSet<Qt::Key> keysPressed;
//    bool m_bFirstRelease;
};

#endif // SCENE_H
