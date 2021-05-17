#pragma once
#include "TicTacToeApp.h"
#include <string>

class TicTacToe
{

public:
	TicTacToe();
	~TicTacToe();

	void PlaceToken(char token, int pos[2]);
	bool CheckWinner(char token);
	bool CheckPlayer(char token);
	char SwitchPlayer(char token);

public:
	char board[3][3] =
	{
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' }
	};

protected:

private:
};