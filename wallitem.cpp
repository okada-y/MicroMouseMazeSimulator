#include "wallitem.h"

WallItem::WallItem()
    :existsState(false),lockedState(false),pen(new QPen)
{

}


bool WallItem::getExists(){
    /*
    get the status of the wall exists.

    return
    ------
    bool exists
    */
    return existsState;
}

bool WallItem::setExists(bool exists){
    /*
    set the status of the wall exists.

    return
    ------
    bool editSuccess
    */
    if(!lockedState){
        return false;
    }
    existsState = exists;
    return true;
}

bool WallItem::setLocked(bool locked){
    /*
    set the status of the wall exists.

    return
    ------
    bool lockSuccess
    */
    lockedState = locked;
    return true;
}

void WallItem::setWidth(int width){
    /*
    Set the drawing width of the wall.

    return
    ------

    */
    pen->setWidth(width);
    this->setPen(*pen);
}

void WallItem::upDateBrush(){
    /*
    Update brushes according to wall conditions.

    return
    ------

    */
    QBrush brush;

    if(existsState){
        brush.setColor(QColor(255, 60, 60, 255));
        brush.setStyle(Qt::SolidPattern);
    }else{
        brush.setColor(Qt::gray);
        brush.setStyle(Qt::Dense4Pattern);
    }
    pen->setBrush(brush);
    this->setPen(*pen);
}
