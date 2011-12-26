#include "block.h"

Block::Block(GLfloat x, GLfloat y, GLfloat z, BlockType _type)
    : Entity(x,y,z,0.5,0.5,0.5), type(_type)
{
}
Block::Block(GLfloat x, GLfloat y, GLfloat z, int _type)
    : Entity(x,y,z,0.5,0.5,0.5), type((BlockType)_type)
{
}
