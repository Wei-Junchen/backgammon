#ifndef __BOARD_H
#define __BOARD_H

#include <iostream>
#include <vector>

class Board
{
public:
    Board() = default;
    void makeBoard(int m,int n);
    void platePiece(int x, int y, int player);
    void printBoard();
    int checkWin(int x,int y);
    
    bool isEnd = false;
    std::vector<std::vector<int>> board;
    int m,n,step;
};

#endif