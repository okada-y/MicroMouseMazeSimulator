#include "mazescene.h"
#include <typeinfo>

MazeScene::MazeScene(int size, QObject *parent)
    : QGraphicsScene{parent},
      wallWidth(3),wallLength(27)
{
    this->setBackgroundBrush(QColor(255, 255, 250, 255));

    //迷路サイズに応じた迷路,柱,壁クラスのインスタンス化
    if((size < 0) && (MAX_MAZE_SIZE < size)){
        qDebug("Out of range of maze size.");
        return;
    }

    mazeSize = size;
    if(16 < mazeSize){
        maze_32 = new Maze<uint32_t>(mazeSize);
        wall = new WallItemVec(maze_32->getMazeSize());
        pillar = new PillarItemVec(maze_32->getMazeSize());
    }else if(8 < mazeSize){
        maze_16 = new Maze<uint16_t>(mazeSize);
        wall = new WallItemVec(maze_16->getMazeSize());
        pillar = new PillarItemVec(maze_16->getMazeSize());
    }else{
        maze_8 = new Maze<uint8_t>(mazeSize);
        wall = new WallItemVec(maze_8->getMazeSize());
        pillar = new PillarItemVec(maze_8->getMazeSize());
    }

    //壁、柱の描画
    drawWallItemVec(wall, wallWidth, wallLength);
    drawPillarlItemVec(pillar, wallWidth, wallLength);
}

void MazeScene::setMazefromWall(){
    /*
     * Set the drawing wall data to the maze data.
     *
     * return
     * ------
     *
     */
    if(16 < mazeSize){
        vector<vector<uint32_t>> tmp(2, vector<uint32_t>(mazeSize - 1));
        tmp = wall->getExistsVec<uint32_t>();
        maze_32->setWallData(tmp);
    }else if(8 < mazeSize){
        vector<vector<uint16_t>> tmp(2, vector<uint16_t>(mazeSize - 1));
        tmp = wall->getExistsVec<uint16_t>();
        maze_16->setWallData(tmp);
    }else{
        vector<vector<uint8_t>> tmp(2, vector<uint8_t>(mazeSize - 1));
        tmp = wall->getExistsVec<uint8_t>();
        maze_8->setWallData(tmp);
    }

}

void* MazeScene::getMazeClassP(){
    /*
     * Return the maze class according to the maze size.
     *
     * return
     * ------
     * mazeClass *
     */
    if(16 < mazeSize){
        return maze_32;
    }else if(8 < mazeSize){
        return maze_16;
    }else{
        return maze_8;
    }
}

void MazeScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QPointF pos = event->scenePos();
    //qDebug("scenePos x = %f, y = %f", pos.x(), pos.y());
    QGraphicsItem *pItem = itemAt(pos, QTransform());
    if(pItem == NULL){
        //qDebug("no object here");
        return;
    }
    switch (pItem->type()) {
        //壁オブジェクトクリック時の処理
        case WallItem::Type :
            //qDebug("this is wall");
            qgraphicsitem_cast<WallItem*>(pItem)->toggleExists();
            qgraphicsitem_cast<WallItem*>(pItem)->upDateBrush();
            break;
        //柱オブジェクトクリック時の処理
        case PillarItem::Type :
            qgraphicsitem_cast<PillarItem*>(pItem)->toggleExists();
            qgraphicsitem_cast<PillarItem*>(pItem)->upDateBrush();
            break;
    }
}

void MazeScene::drawWallItemVec(WallItemVec *wall, int width, int length){
    /*
    draw a wall vector in the scene

    return
    ------

    */
    //横壁の描画
    size_t bYSize = wall->besideItemVec.size();
    size_t bXSize = wall->besideItemVec.at(0).size();
    for(int y=0; y<bYSize; y++){
        for(int x=0; x<bXSize; x++){
            wall->besideItemVec.at(y).at(x)->
                    setLine(QLineF(length * x + width    , length * y,
                                   length * (x+1) - width, length * y));
            wall->besideItemVec.at(y).at(x)->setWidth(width);
            wall->besideItemVec.at(y).at(x)->upDateBrush();
            this->addItem(wall->besideItemVec.at(y).at(x));
        }
    }

    //縦壁の描画
    size_t vYSize = wall->verticalItemVec.size();
    size_t vXSize = wall->verticalItemVec.at(0).size();
    for(int y=0; y<vYSize; y++){
        for(int x=0; x<vXSize; x++){
            wall->verticalItemVec.at(y).at(x)->
                    setLine(QLineF(length * x, length * y + width,
                                   length * x, length * (y+1) - width));
            wall->verticalItemVec.at(y).at(x)->setWidth(width);
            wall->verticalItemVec.at(y).at(x)->upDateBrush();
            this->addItem(wall->verticalItemVec.at(y).at(x));
        }
    }
}

void MazeScene::drawPillarlItemVec(PillarItemVec *pillar, int width, int length){
    /*
    draw a pillar vector in the scene

    return
    ------

    */
    //横壁の描画
    size_t ySize = pillar->itemVec.size();
    size_t xSize = pillar->itemVec.at(0).size();
    for(int y=0; y<ySize; y++){
        for(int x=0; x<xSize; x++){
            pillar->itemVec.at(y).at(x)->setSize(width);
            pillar->itemVec.at(y).at(x)->setPos((length)* x -(width/2),
                                        (length)* y -(width/2));
            pillar->itemVec.at(y).at(x)->upDateBrush();
            this->addItem(pillar->itemVec.at(y).at(x));
        }
    }
};



