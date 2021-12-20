#include "wallitem.h"

WallItem::WallItem()
    :existsState(false),lockedState(false),pen(new QPen)
{

}


bool WallItem::getwallExists(){
    /*
    get the status of the wall exists.

    return
    ------
    bool exists
    */
    return existsState;
}

bool WallItem::setWallExists(bool exists){
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

bool WallItem::setWallLocked(bool locked){
    /*
    set the status of the wall exists.

    return
    ------
    bool lockSuccess
    */
    lockedState = locked;
    return true;
}

void WallItem::setWallWidth(int width){
    /*
    Set the drawing width of the wall.

    return
    ------

    */
    pen->setWidth(width);
    this->setPen(*pen);
}

void WallItem::upDateWallBrush(){
    /*
    Update brushes according to wall conditions.

    return
    ------

    */
    if(existsState){
        pen->setBrush(Qt::red);
    }else{
        pen->setBrush(Qt::gray);
    }
    this->setPen(*pen);
}
