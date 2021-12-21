﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    maze = new Maze;
    scene = new MazeScene;
    wall = new WallItemVec(maze->getXSize(),maze->getYSize());
    wallDesign = new WallDesign;
    pillar = new PillarItemVec(maze->getXSize(),maze->getYSize());
    wall->drawItemVec(scene,wallDesign);
    pillar->drawItemVec(scene,wallDesign);
//    MazeDraw *mDraw = new MazeDraw(scene, wall);

//    //シーンにアイテムを追加
//    QPen *pen = new QPen;
//    pen->setWidth(5);
//    pen->setBrush(Qt::red);
//    for(int i=0; i<3; i++){
//        WallItem *wall = new WallItem;
//        wall->setLine(QLineF(100*(i+1), 100, 100*(i+1), 200));
//        wall->setPen(*pen);
//        scene->addItem(wall);
//    }
    //シーンをビューにセット
    ui->MazeView->setScene(scene);
}

