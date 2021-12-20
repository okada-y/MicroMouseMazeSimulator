#ifndef MAZE_H
#define MAZE_H


class Maze
{
public:
    Maze();
    const int getXSize();
    const int getYSize();

private:
    int xSize;    //迷路行方向サイズ//
    int ySize;    //迷路縦方向サイズ//
};

#endif // MAZE_H
