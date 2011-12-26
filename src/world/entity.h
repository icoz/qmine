#ifndef ENTITY_H
#define ENTITY_H

#include <QtOpenGL>

class Entity
{
public:
    Entity(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _sx, GLfloat _sy, GLfloat _sz)
        : x(_x), y(_y), z(_z), sx(_sx), sy(_sy), sz(_sz) {}
protected:
    GLfloat x,y,z;    //coords
    GLfloat sx,sy,sz; //sizes
};

#endif // ENTITY_H
