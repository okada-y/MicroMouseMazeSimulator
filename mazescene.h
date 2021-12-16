﻿#ifndef MAZESCENE_H
#define MAZESCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

class MazeScene : public QGraphicsScene
{
public:
    explicit MazeScene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MAZESCENE_H