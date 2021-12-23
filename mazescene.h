/**
 * @file      mazescene.h
 * @brief     迷路描画シーンクラス
 * @note      壁、柱アイテムクラス、迷路データを保有
 * @author    yasuhiro okada
 */
#ifndef MAZESCENE_H
#define MAZESCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include "wallitem.h"
#include "wallitemvec.h"
#include "walldesign.h"
#include "pillaritem.h"
#include "pillaritemvec.h"
#include "maze.h"

class MazeScene : public QGraphicsScene
{

public:
    explicit MazeScene(int mazeSize = MAX_MAZE_SIZE, QObject *parent = nullptr);

private:
    WallItemVec *wall;
    PillarItemVec *pillar;
    Maze<uint8_t> *maze_8;
    Maze<uint16_t> *maze_16;
    Maze<uint32_t> *maze_32;

    int wallWidth;
    int wallLength;

    void drawWallItemVec(WallItemVec *wall, int width, int length);
    void drawPillarlItemVec(PillarItemVec *pillar, int width, int length);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // MAZESCENE_H
