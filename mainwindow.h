#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mazescene.h"
#include "wallitemvec.h"
#include "mazedraw.h"
#include "walldesign.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void init();
    MazeScene *scene;
    WallItemVec *wall;
    WallDesign *wallDesign;
};
#endif // MAINWINDOW_H
