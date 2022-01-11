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
#include "pillaritem.h"
#include "pillaritemvec.h"
#include "maze.h"


class MazeScene : public QGraphicsScene
{

public:
    explicit MazeScene(int size = MAX_MAZE_SIZE, QObject *parent = nullptr);
    template<class mazeSize_t> void setMazeFromWall(Maze<mazeSize_t>*maze);
    template<class mazeSize_t> void setWallFromMaze(Maze<mazeSize_t>*maze);
    const int getMazeSize(){return mazeSize;}
    void upDataWallBrush();

private:
    WallItemVec *wall;
    PillarItemVec *pillar;

    int wallWidth;
    int wallLength;
    int mazeSize;

    void drawWallItemVec(WallItemVec *wall, int width, int length);
    void drawPillarlItemVec(PillarItemVec *pillar, int width, int length);
    void drawCoordinates(int width, int length);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

template<class mazeSize_t>
void MazeScene::setMazeFromWall(Maze<mazeSize_t> *maze){
    /*
     * Set the drawing wall data to the maze data.
     *
     * return
     * ------
     *
     */
    vector<vector<mazeSize_t>> tmp(2, vector<mazeSize_t>(mazeSize - 1));
    tmp = wall->getExistsVec<mazeSize_t>();
    maze->setWallData(tmp);
}

template<class mazeSize_t>
void MazeScene::setWallFromMaze(Maze<mazeSize_t> *maze){
    /*
     * Set the maze data to the drawing wall data.
     *
     * return
     * ------
     * void
     */
    const vector<vector<mazeSize_t>> *tmp;
    tmp = maze->getWallData();
    wall->setExistsVec(*tmp);
}

#endif // MAZESCENE_H
