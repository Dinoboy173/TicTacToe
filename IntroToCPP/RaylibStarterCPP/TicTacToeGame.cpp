#include "TicTacToeGame.h"
#include <string>

TicTacToe::TicTacToe()
{

}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::moveToken()
{

}

void TicTacToe::placeToken()
{

}

std::string TicTacToe::checkWinner(char board[3][3], char token)
{
    for (int i = 0; i <= 2;)
    {
        if (board[i][0] == token && board[i][1] == token && board[i][2] == token || board[0][i] == token && board[1][i] == token && board[2][i] == token)
        {
            return checkPlayer(token);
        }

        i++;
    }

    for (int i = 0; i <= 2;)
    {
        if (board[1][1] == token && board[0 + i][0] == token && board[2 - i][2] == token)
        {
            return checkPlayer(token);
        }

        i = i + 2;
    }

    return "No Winner";
}

std::string TicTacToe::checkPlayer(char token)
{
    if (token == 'x')
        return "x Wins";
    else
        return "o Wins";
}

void TicTacToe::switchPlayer()
{

}
