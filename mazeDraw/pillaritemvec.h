#ifndef PILLARITEMVEC_H
#define PILLARITEMVEC_H

#include "pillaritem.h"
#include "../maze.h"

class PillarItemVec
{
public:
    PillarItemVec(int size = MAX_MAZE_SIZE);

    void setExists(int x, int y, bool exists);
    bool getExists(int x, int y);
    bool isInsideOfField(int x, int y);

    std::vector<std::vector<PillarItem*>> itemVec;
};

#endif // PILLARITEMVEC_H
