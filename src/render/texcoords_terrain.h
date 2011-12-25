#ifndef TEXCOORDS_TERRAIN_H
#define TEXCOORDS_TERRAIN_H

#include "gfx_primitives.h"
#include "../world/block.h"

#define tex_id(i) \
        {((((i) & 0xF)  ) * 16)/256.0, (256-(((i) >> 4) + 1)*16)/256.0}, \
        {((((i) & 0xF)  ) * 16)/256.0, (256-(((i) >> 4)    )*16)/256.0}, \
        {((((i) & 0xF)+1) * 16)/256.0, (256-(((i) >> 4)    )*16)/256.0}, \
        {((((i) & 0xF)+1) * 16)/256.0, (256-(((i) >> 4) + 1)*16)/256.0}

//const avTexCoord c = {1,2};

const avTexCube texture_by_id[] = {
    {tex_id(btPachma),tex_id(btPachma),tex_id(btPachma),
     tex_id(btPachma),tex_id(btPachma),tex_id(btPachma)},
    {tex_id(btStone),tex_id(btStone),tex_id(btStone),
     tex_id(btStone),tex_id(btStone),tex_id(btStone)},
    {tex_id(btDirt),tex_id(btDirt),tex_id(btDirt),
     tex_id(btDirt),tex_id(btDirt),tex_id(btDirt)}
};

#endif // TEXCOORDS_TERRAIN_H
