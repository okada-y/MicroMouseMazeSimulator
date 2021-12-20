#include "wallitemvec.h"

WallItemVec::WallItemVec(int xSize, int ySize):
    besideWallItemVec(ySize+1,std::vector<WallItem*>(xSize, nullptr)),
    verticalWallItemVec(ySize,std::vector<WallItem*>(xSize+1, nullptr))
{
    /*
    Default Constructor
    */

    //横壁ポインタの初期化
    for(int y = 0; y <= ySize; y++){
        for(int x = 0; x < xSize; x++){
            besideWallItemVec.at(y).at(x) = new WallItem;
        }
    }

    //縦壁ポインタの初期化
    for(int y = 0; y < ySize; y++){
        for(int x = 0; x <= xSize; x++){
            verticalWallItemVec.at(y).at(x) = new WallItem;
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
        besideWallItemVec.at(y).at(x)->setWallExists(exists);
        break;
    case VERTICAL:
        verticalWallItemVec.at(y).at(x)->setWallExists(exists);
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
        return besideWallItemVec.at(y).at(x)->getwallExists();
    case VERTICAL:
        return verticalWallItemVec.at(y).at(x)->getwallExists();
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
    size_t xSize; //X方向壁の枚数
    size_t ySize; //Y方向壁の枚数

    switch(ax){
    case BESIDE:
        ySize = besideWallItemVec.size();
        xSize = besideWallItemVec.at(0).size();
        return (0 <= y) && (y <= ySize) && (0 <= x) && (x <= xSize);
    case VERTICAL:
        ySize = verticalWallItemVec.size();
        xSize = verticalWallItemVec.at(0).size();
        return (0 <= y) && (y <= ySize) && (0 <= x) && (x <= xSize);
    default:
        qDebug("Axis does not exit");
        return false;
    }
}

void WallItemVec::drawWallItemVec(MazeScene *scene, WallDesign *design){
    /*
    draw a wall vector in the scene

    return
    ------

    */
    //横壁の描画
    size_t bYSize = besideWallItemVec.size();
    size_t bXSize = besideWallItemVec.at(0).size();
    for(int y=0; y<bYSize; y++){
        for(int x=0; x<bXSize; x++){
            besideWallItemVec.at(y).at(x)->
                    setLine(QLineF(design->wallLength * x + design->wallWidth    , design->wallLength * y,
                                   design->wallLength * (x+1) - design->wallWidth, design->wallLength * y));
            besideWallItemVec.at(y).at(x)->setWallWidth(design->wallWidth);
            besideWallItemVec.at(y).at(x)->upDateWallBrush();
            scene->addItem(besideWallItemVec.at(y).at(x));
        }
    }

    //縦壁の描画
    size_t vYSize = verticalWallItemVec.size();
    size_t vXSize = verticalWallItemVec.at(0).size();
    for(int y=0; y<vYSize; y++){
        for(int x=0; x<vXSize; x++){
            verticalWallItemVec.at(y).at(x)->
                    setLine(QLineF(design->wallLength * x, design->wallLength * y + design->wallWidth,
                                   design->wallLength * x, design->wallLength * (y+1) - design->wallWidth));
            verticalWallItemVec.at(y).at(x)->setWallWidth(design->wallWidth);
            verticalWallItemVec.at(y).at(x)->upDateWallBrush();
            scene->addItem(verticalWallItemVec.at(y).at(x));
        }
    }
}

