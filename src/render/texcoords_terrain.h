#ifndef TEXCOORDS_TERRAIN_H
#define TEXCOORDS_TERRAIN_H

#include "gfx_primitives.h"
#include "../world/block.h"

#define tex_id(i) \
        {((((i) & 0xF)  ) * 16)/256.0, (256-(((i) >> 4) + 1)*16)/256.0}, \
        {((((i) & 0xF)  ) * 16)/256.0, (256-(((i) >> 4)    )*16)/256.0}, \
        {((((i) & 0xF)+1) * 16)/256.0, (256-(((i) >> 4)    )*16)/256.0}, \
        {((((i) & 0xF)+1) * 16)/256.0, (256-(((i) >> 4) + 1)*16)/256.0}


const avTexCube texture_by_id[] = {
    {{// Pachma
        tex_id(0),tex_id(0),tex_id(0),
        tex_id(0),tex_id(0),tex_id(0)
    }},
    {{// Stone
        tex_id(1),tex_id(1),tex_id(1),
        tex_id(1),tex_id(1),tex_id(1)
    }},
    {{// Dirt
        tex_id(2),tex_id(2),tex_id(2),
        tex_id(2),tex_id(2),tex_id(2)
    }},
    {{// Grass = Dirt with grass
        tex_id(3),tex_id(3),tex_id(3),
        tex_id(3),tex_id(9*16+2),tex_id(2)
    }},
    {{// Gold
        tex_id(32),tex_id(32),tex_id(32),
        tex_id(32),tex_id(32),tex_id(32)
    }},
    {{// Diamond
        tex_id(3*16+2),tex_id(3*16+2),tex_id(3*16+2),
        tex_id(3*16+2),tex_id(3*16+2),tex_id(3*16+2)
    }}
};

#endif // TEXCOORDS_TERRAIN_H
