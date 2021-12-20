#include "mazedraw.h"

MazeDraw::MazeDraw()
{
}

MazeDraw::MazeDraw(MazeScene* scene, WallItemVec* itemVec){
    mScene = scene;
    mItemVec = itemVec;
    init();
}

void MazeDraw::init(){
    /*
    Initial processing of maze drawing

    return
    ------
    */
}

void MazeDraw::drawPillers(){
    /*
    draw Pillers in the scene

    return
    ------
    */
    for(int i = 0; i<=32; i++){
        for(int j = 0; j <= 32; j++){
            QGraphicsRectItem *temp = new QGraphicsRectItem(j*pillerSpacing, i*pillerSpacing, pillerWidth, pillerWidth);
            temp->setBrush(Qt::gray);
            mScene->addItem(temp);
        }
    }
}

void MazeDraw::drawCoordinates(){
    /*
    draw Coordinates in the scene

    return
    ------
    */
    //左縦
    for(int i = 0; i < 32; i++){
       QGraphicsTextItem *temp = new QGraphicsTextItem(QString::number(i));
       temp->setPos(-pillerSpacing,pillerSpacing*(31-i+0.35));
       mScene->addItem(temp);
    }

    //右縦
    for(int i = 0; i < 32; i++){
       QGraphicsTextItem *temp = new QGraphicsTextItem(QString::number(i));
       temp->setPos(pillerSpacing*32.5,pillerSpacing*(31-i+0.35));
       mScene->addItem(temp);
    }
    //上横
    for(int i = 0; i < 32; i++){
       QGraphicsTextItem *temp = new QGraphicsTextItem(QString::number(i));
       temp->setPos(pillerSpacing*(i+0.35),-pillerSpacing);
       mScene->addItem(temp);
    }
    //下横
    for(int i = 0; i < 32; i++){
       QGraphicsTextItem *temp = new QGraphicsTextItem(QString::number(i));
       temp->setPos(pillerSpacing*(i+0.35),pillerSpacing*32.5);
       mScene->addItem(temp);
    }
}

QPen* MazeDraw::getWallPen(bool wallExists){
    QPen *pen = new QPen;
    pen->setWidth(wallWidth);
    if(wallExists){
        pen->setBrush(Qt::red);
    }else{
        pen->setBrush(Qt::gray);
    }
    return pen;
}



