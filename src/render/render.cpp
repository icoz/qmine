#include "render.h"

Render::Render()
{
    // no GL stuff here! We need GL-context first
}

Render::~Render()
{
    glDeleteTextures(1,&tex_id);
}

void Render::initRender()
{
    tex_id = allocateTexture(":/terrain.png");
//    GLuint tex_id = QGLWidget::bindTexture(":/res/terrain.png");
    //qDebug("terrain.png tex_id=%d", tex_id);

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

void Render::drawTestCube(GLfloat x, GLfloat y, GLfloat z, BlockType type)
{
    QVector<avVertex3> v;
    QVector<avTexCube> t;
    for (unsigned int i = 0; i < sizeof(cube)/sizeof(GLfloat); i += 3){
        v.append(avVertex3(x + cube[i], y + cube[i+1], z + cube[i+2]));
    }
    t.append(texture_by_id[type]);

    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            glFrontFace(GL_CW);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            glColor3f(1.0, 1.0, 1.0);
            glBindTexture(GL_TEXTURE_2D, tex_id);
            glTexCoordPointer(2, GL_FLOAT, 0, t.constData());
            //glNormalPointer(GL_FLOAT, 0, ch->normal);
            glVertexPointer(3, GL_FLOAT, 0, v.constData());
            glDrawArrays(GL_QUADS, 0, 24);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisable(GL_CULL_FACE);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
//    QGLWidget::deleteTexture(tex_id);
}

GLuint Render::allocateTexture(QString filename)
{
    /* Generate texture */
    GLuint texture_id;

    // загрузка изображений
    QImage image; // создаём объекты класса QImage (изображения)
    image.load(filename); // загружаем изображение в переменную image
    // конвертируем изображение в формат для работы с OpenGL:
    image=QGLWidget::convertToGLFormat(image);

    // создание имён для текстурных объектов
    glGenTextures(1, &texture_id); // создаём два имени и записываем их в массив

    // создаём и связываем текстурные объекты с состоянием текстуры
    // 1-ый текстурный объект
    // создаём и связываем 1-ый текстурный объект с последующим состоянием текстуры
    glBindTexture(GL_TEXTURE_2D, texture_id);
    // связываем текстурный объект с изображением
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)image.width(), (GLsizei)image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

    // дополнительные параметры текстурного объекта
    // задаём линейную фильтрацию вблизи:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // задаём линейную фильтрацию вдали:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    // задаём: при фильтрации игнорируются тексели, выходящие за границу текстуры для s координаты
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    // задаём: при фильтрации игнорируются тексели, выходящие за границу текстуры для t координаты
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // задаём: цвет текселя полностью замещает цвет фрагмента фигуры
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    return texture_id;
}

void Render::drawChunk(Chunk *ch)
{
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            glFrontFace(GL_CW);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            glColor3f(1.0, 1.0, 1.0);
            glBindTexture(GL_TEXTURE_2D, tex_id);
            glTexCoordPointer(2, GL_FLOAT, 0, ch->texcoord_array.constData());
            //glNormalPointer(GL_FLOAT, 0, ch->normal);
            glVertexPointer(3, GL_FLOAT, 0, ch->vertex_array.constData());
            glDrawArrays(GL_QUADS, 0, 24*ch->blocks.size()); // each block is 24 vertex

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisable(GL_CULL_FACE);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

