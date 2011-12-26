#ifndef BLOCK_H
#define BLOCK_H

#include "entity.h"

enum BlockType {
    btPachma = 0,
    btStone,
    btDirt,
    btGrass,
    btGold,
    btDiamond,
    btWood,
    btMAX_ID
};

class Block : public Entity
{
public:
    Block(GLfloat x, GLfloat y, GLfloat z, BlockType _type);
    Block(GLfloat x, GLfloat y, GLfloat z, int _type);
protected:
    int type; // eq BlockType

    friend class Chunk;
};

#endif // BLOCK_H
