#include "chunk.h"

Chunk::Chunk()
{
}

void Chunk::randomGenerate(int count)
{
    int x,y,z,t;
    qsrand(QTime::currentTime().msec());
    for (int i = 0; i < count; i++){
        x = qrand() % CHUNK_SIZE_X;
        y = qrand() % 5;
        z = qrand() % CHUNK_SIZE_Z;
        t = qrand() % btMAX_ID;
        blocks.append(Block(x,y,z,t));
    }
    updateArrays();
}

void Chunk::updateArrays()
{
    vertex_array.clear();
    texcoord_array.clear();
    foreach (Block b, blocks){
        for (unsigned int i = 0; i < sizeof(cube)/sizeof(GLfloat); i += 3){
            vertex_array.append(avVertex3(b.x + cube[i], b.y + cube[i+1], b.z + cube[i+2]));
        }
        texcoord_array.append(texture_by_id[b.type]);
    }
}

void Chunk::loadFromFile(QString filename)
{
}

void Chunk::saveToFile(QString filename)
{
}
