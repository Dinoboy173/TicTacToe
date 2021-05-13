#pragma once
#include <string>

class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();

	void MoveToken(int direction);
	void PlaceToken();
	std::string CheckWinner(char board[3][3], char token);
	std::string CheckPlayer(char token);
	void SwitchPlayer();
protected:
private:
};