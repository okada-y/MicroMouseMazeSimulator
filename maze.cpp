#include "maze.h"

Maze::Maze()
    :xSize(32),ySize(32)
{

}

const int Maze::getXSize(){
    return xSize;
}

const int Maze::getYSize(){
    return ySize;
}
