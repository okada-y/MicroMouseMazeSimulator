/**
 * @file      wallitem.h
 * @date      2021/12/18
 * @brief     壁描画アイテム配列管理クラス
 * @note      壁アイテムクラスポインタを配列で管理
 *            (32*32のみ対応)
 * @author    yasuhiro okada
 */

#ifndef WALLITEMVEC_H
#define WALLITEMVEC_H

#include "wallitem.h"
#include "../maze.h"
#include <vector>

class WallItemVec
{
public:
    WallItemVec(int size = MAX_MAZE_SIZE);
    enum{BESIDE,VERTICAL,MAX_WALLITE_DIM};

    void setExists(int ax, int x, int y, bool exists);
    bool getExists(int ax, int x, int y);
    bool isInsideOfField(int ax, int x, int y);
    template <class mazeSize_t>
    vector<vector<mazeSize_t>>getExistsVec();
    void setExistsVec(vector<vector<uint32_t>>);

    std::vector<std::vector<WallItem*>> besideItemVec;     //横壁配列
    std::vector<std::vector<WallItem*>> verticalItemVec;   //縦壁配列
private:
    void wallItemInit(int size);
    int mazeSize;
};

template <class mazeSize_t>
vector<vector<mazeSize_t>> WallItemVec::getExistsVec(){
    /*
    Return formed wall data.

    Return
    ------
    vector<vector<mazeSize_t>> Formed wall data
    */

    vector<vector<mazeSize_t>> data(2, vector<mazeSize_t>(mazeSize-1));

    /*横壁情報の整形*/
    for(int y=1; y<mazeSize; y++){ //　一番下と上の壁は既知であるためデータとしない
        for(int x=0; x<mazeSize; x++){
            data.at(BESIDE).at(y-1) |= (getExists(BESIDE,x,y) << x);
        }
    }

    /*縦壁情報の整形*/
    for(int x=1; x<mazeSize; x++){ //　一番左と右の壁は既知であるためデータとしない
        for(int y=0; y<mazeSize; y++){
            data.at(VERTICAL).at(x-1) |= (getExists(VERTICAL,x,y) << y);
        }
    }
    return data;
}

#endif // WALLITEMVEC_H
