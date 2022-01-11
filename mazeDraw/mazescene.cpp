#include "mazescene.h"
#include <typeinfo>

MazeScene::MazeScene(int size, QObject *parent)
    : QGraphicsScene{parent}
{
    this->setBackgroundBrush(QColor(255, 255, 250, 255));

    //迷路サイズに応じた迷路,柱,壁クラスのインスタンス化
    if((size < 0) && (MAX_MAZE_SIZE < size)){
        qDebug("Out of range of maze size.");
        return;
    }
    mazeSize = size;
    wall = new WallItemVec(mazeSize);
    pillar = new PillarItemVec(mazeSize);

    //壁、柱の描画
    wallWidth = 3 * MAX_MAZE_SIZE / size;
    wallLength = 27 * MAX_MAZE_SIZE / size;
    drawWallItemVec(wall, wallWidth, wallLength);
    drawPillarlItemVec(pillar, wallWidth, wallLength);
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

void MazeScene::upDataWallBrush(){

    //横壁の描画更新
    size_t bYSize = wall->besideItemVec.size();
    size_t bXSize = wall->besideItemVec.at(0).size();
    for(int y=0; y<bYSize; y++){
        for(int x=0; x<bXSize; x++){
            wall->besideItemVec.at(y).at(x)->upDateBrush();
        }
    }

    //縦壁の描画更新
    size_t vYSize = wall->verticalItemVec.size();
    size_t vXSize = wall->verticalItemVec.at(0).size();
    for(int y=0; y<vYSize; y++){
        for(int x=0; x<vXSize; x++){
            wall->verticalItemVec.at(y).at(x)->upDateBrush();
        }
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



