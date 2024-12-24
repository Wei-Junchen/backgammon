#include <iostream>
#include "board.h"
#include "ai.h"

int main()
{
    int gameMode;
    std::cout << "Choose game mode: 0 for pvp, 1 for pve(first hand), 2 for pve(second hand)" << std::endl;
    std::cin >> gameMode;
    Board board;
    board.makeBoard(15,15);
    ai.bindBoard(&board);
    board.printBoard();
    while(!board.isEnd)//game loop
    {
        if(gameMode == 0)//pvp mode
        {
            int x,y,player;
            std::cin >> x >> y >> player;
            board.platePiece(x,y,player);
            board.printBoard();
            continue;
        }
        else if(gameMode == 1)//pve mode (p goes first)
        {
            int x,y;
            std::cin >> x >> y;
            board.platePiece(x,y,1);
            board.printBoard();
            ai.makeMove();
            board.printBoard();
            continue;
        }
        else if(gameMode == 2)//evp mode (e goes first)
        {
            ai.makeMove();
            board.printBoard();
            int x,y;
            std::cin >> x >> y;
            board.platePiece(x,y,1);
            board.printBoard();
            continue;
        }
    }
    return 0;
}