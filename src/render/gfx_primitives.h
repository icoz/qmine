#ifndef GFX_PRIMITIVES_H
#define GFX_PRIMITIVES_H

#include <QtOpenGL>

struct avVertex3 {
    GLfloat x,y,z;
    avVertex3(GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z) {}
    avVertex3() : x(0),y(0),z(0) {}
};

struct avQuadVertex {
    avVertex3 v[4];
};

struct avTexCoord {
    GLfloat s,t;
    //avTexCoord() : avTexCoord(0,0) {}
    //avTexCoord(GLfloat _s, GLfloat _t) : s(_s), t(_t) {}
};

struct avTexCoords2d {
    avTexCoord t[4];
};

struct avTexCube {
    avTexCoord t[4*6];
};

const GLfloat cube_vertex[] ={

    -0.5, -0.5, +0.5, // 0 --+
    -0.5, +0.5, +0.5, // 1 -++
    +0.5, -0.5, +0.5, // 2 +-+
    +0.5, +0.5, +0.5, // 3 +++
    +0.5, -0.5, -0.5, // 4 +--
    +0.5, +0.5, -0.5, // 5 ++-
    -0.5, -0.5, -0.5, // 6 ---
    -0.5, +0.5, -0.5, // 7 -+-
};

const GLshort cube_indexes[] = {
    0,1,3,2,
    4,5,7,6,
    2,3,5,4,
    6,7,2,0,
    1,7,5,3,
    6,0,2,4
};

const GLfloat cube[] ={
    // front    0132
    -0.5, -0.5, +0.5,
    -0.5, +0.5, +0.5,
    +0.5, +0.5, +0.5,
    +0.5, -0.5, +0.5,
    // back     4576
    +0.5, -0.5, -0.5,
    +0.5, +0.5, -0.5,
    -0.5, +0.5, -0.5,
    -0.5, -0.5, -0.5,
    // right    2354
    +0.5, -0.5, +0.5,
    +0.5, +0.5, +0.5,
    +0.5, +0.5, -0.5,
    +0.5, -0.5, -0.5,
    // left     6710
    -0.5, -0.5, -0.5,
    -0.5, +0.5, -0.5,
    -0.5, +0.5, +0.5,
    -0.5, -0.5, +0.5,
    // top      1753
    -0.5, +0.5, +0.5,
    -0.5, +0.5, -0.5,
    +0.5, +0.5, -0.5,
    +0.5, +0.5, +0.5,
    // bottom   6024
    -0.5, -0.5, -0.5,
    -0.5, -0.5, +0.5,
    +0.5, -0.5, +0.5,
    +0.5, -0.5, -0.5
};

#endif // GFX_PRIMITIVES_H
