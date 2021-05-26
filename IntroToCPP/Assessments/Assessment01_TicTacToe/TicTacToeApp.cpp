#include "TicTacToeApp.h"
#include "TicTacToeGame.h"
#include <iostream>
#include <conio.h>
#include <string>

TicTacToe m_game;

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

	MultiMenuControl();
}

void TicTacToeApp::RunPlayState()
{
	int selectedRow = m_selectorPos[0];
	int selectedCol = m_selectorPos[1];
	char selectedToken = m_game.GetToken(selectedRow, selectedCol);

	if (selectedToken == (char)Tokens::BLANK)
		m_game.SetToken(selectedRow, selectedCol, (char)Tokens::SELECTOR);

	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			std::cout << "|";

			std::cout << m_game.board[i][j];
		}
		std::cout << "|\n";
	}
	std::cout << "\nCurrent Player: " << m_currentPlayer << std::endl;

	if (invalidPlacement)
		std::cout << "\nInvalid Placement";
}

void TicTacToeApp::RunWinState()
{
	if (m_currentPlayer == (char)Tokens::O)
		std::cout << "X WINS\n";
	else
		std::cout << "O WINS\n";

	MultiMenuControl();
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
		switch (m_menuSelection)
		{
		case (int)GameStates::PLAY:
			m_gameState = GameStates::PLAY;
			break;
		case (int)GameStates::CONTROLS:
			m_gameState = GameStates::CONTROLS;
			break;
		case (int)GameStates::QUIT:
			m_shouldQuit = true;
			break;
		default: NULL;
		}
	}
}

void TicTacToeApp::MultiMenuControl()
{
	int input = _getch();

	if (input == (int)Controls::BACK)
		m_gameState = GameStates::MENU;
	else if (input)
		m_shouldQuit = true;
}

void TicTacToeApp::GameControl()
{
	int input = _getch();

	switch (input)
	{
	case (int)Controls::UP:
		MoveToken((int)Direction::NORTH);
		break;
	case (int)Controls::LEFT:
		MoveToken((int)Direction::WEST);
		break;
	case (int)Controls::RIGHT:
		MoveToken((int)Direction::EAST);
		break;
	case (int)Controls::DOWN:
		MoveToken((int)Direction::SOUTH);
		break;
	case (int)Controls::SELECTGAMEPOS:
		if (m_game.board[m_selectorPos[0]][m_selectorPos[1]] == (char)Tokens::X || m_game.board[m_selectorPos[0]][m_selectorPos[1]] == (char)Tokens::O)
		{
			invalidPlacement = true;
		}
		else
		{
			invalidPlacement = false;
			m_game.PlaceToken(m_currentPlayer, m_selectorPos);
			winner = m_game.CheckWinner(m_currentPlayer);
			m_currentPlayer = m_game.SwitchPlayer(m_currentPlayer);
		}
		break;

	default: NULL;
	}

	if (input == (int)Controls::QUIT)
		m_shouldQuit = true;

	if (winner)
		m_gameState = GameStates::WIN;
}

void TicTacToeApp::MoveToken(int direction)
{
	switch (direction)
	{
	case (int)Direction::NORTH:
		if (m_selectorPos[0] >= 1)
		{
			PlaceBlank();
			m_selectorPos[0] -= 1;
		}
		break;
	case (int)Direction::WEST:
		if (m_selectorPos[1] >= 1)
		{
			PlaceBlank();
			m_selectorPos[1] -= 1;
		}
		break;
	case (int)Direction::EAST:
		if (m_selectorPos[1] <= 1)
		{
			PlaceBlank();
			m_selectorPos[1] += 1;
		}
		break;
	case (int)Direction::SOUTH:
		if (m_selectorPos[0] <= 1)
		{
			PlaceBlank();
			m_selectorPos[0] += 1;
		}
		break;
	default: NULL;
	}
}

void TicTacToeApp::PlaceBlank()
{
	if (m_game.board[m_selectorPos[0]][m_selectorPos[1]] == (char)Tokens::SELECTOR)
		m_game.board[m_selectorPos[0]][m_selectorPos[1]] = (char)Tokens::BLANK;
}