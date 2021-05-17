#include "TicTacToeGame.h"
#include "TicTacToeApp.h"
#include <string>

TicTacToe::TicTacToe()
{

}

TicTacToe::~TicTacToe()
{

}


void TicTacToe::PlaceToken(char token)
{

}

std::string TicTacToe::CheckWinner(char token)
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

char TicTacToe::SwitchPlayer(char token)
{
    if (token == 'x')
        return 'o';
    else if (token == 'o')
        return 'x';
}
