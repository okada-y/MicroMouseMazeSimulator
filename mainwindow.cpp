#include "mainwindow.h"
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
    maze = new Maze<unsigned int>;
    scene = new MazeScene;
    wall = new WallItemVec(maze->getMazeSize());
    wallDesign = new WallDesign;
    pillar = new PillarItemVec(maze->getMazeSize());
    wall->drawItemVec(scene,wallDesign);
    pillar->drawItemVec(scene,wallDesign);

    //シーンをビューにセット
    ui->MazeView->setScene(scene);
}

