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
#include "mazescene.h"
#include "walldesign.h"
#include "maze.h"
#include <vector>

class WallItemVec
{
public:
    WallItemVec(int xSize = 32, int ySize = 32);
    enum{BESIDE,VERTICAL,MAX_WALLITE_DIM};

    void setExists(int ax, int x, int y, bool exists);
    bool getExists(int ax, int x, int y);
    bool isInsideOfField(int ax, int x, int y);
    void drawWallItemVec(MazeScene *scene, WallDesign *design);
//    void drawPiller(MazeScene *scene);
//    void drawCoordinate(MazeScene *scene);

private:
    std::vector<std::vector<WallItem*>> besideWallItemVec;     //横壁配列
    std::vector<std::vector<WallItem*>> verticalWallItemVec;   //縦壁配列
};

#endif // WALLITEMVEC_H
