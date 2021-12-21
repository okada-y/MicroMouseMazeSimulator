#include "pillaritem.h"

PillarItem::PillarItem()
    :existsState(false),lockedState(false)
{
}

bool PillarItem::getExists(){
    /*
    get the status of the pillar exists.

    return
    ------
    bool pillar exists
    */
    return existsState;
}

bool PillarItem::setExists(bool exists){
    /*
    set the status of the pillar exists.

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

void PillarItem::setLocked(bool locked){
    /*
    set the status of the pillar locked.

    return
    ------

    */
    lockedState = locked;
}

void PillarItem::setSize(int size){
    /*
    Set the drawing size of the pillar.

    return
    ------

    */
    this->setRect(0,0,size,size);
}

void PillarItem::upDateBrush(){
    /*
    Update brushes according to wall conditions.

    return
    ------

    */
    QPen *pen = new QPen;
    if(existsState){
        this->setBrush(Qt::gray);
        pen->setColor(Qt::gray);
        pen->setStyle(Qt::SolidLine);

    }else{
        this->setBrush(Qt::NoBrush);
        pen->setColor(Qt::gray);
        pen->setStyle(Qt::DotLine);
    }
    this->setPen(*pen);
}
