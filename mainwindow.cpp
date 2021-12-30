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

    text = new MazeText();
    //迷路サイズコンボボックスの値をもとに迷路サイズを設定して迷路描画用シーンを初期化
    scene = new MazeScene(ui->mazeSize_comboBox->currentText().toInt());

    //シーンをビューにセット
    ui->MazeView->setScene(scene);
}


void MainWindow::on_getMazeDataButton_clicked()
{
    scene->setMazefromWall();   //描画されている壁を壁データとして保存
    text->clearText();          //壁情報を記すテキストをクリア

    /*壁データをテキストに変換 */
    if(16 < scene->getMazeSize()){
        Maze<uint32_t> *temp = static_cast<Maze<uint32_t>*>(scene->getMazeClassP());
        text->vec2Text<uint32_t>(*(temp->getWallData()));
    }else if(8 < scene->getMazeSize()){
        Maze<uint16_t> *temp = static_cast<Maze<uint16_t>*>(scene->getMazeClassP());
        text->vec2Text<uint16_t>(*(temp->getWallData()));
    }else{
        Maze<uint16_t> *temp = static_cast<Maze<uint16_t>*>(scene->getMazeClassP());
        text->vec2Text<uint16_t>(*(temp->getWallData()));
    }
    /*テキストをブラウザにセット*/
    ui->mazeTextBrowser->setText(*(text->getText()));
}


void MainWindow::on_mazeSize_comboBox_currentIndexChanged(int index)
{

}


void MainWindow::on_SaveButton_clicked()
{

}

