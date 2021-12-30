#include "pillaritemvec.h"

PillarItemVec::PillarItemVec(int size):
    itemVec(size+1,std::vector<PillarItem*>(size+1, nullptr))
{
    //柱ポインタの初期化
    for(int y = 0; y <= size; y++){
        for(int x = 0; x <= size; x++){
            itemVec.at(y).at(x) = new PillarItem();
        }
    }
}

bool PillarItemVec::isInsideOfField(int x, int y){
    /*
    determin if the pillar is inside of the field

    Return
    ------
    bool result
    */
    size_t xSize; //X方向柱の本数
    size_t ySize; //Y方向柱の本数
    ySize = itemVec.size();
    xSize = itemVec.at(0).size();
    return (0 <= x) && (0 <= y) && (x <= xSize) && (y <= ySize);
}

void PillarItemVec::setExists( int x, int y, bool exists){
    /*
    Set the existence of the pillar stored in the vector.

    Return
    ------

    */
    if(!isInsideOfField(x,y)){
        qDebug("not inside of field");
        return;
    }
    itemVec.at(y).at(x)->setExists(exists);
}

bool PillarItemVec::getExists(int x, int y){
    /*
    Get the existence of the wall stored in the vector.

    Return
    ------
    bool existence
    */

    if(!isInsideOfField(x,y)){
        qDebug("not inside of field");
        return false;
    }
    return itemVec.at(y).at(x)->getExists();
}
