#pragma once

#include <string>

class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();

	void moveToken();
	void placeToken();
	std::string checkWinner(char board[3][3], char token);
	std::string checkPlayer(char token);
	void switchPlayer();
protected:
private:
};