#include "ai.h"

AI ai;

//Calculate the current best move,and store it in exp_x and exp_y, which are the expected x and y coordinates of the next move
void AI::makeMove()
{
    board->platePiece(exp_x,exp_y,2);
}


void AI::minimax()
{

}

void AI::alphaBeta()
{
    
}

void AI::evaluate()
{
    for(int i = 0;i < board->m;++i)//遍历整个棋盘
    {
        for(int j = 0;j < board->n;++j)
        {
            evaluateValue(i,j,1);
            evaluateValue(i,j,2);
        }
    }
}

void AI::evaluateValue(int x,int y,int player)
{
    if(board->board[x][y] != 0)
    {
        pValue[x][y] = -1;
        eValue[x][y] = -1;
        return;
    }
    int shapeType[4]{-1,-1,-1,-1};
    //搜索4个方向
    for(int i = 0;i < 4;i++)
    {
        int type[11];
        for(int j = 0;j < 2;++j)
        {
            int side[5]{-1,-1,-1,-1,-1};
            int state{0};
            for(int k = 1;k < 6;++k)
            {
                int dx = x + direction[i][0] * k * (j == 0 ? 1 : -1);
                int dy = y + direction[i][1] * k * (j == 0 ? 1 : -1);
                if(state)
                {
                    if(k == 5)
                        side[4] = 2;
                    break;
                }
                else if(k == 5)
                {
                    break;
                }
                else if(dx < 0 || dx >= board->m || dy < 0 || dy >= board->n)
                {
                    side[k-1] = 2;
                    break;
                }
                if(board->board[dx][dy] == player)//己方棋子
                    side[k-1] = 1;
                else if(board->board[dx][dy] == 0)//空位
                {
                    side[k-1] = 0;
                    state = 1;
                }
                else//阻挡棋子
                {
                    side[k-1] = 2;
                    state = 1;
                }
            }
            if(j==0)
            {
                for(int k=4;k>=0;--k)
                    type[k] = side[4-k];
            }
            else
            {
                for(int k=6;k<11;++k)
                    type[k] = side[k-6];
            }
            type[5] = 3;//中心
        }
        //计算棋型(匹配type数组)
        //汇总四个方向的棋型，设定权重计算value
        shapeType[i] = shapeMatch(type);
    }
    for(int i = 0;i < 4;++i)
    {
        if(shapeType[i] != -1)
        {
            if(player == 1)
                pValue[x][y] += shapeValue[i];
            else
                eValue[x][y] += shapeValue[i];
        }
        else
        {
            if(player == 1)
                pValue[x][y] += 10;
            else
                eValue[x][y] += 10;
        }
    }
}

int AI::shapeMatch(int* type)
{
    for(int i = 0;i < 12;++i)
    {
        int flagP = 1,flagN = 1;
        int index = 0;
        for(;shape[i][index]!=3;++index);
        for(int j=5-index;j<shape[i].size()+(5-index);++j)
        {
            if(shape[i][j-(5-index)] != type[j])
            {
                flagP = 0;
                break;
            }
        }
        for(int j=5-index;j<shape[i].size()+(5-index);++j)
        {
            if(shape[i][j-(5-index)] != type[10-j])
            {
                flagN = 0;
                break;
            }
        }
        if(flagP||flagN)
            return i;
    }
    return -1;
}

void AI::setInferenceDepth(int depth)
{
    this->depth = depth;
}

void AI::bindBoard(Board* board)
{
    this->board = board;
    pValue.resize(board->m, std::vector<int>(board->n));
    eValue.resize(board->m, std::vector<int>(board->n));
}