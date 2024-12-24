#include "board.h"

void Board::makeBoard(int m, int n)
{
    step = 0;
    this->m = m;
    this->n = n;
    board.resize(m);
    for(auto &line : board)
    {
        line.resize(n);
    }
    for(auto &line : board)
    {
        for(auto &cell : line)
        {
            cell = 0;
        }
    }
}

void Board::printBoard()
{
    for(auto line : board)
    {
        for(auto cell : line)
        {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

void Board::platePiece(int x, int y, int player)
{
    ++step;
    board[x][y] = player;
    if(checkWin(x,y))
    {
        std::cout << "Player " << player << " wins!" << std::endl;
        isEnd = true;
    }
    else if(step == m * n)
    {
        std::cout << "Draw!" << std::endl;
        isEnd = true;
    }
}

//return 0 if no win, 1 if player 1 wins, 2 if player 2 wins
int Board::checkWin(int x,int y)
{
    int player = board[x][y];
    int count = 0;
    //search for horizontal win
    for(int i = x; i < m; i++)
    {
        if(board[i][y] == player)
            count++;
        else
            break;
    }
    for(int i = x; i >= 0; i--)
    {
        if(board[i][y] == player)
            count++;
        else
            break;
    }
    if(count >= 5)
        return player;
    else 
        count = 0;
    //search for vertical win
    for(int i = x; i < n; i++)
    {
        if(board[x][i] == player)
            count++;
        else
            break;
    }
    for(int i = x; i >= 0; i--)
    {
        if(board[x][i] == player)
            count++;
        else
            break;
    }
    if(count >= 5)
        return player;
    else 
        count = 0;
    //search for diagonal win
    for(int i = x, j = y; i < m && j < n; i++, j++)
    {
        if(board[i][j] == player)
            count++;
        else
            break;
    }
    for(int i = x, j = y; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == player)
            count++;
        else
            break;
    }
    if(count >= 5)
        return player;
    else 
        count = 0;
    for(int i = x, j = y; i < m && j >= 0; i++, j--)
    {
        if(board[i][j] == player)
            count++;
        else
            break;
    }
    for(int i = x, j = y; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == player)
            count++;
        else
            break;
    }
    if(count >= 5)
        return player;
    else 
        count = 0;
    return 0;
}