#include "mazescene.h"


MazeScene::MazeScene(QObject *parent)
    : QGraphicsScene{parent}
{
    this->setBackgroundBrush(QColor(255, 255, 250, 255));
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

