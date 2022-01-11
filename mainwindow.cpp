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

    ui->inputFileName->setReadOnly(true);   //インプットファイル表示部をリードオンリーに設定
    text = new MazeText();  //迷路テキストデータインスタンス生成
    mazeSize = ui->mazeSize_comboBox->currentText().toInt();//コンボボックスの値をもとに迷路サイズを設定
    scene = new MazeScene(mazeSize);    //迷路描画用シーンインスタンス生成
    ui->MazeView->setScene(scene);  //シーンをビューにセット

    //mazeインスタンスの生成
    if(mazeSize > 16){
        maze_32 = new Maze<uint32_t>;
    }else if(mazeSize > 8){
        maze_16 = new Maze<uint16_t>;
    }else{
        maze_8 = new Maze<uint8_t>;
    }

}


void MainWindow::on_getMazeDataButton_clicked()
{
    /*
    Output drawing wall as text data

    Return
    ------

    */

    text->clearText();//壁情報を記すテキストをクリア

    /*描画されている壁を壁データとして保存 */
    /*壁データをテキストに変換 */
    if((mazeSize > 16) && (maze_32 != nullptr)){
        scene->setMazeFromWall<uint32_t>(maze_32);
        text->vec2Text<uint32_t>(*(maze_32->getWallData()));
    }else if((mazeSize > 8) && (maze_16 != nullptr)){
        scene->setMazeFromWall<uint16_t>(maze_16);
        text->vec2Text<uint16_t>(*(maze_16->getWallData()));
    }else if(maze_8 != nullptr){
        scene->setMazeFromWall<uint8_t>(maze_8);
        text->vec2Text<uint8_t>(*(maze_8->getWallData()));
    }else{
        //何もしない
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
        /*壁描画データ更新*/
        if((15 < size) && (maze_32 != nullptr)){
            vector<vector<uint32_t>> tmpWallData = text->text2Vec<uint32_t>();
            maze_32->setWallData(tmpWallData);
            scene->setWallFromMaze(maze_32);
        }else if((7 < size) && (maze_16 != nullptr)){
            vector<vector<uint16_t>> tmpWallData = text->text2Vec<uint16_t>();
            maze_16->setWallData(tmpWallData);
            scene->setWallFromMaze(maze_16);
        }else if(maze_8 != nullptr){
            vector<vector<uint8_t>> tmpWallData = text->text2Vec<uint8_t>();
            maze_8->setWallData(tmpWallData);
            scene->setWallFromMaze(maze_8);
        }else{
            //何もしない
        }

        //壁描画の更新
        scene->upDataWallBrush();
    }
}

