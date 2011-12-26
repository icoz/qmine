#include "chunk.h"

Chunk::Chunk() : chunk_pos(0,0)
{
}

Chunk::~Chunk()
{
    blocks.clear();
    vertex_array.clear();
    texcoord_array.clear();
}

void Chunk::randomGenerate(int count)
{
    blocks.clear();
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
            vertex_array.append(avVertex3(chunk_pos.x() + b.x + cube[i], b.y + cube[i+1], chunk_pos.y() + b.z + cube[i+2]));
        }
        texcoord_array.append(texture_by_id[b.type]);
    }
}

void Chunk::loadFromFile(QString filename)
{
    blocks.clear();
    QFile fin(filename);
    if (fin.open(QIODevice::ReadOnly)){
        QDataStream ds(&fin);
        ds >> chunk_pos;
        while (!ds.atEnd()){
            GLfloat x,y,z;
            int type;
            ds >> x >> y >> z >> type;
            blocks.append(Block(x,y,z,type));
        }
        fin.close();
    } else QMessageBox::warning(0,"Error loading file", QString("Cannot load file %1").arg(filename));
    updateArrays();
}

void Chunk::saveToFile(QString filename)
{
    QFile fout(filename);
    if (fout.open(QIODevice::WriteOnly)){
        QDataStream ds(&fout);
        ds << chunk_pos;
        foreach (Block b, blocks){
            ds << b.x << b.y << b.z << b.type;
        }
        fout.close();
    } else QMessageBox::warning(0,"Error saving file", QString("Cannot save file %1").arg(filename));
}
