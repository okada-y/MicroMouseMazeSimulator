#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mazeDraw/mazescene.h"
#include "mazeDraw/wallitemvec.h"
#include "mazeDraw/pillaritemvec.h"
#include "mazeText/mazetext.h"
#include "maze.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_getMazeDataButton_clicked();

    void on_mazeSize_comboBox_currentIndexChanged(int index);

    void on_SaveButton_clicked();

    void on_selectFileButton_clicked();

private:
    void init();
    Ui::MainWindow *ui;
    MazeScene *scene;
    MazeText *text;
    Maze<uint8_t> *maze_8;
    Maze<uint16_t> *maze_16;
    Maze<uint32_t> *maze_32;
    void* mazetemp;
    int mazeSize;
};
#endif // MAINWINDOW_H
