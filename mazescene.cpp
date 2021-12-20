#include "mazescene.h"


MazeScene::MazeScene(QObject *parent)
    : QGraphicsScene{parent}
{
    //this->setBackgroundBrush(Qt::gray);
}

void MazeScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QPointF pos = event->scenePos();
    qDebug("scenePos x = %f, y = %f", pos.x(), pos.y());
    QGraphicsItem *pItem = itemAt(pos, QTransform());
    if(pItem == NULL){
        qDebug("no object here");
        return;
    }
    switch (pItem->type()) {
        case QGraphicsTextItem::Type :
            qDebug("this is text");
            break;

        case QGraphicsRectItem::Type :
            qDebug("this is rect");
            break;

        case QGraphicsLineItem::Type :
            qDebug("this is line");
            break;

        case WallItem::Type :
            qDebug("this is wall");
//            WallItem *temp = qgraphicsitem_cast<WallItem*>(pItem);
//            QPen *pen = new QPen;
//            pen->setWidth(5);
//            pen->setBrush(Qt::gray);
//            temp->setPen(*pen);
            break;
    }
}

