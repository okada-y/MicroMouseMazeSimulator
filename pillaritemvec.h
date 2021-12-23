#ifndef PILLARITEMVEC_H
#define PILLARITEMVEC_H

#include "mazescene.h"
#include "walldesign.h"
#include "pillaritem.h"
#include "maze.h"

class PillarItemVec
{
public:
    PillarItemVec(int size = DEFAULT_MAZE_SIZE);

    void setExists(int x, int y, bool exists);
    bool getExists(int x, int y);
    bool isInsideOfField(int x, int y);
    void drawItemVec(MazeScene *scene, WallDesign *design);

private:
    std::vector<std::vector<PillarItem*>> itemVec;
};

#endif // PILLARITEMVEC_H
