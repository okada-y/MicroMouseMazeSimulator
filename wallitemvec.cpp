#include "wallitemvec.h"

WallItemVec::WallItemVec(int xSize, int ySize):
    besideItemVec(ySize+1,std::vector<WallItem*>(xSize, nullptr)),
    verticalItemVec(ySize,std::vector<WallItem*>(xSize+1, nullptr))
{
    //横壁ポインタの初期化
    for(int y = 0; y <= ySize; y++){
        for(int x = 0; x < xSize; x++){
            besideItemVec.at(y).at(x) = new WallItem;
        }
    }

    //縦壁ポインタの初期化
    for(int y = 0; y < ySize; y++){
        for(int x = 0; x <= xSize; x++){
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
    size_t xSize; //X方向壁の枚数
    size_t ySize; //Y方向壁の枚数

    switch(ax){
    case BESIDE:
        ySize = besideItemVec.size();
        xSize = besideItemVec.at(0).size();
        return (0 <= y) && (y <= ySize) && (0 <= x) && (x <= xSize);
    case VERTICAL:
        ySize = verticalItemVec.size();
        xSize = verticalItemVec.at(0).size();
        return (0 <= y) && (y <= ySize) && (0 <= x) && (x <= xSize);
    default:
        qDebug("Axis does not exit");
        return false;
    }
}

void WallItemVec::drawItemVec(MazeScene *scene, WallDesign *design){
    /*
    draw a wall vector in the scene

    return
    ------

    */
    //横壁の描画
    size_t bYSize = besideItemVec.size();
    size_t bXSize = besideItemVec.at(0).size();
    for(int y=0; y<bYSize; y++){
        for(int x=0; x<bXSize; x++){
            besideItemVec.at(y).at(x)->
                    setLine(QLineF(design->wallLength * x + design->wallWidth    , design->wallLength * y,
                                   design->wallLength * (x+1) - design->wallWidth, design->wallLength * y));
            besideItemVec.at(y).at(x)->setWidth(design->wallWidth);
            besideItemVec.at(y).at(x)->upDateBrush();
            scene->addItem(besideItemVec.at(y).at(x));
        }
    }

    //縦壁の描画
    size_t vYSize = verticalItemVec.size();
    size_t vXSize = verticalItemVec.at(0).size();
    for(int y=0; y<vYSize; y++){
        for(int x=0; x<vXSize; x++){
            verticalItemVec.at(y).at(x)->
                    setLine(QLineF(design->wallLength * x, design->wallLength * y + design->wallWidth,
                                   design->wallLength * x, design->wallLength * (y+1) - design->wallWidth));
            verticalItemVec.at(y).at(x)->setWidth(design->wallWidth);
            verticalItemVec.at(y).at(x)->upDateBrush();
            scene->addItem(verticalItemVec.at(y).at(x));
        }
    }
}

