#ifndef MAZE_H
#define MAZE_H

/**
* @file Maze.h
* @brief マイクロマウスの迷路クラスを定義
* @author y okada
* @date 2021.12.22
*/
#include <vector>

#define MAX_MAZE_SIZE 32

template <class mazeSize_t>
class Maze
{
public:
    Maze(int size = MAX_MAZE_SIZE);
    int getMazeSize(){return mazeSize;}
private:
    int mazeSize;
    std::vector<std::vector<mazeSize_t>> wall;
    std::vector<std::vector<mazeSize_t>> wallknown;
};


template <class mazeSize_t>
Maze<mazeSize_t>::Maze(int size)
{
    mazeSize = size;

    //壁格納配列の初期化
    wall.resize(2,std::vector<mazeSize_t>(mazeSize-1,0));
    wallknown.resize(2,std::vector<mazeSize_t>(mazeSize-1,0));
}

#endif // MAZE_H
