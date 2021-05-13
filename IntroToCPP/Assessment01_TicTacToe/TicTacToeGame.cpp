#include "TicTacToeGame.h"
#include "TicTacToeBoard.h"
#include <string>

TicTacToe::TicTacToe()
{

}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::MoveToken(int direction)
{
    TicTacToeBoard b;

    if (direction == 1)
    {
        b.m_selectorPosY = 0;
        //if (b.board[b.m_selectorPosY][b.m_selectorPosX] = !b.board[0][b.m_selectorPosX])
        //{
            //b.board[b.m_selectorPosY][b.m_selectorPosX] = b.m_underSelector;
            //b.m_selectorPosY = b.m_selectorPosY - 1;
            //b.m_underSelector = b.board[b.m_selectorPosY][b.m_selectorPosX];
        //}
    }
}

void TicTacToe::PlaceToken()
{

}

std::string TicTacToe::CheckWinner(char board[3][3], char token)
{
    for (int i = 0; i <= 2;)
    {
        if (board[i][0] == token && board[i][1] == token && board[i][2] == token || board[0][i] == token && board[1][i] == token && board[2][i] == token)
        {
            return CheckPlayer(token);
        }

        i++;
    }

    for (int i = 0; i <= 2;)
    {
        if (board[1][1] == token && board[0 + i][0] == token && board[2 - i][2] == token)
        {
            return CheckPlayer(token);
        }

        i = i + 2;
    }

    return "No Winner";
}

std::string TicTacToe::CheckPlayer(char token)
{
    if (token == 'x')
        return "x Wins";
    else
        return "o Wins";
}

void TicTacToe::SwitchPlayer()
{

}
