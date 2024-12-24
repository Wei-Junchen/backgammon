#ifndef __AI_H
#define __AI_H

#include "board.h"
#include <vector>

class AI
{
public:
    void makeMove();
    void minimax();
    void alphaBeta();
    void evaluate();
    void evaluateValue(int x,int y,int player);
    void setInferenceDepth(int depth);
    void bindBoard(Board* board);
    int shapeMatch(int* type);
private:
    int depth;
    Board* board;
    std::vector<std::vector<int>> pValue;
    std::vector<std::vector<int>> eValue;
    int exp_x,exp_y;
    int direction[4][2] = {{1,0},{0,1},{1,1},{1,-1}};
    std::vector<std::vector<int>> shape ={  {3,1,1,1,1,0},
                                                {3,1,1,1,1,2},
                                                {1,3,1,1,1},
                                                {1,1,3,1,1},
                                                {3,1,1,1,0},
                                                {0,1,3,1,1,0},
                                                {0,3,1,1,1,2},
                                                {3,0,1,1,1,2},
                                                {0,1,3,1,1,2},
                                                {3,1,0,1,1,2},
                                                {2,1,3,1,1,0},
                                                {3,1,1,0,1,2}};//形状评估表 0:空 1:棋子 2:界 3:匹配中心

    std::vector<int> shapeValue = {100000,10000,10000,10000,1000,1000,100,120,100,100,100,100};//形状评估值
};

extern AI ai;

#endif