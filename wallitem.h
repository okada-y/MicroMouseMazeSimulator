/**
 * @file      wallitem.h
 * @brief     壁描画アイテムクラス
 * @note      壁の有無状態を保有、編集可否フラグによって操作を制限
 * @author    yasuhiro okada
 */

#ifndef WALLITEM_H
#define WALLITEM_H

#include <QGraphicsLineItem>
#include <QObject>
#include <QWidget>
#include <QPen>
#include <QBrush>

class WallItem : public QGraphicsLineItem
{

public:
    //コンストラクタ
    WallItem();

    //アイテムタイプをユーザタイプ+1に設定
    enum{ Type = UserType + 1};
    int type() const override { return Type; }

    bool getExists();       //壁の有無を取得
    bool setExists(bool);   //壁の有無を操作
    bool setLocked(bool);   //アイテムの編集可否を操作
    void setWidth(int width);
    void upDateBrush();

private:
    bool existsState; //壁の有無の状態
    bool lockedState; //壁編集可否の状態
    QPen *pen;
};

#endif // WALLITEM_H
