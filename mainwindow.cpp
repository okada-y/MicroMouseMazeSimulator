#include "mainwindow.h"
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

    ui->inputFileName->setReadOnly(true);
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
    scene->setMazeFromWall();   //描画されている壁を壁データとして保存
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


void MainWindow::on_selectFileButton_clicked()
{
    /*
    Select and read text data files

    Return
    ------

    */
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                               "C:/Users/yokad/Documents/Qt/mazeData/untitle.txt",
                               tr("Text (*.txt)"));
    if(!fileName.isEmpty()){
        ui->inputFileName->setText(fileName); //読みとるファイル名を出力
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this, tr("Error"), tr("This System could not open File"));
            return;
        }

        QTextStream stream(&file);
        QString data = stream.readAll();

        text->clearText();          //壁テキストデータをクリア
        text->setText(&data);       //読み取ったテキストデータを壁テキストデータにセット
        ui->mazeTextBrowser->setText(*(text->getText()));  //壁テキストデータをブラウザに出力

        QStringList list = data.split(' ');
        int size = (list.size()-1)/2;

        /*壁テキストデータを壁データに変換*/
        if(15 < size){
            Maze<uint32_t> *tmpMazeP = static_cast<Maze<uint32_t>*>(scene->getMazeClassP());
            vector<vector<uint32_t>> tmpWallData = text->text2Vec<uint32_t>();
            tmpMazeP->setWallData(tmpWallData);
        }else if(7 < size){

        }else{

        }

        /*壁描画更新*/

    }
}

