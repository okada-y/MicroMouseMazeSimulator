#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wallitemvec.h"

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
    scene = new MazeScene(16); //迷路サイズを設定して迷路描画用シーンを初期化
    ui->MazeView->setScene(scene); //シーンをビューにセット
}


void MainWindow::on_getMazeDataButton_clicked()
{
    scene->setMazefromWall();
}

