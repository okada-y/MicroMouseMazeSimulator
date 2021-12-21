#include "pillaritemvec.h"

PillarItemVec::PillarItemVec(int xSize, int ySize):
    itemVec(ySize+1,std::vector<PillarItem*>(xSize+1, nullptr))
{
    //柱ポインタの初期化
    for(int y = 0; y <= ySize; y++){
        for(int x = 0; x <= xSize; x++){
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


void PillarItemVec::drawItemVec(MazeScene *scene, WallDesign *design){
    /*
    draw a pillar vector in the scene

    return
    ------

    */
    //横壁の描画
    size_t ySize = itemVec.size();
    size_t xSize = itemVec.at(0).size();
    for(int y=0; y<ySize; y++){
        for(int x=0; x<xSize; x++){
            itemVec.at(y).at(x)->setSize(design->wallWidth);
            itemVec.at(y).at(x)->setPos((design->wallLength)* x -(design->wallWidth/2),
                                        (design->wallLength)* y -(design->wallWidth/2));
            itemVec.at(y).at(x)->upDateBrush();
            scene->addItem(itemVec.at(y).at(x));
        }
    }
}
