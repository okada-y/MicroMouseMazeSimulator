#ifndef MAZE_H
#define MAZE_H

/**
* @file Maze.h
* @brief マイクロマウスの迷路クラスを定義
* @author y okada
* @date 2021.12.22
*/
#include <vector>
#include <iterator>

#define MAX_MAZE_SIZE 32
enum{BESIDE,VERTICAL,NUM_OF_DIM};

using std::vector;

template <class mazeSize_t>
class Maze
{

public:
    Maze(int size = MAX_MAZE_SIZE);
    int getMazeSize(){return mazeSize;}
    const vector<vector<mazeSize_t>>* getWallData(){return &wall;}
    const vector<vector<mazeSize_t>>* getWallKnownData(){return &wallknown;}
    void setWallData(vector<vector<mazeSize_t>> &wallData);
    void setWallKnownData(vector<vector<mazeSize_t>> &wallKnownData);

private:
    int mazeSize;
    vector<vector<mazeSize_t>> wall;
    vector<vector<mazeSize_t>> wallknown;
};

template <class mazeSize_t>
Maze<mazeSize_t>::Maze(int size)
{
    mazeSize = size;

    //壁格納配列の初期化
    wall.resize(2,vector<mazeSize_t>(mazeSize-1,0));
    wallknown.resize(2,vector<mazeSize_t>(mazeSize-1,0));
}

template <class mazeSize_t>
void Maze<mazeSize_t>::setWallData(vector<vector<mazeSize_t>> &wallData){
    /*
    Set the wall data vector.

    return
    ------

    */
    wall = wallData;
}


#endif // MAZE_H
