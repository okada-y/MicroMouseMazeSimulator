#ifndef PILLAR_H
#define PILLAR_H

#include "mazescene.h"

class Pillar
{
public:
    Pillar(int xNum = 32, int yNum = 32);
    void drawPillar(MazeScene *scene);

};


#endif // PILLAR_H
