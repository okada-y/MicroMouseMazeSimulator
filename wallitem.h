#ifndef WALLITEM_H
#define WALLITEM_H

#include <QGraphicsLineItem>
#include <QObject>
#include <QWidget>

class WallItem : public QGraphicsLineItem
{

public:
    WallItem();
    //アイテムタイプをユーザタイプ+1に設定
    enum{ Type = UserType + 1};
    int type() const override { return Type; }
};

#endif // WALLITEM_H
