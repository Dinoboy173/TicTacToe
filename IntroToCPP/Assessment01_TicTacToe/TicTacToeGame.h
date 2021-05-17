#pragma once
#include <string>

class TicTacToe
{

public:
	TicTacToe();
	~TicTacToe();

	void PlaceToken(char token);
	std::string CheckWinner(char token);
	std::string CheckPlayer(char token);
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