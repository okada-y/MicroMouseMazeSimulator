#ifndef PILLARITEMVEC_H
#define PILLARITEMVEC_H

#include "mazescene.h"
#include "walldesign.h"
#include "pillaritem.h"

class PillarItemVec
{
public:
    PillarItemVec(int xSize = 32, int ySize = 32);

    void setExists(int x, int y, bool exists);
    bool getExists(int x, int y);
    bool isInsideOfField(int x, int y);
    void drawItemVec(MazeScene *scene, WallDesign *design);

private:
    std::vector<std::vector<PillarItem*>> itemVec;
};

#endif // PILLARITEMVEC_H
