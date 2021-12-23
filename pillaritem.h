#ifndef PILLARITEM_H
#define PILLARITEM_H

#include <QGraphicsRectItem>
#include <QPen>

class PillarItem : public QGraphicsRectItem
{
public:
    PillarItem();
    enum{ Type = UserType + 2};
    int type() const override { return Type; }

    bool getExists();       //柱の有無を取得
    bool setExists(bool);   //柱の有無を操作
    void setLocked(bool);   //アイテムの編集可否を操作
    void setSize(int size);
    void upDateBrush();
    void toggleExists();

private:
    bool existsState;
    bool lockedState;
};

#endif // PILLARITEM_H
