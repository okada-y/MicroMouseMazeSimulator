﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtCore/QDebug>
#include <QFile>
#include <QMessageBox>

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
    /*
    Output drawing wall as text data

    Return
    ------

    */
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
    /*
    Output text data to a file

    Return
    ------

    */
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "C:/Users/yokad/Documents/Qt/mazeData/untitle.txt",
                               tr("Text (*.txt)"));
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly)){
            QMessageBox::critical(this, tr("Error"), tr("This System could not open File"));
            return;
        }

        QTextStream stream(&file);
        stream << *(text->getText()) << endl;
    }
}

