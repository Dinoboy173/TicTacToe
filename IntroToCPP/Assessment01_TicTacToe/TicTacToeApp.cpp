#include "TicTacToeApp.h"
#include "TicTacToeGame.h"
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
	m_game.board[m_selectorPos[0]][m_selectorPos[1]] = (char)Tokens::SELECTOR;

	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			std::cout << "|";

			std::cout << m_game.board[i][j];
		}
		std::cout << "|\n";
	}
	std::cout << "\nCurrent Player: " << m_currentPlayer;
}

void TicTacToeApp::RunWinState()
{
	std::cout << "RunWinState\n";
}

void TicTacToeApp::MenuControl()
{
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
	case (int)Controls::SELECTGAMEPOS:
		m_gameSelection = 5;
		break;

	default: NULL;
	}

	if (input == (int)Controls::QUIT)
		m_shouldQuit = true;

	if (m_gameSelection == 1)
		MoveToken(m_gameSelection);
	else if (m_gameSelection == 2)
		MoveToken(m_gameSelection);
	else if (m_gameSelection == 3)
		MoveToken(m_gameSelection);
	else if (m_gameSelection == 4)
		MoveToken(m_gameSelection);
	else if (m_gameSelection == 5)
	{
		TicTacToe().PlaceToken(m_currentPlayer);
	    //TicTacToe().CheckWinner(m_currentPlayer);
		m_currentPlayer = TicTacToe().SwitchPlayer(m_currentPlayer);
	}
}

void TicTacToeApp::MoveToken(int direction)
{
	if (direction == 1)
	{
		if (m_selectorPos[0] >= 1)
		{
			m_game.board[m_selectorPos[0]][m_selectorPos[1]] = (char)Tokens::BLANK;
			m_selectorPos[0] -= 1;
			m_gameSelection = 0;
		}
	}
	if (direction == 2)
	{
		if (m_selectorPos[1] >= 1)
		{
			m_game.board[m_selectorPos[0]][m_selectorPos[1]] = (char)Tokens::BLANK;
			m_selectorPos[1] -= 1;
			m_gameSelection = 0;
		}
	}
	if (direction == 3)
	{
		if (m_selectorPos[1] <= 1)
		{
			m_game.board[m_selectorPos[0]][m_selectorPos[1]] = (char)Tokens::BLANK;
			m_selectorPos[1] += 1;
			m_gameSelection = 0;
		}
	}
	if (direction == 4)
	{
		if (m_selectorPos[0] <= 1)
		{
			m_game.board[m_selectorPos[0]][m_selectorPos[1]] = (char)Tokens::BLANK;
			m_selectorPos[0] += 1;
			m_gameSelection = 0;
		}
	}
}