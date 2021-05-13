#include "TicTacToeApp.h"
#include "TicTacToeGame.h"
#include "TicTacToeBoard.h"
#include <iostream>
#include <conio.h>
#include <string>

TicTacToeBoard b;

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
			GameControl();
		}
			

		else if (m_gameState == GameStates::CONTROLS)
			RunControlsState();

		else if (m_gameState == GameStates::WIN)
			RunWinState();
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
	std::cout << " Controls\n";
	if (m_menuSelection == 3)
		std::cout << ">";
	std::cout << " Quit Game\n---------------------\n";
}

void TicTacToeApp::RunControlsState()
{
	std::cout << "Up Arrow to move up\n\nDown Arrow to move down\n\nLeft Arrow to move left\n\nRight Arrow to move right\n\nSpace to make selection\n\nEscape to quit\n\n\nPress Backspace to go back the the Menu";

	ControlsControl();
}

void TicTacToeApp::RunPlayState()
{
	//TicTacToeBoard b;

	b.board[b.m_selectorPosY][b.m_selectorPosX] = (char)Tokens::SELECTOR;

	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			std::cout << "|" << b.board[i][j];
		}
		std::cout << "|\n";
	}
}

void TicTacToeApp::RunWinState()
{
	std::cout << "RunWinState\n";
}

void TicTacToeApp::MenuControl()
{
	//TicTacToeBoard b;

	int input = _getch();

	switch (input)
	{
	case (int)Controls::UP:
		if (m_menuSelection > 1)
			m_menuSelection -= 1;
		break;
	case (int)Controls::DOWN:
		if (m_menuSelection < 3)
			m_menuSelection += 1;
		break;

	default: NULL;
	}

	if (input == (int)Controls::ENTER)
	{
		if (m_menuSelection == 1)
		{
			b.m_selectorPosX = 1;
			b.m_selectorPosY = 1;

			m_gameState = GameStates::PLAY;
		}
		else if (m_menuSelection == 2)
			m_gameState = GameStates::CONTROLS;
		else if (m_menuSelection == 3)
			m_shouldQuit = true;
	}
}

void TicTacToeApp::ControlsControl()
{
	int input = _getch();

	if (input == (int)Controls::BACK)
		m_gameState = GameStates::MENU;
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

	if (input == (int)Controls::QUIT)
		m_shouldQuit = true;

	if (m_gameSelection == 1)
		game.MoveToken(m_gameSelection);
	else if (m_gameSelection == 2)
		game.MoveToken(m_gameSelection);
	else if (m_gameSelection == 3)
		game.MoveToken(m_gameSelection);
	else if (m_gameSelection == 4)
			game.MoveToken(m_gameSelection);
}