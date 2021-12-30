#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mazeDraw/mazescene.h"
#include "mazeDraw/wallitemvec.h"
#include "mazeDraw/pillaritemvec.h"
#include "mazeText/mazetext.h"

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

private:
    Ui::MainWindow *ui;
    void init();
    MazeScene *scene;
    MazeText *text;
    void* mazetemp;
};
#endif // MAINWINDOW_H
