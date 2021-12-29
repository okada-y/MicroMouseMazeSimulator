#include "wallitemvec.h"

WallItemVec::WallItemVec(int size):
    besideItemVec(size+1,std::vector<WallItem*>(size, nullptr)),
    verticalItemVec(size,std::vector<WallItem*>(size+1, nullptr))
{

    mazeSize = size;

    //横壁ポインタの初期化
    for(int y = 0; y <= size; y++){
        for(int x = 0; x < size; x++){
            besideItemVec.at(y).at(x) = new WallItem;
        }
    }

    //縦壁ポインタの初期化
    for(int y = 0; y < size; y++){
        for(int x = 0; x <= size; x++){
            verticalItemVec.at(y).at(x) = new WallItem;
        }
    }
}

void WallItemVec::setExists(int ax, int x, int y, bool exists){
    /*
    Set the existence of the wall stored in the vector.

    Return
    ------

    */
    if(!isInsideOfField(ax,x,y)){
        qDebug("not inside of field");
        return;
    }
    switch(ax){
    case BESIDE:
        besideItemVec.at(y).at(x)->setExists(exists);
        break;
    case VERTICAL:
        verticalItemVec.at(y).at(x)->setExists(exists);
        break;
    default:
        qDebug("test");
        break;
    }
}

bool WallItemVec::getExists(int ax, int x, int y){
    /*
    Get the existence of the wall stored in the vector.

    Return
    ------
    bool existence
    */

    if(!isInsideOfField(ax,x,y)){
        qDebug("not inside of field");
        return false;
    }

    switch(ax){
    case BESIDE:
        return besideItemVec.at(y).at(x)->getExists();
    case VERTICAL:
        return verticalItemVec.at(y).at(x)->getExists();
    default:
        qDebug("Axis does not exit");
        return false;
    }
}

bool WallItemVec::isInsideOfField(int ax, int x, int y){
    /*
    determin if the wall is inside of the field

    Return
    ------
    bool result
    */
    switch(ax){
    case BESIDE:
        return (0 <= y) && (y < mazeSize+1) && (0 <= x) && (x < mazeSize);
    case VERTICAL:
        return (0 <= y) && (y < mazeSize) && (0 <= x) && (x < mazeSize+1);
    default:
        qDebug("Axis does not exit");
        return false;
    }
}


