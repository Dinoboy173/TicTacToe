#include "TicTacToeApp.h"
#include "TicTacToeGame.h"
#include "TicTacToeBoard.h"
#include <iostream>
#include <conio.h>
#include <string>

TicTacToeApp::TicTacToeApp()
{

}
TicTacToeApp::~TicTacToeApp()
{

}

void TicTacToeApp::Run()
{
	while (!m_shouldQuit)
	{
		system("CLS");

		if (m_gameState == GameStates::MENU)
		{
			RunMenuState();
			MenuControl();
		}
		else if (m_gameState == GameStates::PLAY)
		{
			RunPlayState();
		}
		else if (m_gameState == GameStates::WIN) RunWinState();
	}
}

void TicTacToeApp::RunMenuState()
{
	std::cout << "Tic Tac Toe\n---------------------\n";
	if (m_menuSelection == 1)
		std::cout << ">";
	std::cout << " Play Game\n";
	if (m_menuSelection == 2)
		std::cout << ">";
	std::cout << " Quit Game\n---------------------\n";
}

void TicTacToeApp::RunPlayState()
{
	TicTacToeBoard b;

	b.m_underSelector = b.board[b.m_selectorPosY][b.m_selectorPosX];
	b.board[b.m_selectorPosY][b.m_selectorPosX] = (char)Tokens::SELECTOR;

	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			std::cout << "|" << b.board[i][j];
		}
		std::cout << "|\n";
	}

	GameControl();
}

void TicTacToeApp::RunWinState()
{
	std::cout << "RunState\n";
}

void TicTacToeApp::MenuControl()
{
	int input = _getch();

	switch (input)
	{
	case (int)Controls::UP:
		m_menuSelection = 1;
		break;
	case (int)Controls::DOWN:
		m_menuSelection = 2;
		break;

	default: NULL;
	}

	if (input == (int)Controls::ENTER)
	{
		if (m_menuSelection == 1)
			m_gameState = GameStates::PLAY;
		if (m_menuSelection == 2)
			m_shouldQuit = true;
	}
}

void TicTacToeApp::GameControl()
{
	int input = _getch();
	TicTacToe game;

	switch (input)
	{
	case (int)Controls::UP:
		m_gameSelection = 1;
		break;
	case (int)Controls::LEFT:
		m_gameSelection = 2;
		break;
	case (int)Controls::RIGHT:
		m_gameSelection = 3;
		break;
	case (int)Controls::DOWN:
		m_gameSelection = 4;
		break;

	default: NULL;
	}

	if (input == 13)
	{
		if (m_gameSelection == 1)
			game.MoveToken("up");
		if (m_gameSelection == 2)
			game.MoveToken("left");
		if (m_gameSelection == 2)
			game.MoveToken("right");
		if (m_gameSelection == 2)
			game.MoveToken("down");
	}
}