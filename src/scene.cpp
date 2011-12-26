#include "scene.h"
#include "mainwindow.h"

Scene::Scene(QWidget *parent) :
    QGLWidget(parent)//,camera(1.0,0.0,0.0,0.0)
{
    test_chunk.randomGenerate(100);
    test_chunk.setChunkPosition(QPointF(0,16));
    test_chunk.saveToFile("out_0_1.chunk");
    test_chunk.randomGenerate(50);
    test_chunk.setChunkPosition(QPointF(16,0));
    test_chunk.saveToFile("out_1_0.chunk");
    test_chunk.randomGenerate(150);
    test_chunk.setChunkPosition(QPointF(0,0));
    test_chunk.saveToFile("out_0_0.chunk");
    test_chunk.loadFromFile("out_0_0.chunk");
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

    camera.x = camera.y =
    camera.z = 15;
    camera.xRot = camera.yRot = camera.zRot = 0;
    camera.scale = 1;

    render.initRender();
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
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();

//    GLfloat ratio=(GLfloat)nHeight/(GLfloat)nWidth;

//    if (nWidth>=nHeight)
//       glOrtho(-10.0/ratio, 10.0/ratio, -10.0, 10.0, -10.0, 10.0);
//    else
//       glOrtho(-10.0, 10.0, -10.0*ratio, 10.0*ratio, -10.0, 10.0);

    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    updateGL();
}

void Scene::paintGL()
{
//projection
    MainWindow *m = NULL;
    if (parent()->objectName() == "MainWindow")
        m = ((MainWindow*) parent());
    if (m)
        m->printStatus(QString("x: %1, y: %2, z: %3, xR: %4, yR: %5, zR: %6")
               .arg((int)camera.x).arg((int)camera.y).arg((int)camera.z)
               .arg((int)camera.xRot).arg((int)camera.yRot).arg((int)camera.zRot)
               );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat ratio=(GLfloat)height()/(GLfloat)width();

//    if (width()>=height())
//       glOrtho(-10.0/ratio, 10.0/ratio, -10.0, 10.0, -10.0, 100.0);
//    else
//       glOrtho(-10.0, 10.0, -10.0*ratio, 10.0*ratio, -10.0, 100.0);
    gluPerspective(45, 1/ratio, 1.0, 100.0);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(camera.scale, camera.scale, camera.scale);
    glRotatef(camera.xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(camera.yRot, 0.0f, 1.0f, 0.0f);
    //glRotatef(camera.zRot, 0.0f, 0.0f, 1.0f);
    glTranslatef(-camera.x, -camera.y, -camera.z);
    //gluLookAt(camera.x, camera.y, camera.z, 0, 0, 0, 0, 100, 0);
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

    if (camera.xRot > 360) camera.xRot -= 360;
    if (camera.xRot < -360) camera.xRot += 360;
    if (camera.yRot > 360) camera.yRot -= 360;
    if (camera.yRot < -360) camera.yRot += 360;
//    if (camera.zRot > 360) camera.zRot -= 360;
//    if (camera.zRot < -360) camera.zRot += 360;
    ptrMousePosition = pe->pos();

    updateGL();
}

void Scene::wheelEvent(QWheelEvent* pe)
{
   if ((pe->delta())>0) camera.scale *= 1.1;
   else if ((pe->delta())<0) camera.scale /= 1.1;

   updateGL();
}

void Scene::keyPressEvent(QKeyEvent* pe)
{
//    m_bFirstRelease = true;
    keysPressed += (Qt::Key) pe->key();
    pe->accept();
    checkPressedKeys();

    updateGL();
}

void Scene::checkPressedKeys(){
    if (keysPressed.contains(Qt::Key_Escape))
        qApp->quit();
    if (keysPressed.contains(Qt::Key_W)) {
        if (keysPressed.contains(Qt::Key_A)){
            moveCamera(4);
        }else if (keysPressed.contains(Qt::Key_D)){
            moveCamera(5);
        }else
            moveCamera(0);
    }else if (keysPressed.contains(Qt::Key_S)){
        if (keysPressed.contains(Qt::Key_A)){
            moveCamera(6);
        }else if (keysPressed.contains(Qt::Key_D)){
            moveCamera(7);
        }else
            moveCamera(2);
    }else if (keysPressed.contains(Qt::Key_A)){
        moveCamera(1);
    }else if (keysPressed.contains(Qt::Key_D)){
        moveCamera(3);
    }
}

void Scene::keyReleaseEvent(QKeyEvent *pe) {
    keysPressed -= (Qt::Key) pe->key();
    pe->accept();
    checkPressedKeys();
}


void Scene::moveCamera(int direction)
{
    const GLfloat velocity = 0.1;
    GLfloat dir_x,dir_y;
    dir_x = dir_y = 0;
    switch (direction){
    case 0: // forward = W
        dir_x = 0;
        dir_y = 0;
        break;
    case 1: // left  = A
        dir_x = -camera.xRot;
        dir_y = -90;
        break;
    case 2: // bask = S
        dir_x = 180;
        dir_y = 0;
        break;
    case 3: // right = D
        dir_x = -camera.xRot;
        dir_y = 90;
        break;
    case 4: // forward-left = WA
        dir_x = -camera.xRot/2;
        dir_y = -45;
        break;
    case 5: // forward-right = WD
        dir_x = -camera.xRot/2;
        dir_y = 45;
        break;
    case 6: // back-left = SA
        dir_x = 180;//90-camera.xRot/2;
        dir_y = 45;
        break;
    case 7: // back-right = SD
        dir_x = 180;//90-camera.xRot/2;
        dir_y = -45;
        break;
    }
    camera.x += velocity  * sin((camera.yRot+dir_y)/180*M_PI) * cos((camera.xRot+dir_x)/180*M_PI);
    camera.y -= velocity  * sin((camera.xRot+dir_x)/180*M_PI);
    camera.z -= velocity  * cos((camera.yRot+dir_y)/180*M_PI) * cos((camera.xRot+dir_x)/180*M_PI);
}//*/
