#pragma once

enum class Tokens
{
	X = 120,
	O = 111,
	SELECTOR = 35,
	BLANK = 32
};

class TicTacToeBoard
{
public:
	char board[3][3] =
	{
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	int m_selectorPosX = 0;
	int m_selectorPosY = 0;
	char m_underSelector = ' ';
};