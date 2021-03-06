#include "ConsoleTicTacToeApp.h"
#include "TicTacToeGame.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

ConsoleTicTacToe::ConsoleTicTacToe()
{
	
}
ConsoleTicTacToe::~ConsoleTicTacToe()
{

}

void ConsoleTicTacToe::Run()
{
	while (!m_shouldQuit)
	{
		system("CLS");

		if (m_gameState == GameStates::MENU)
		{
			RunMenuState();
			MenuControl();
		}
		else if (m_gameState == GameStates::PLAY) RunPlayState();
		else if (m_gameState == GameStates::WIN) RunWinState();
	}
}

void ConsoleTicTacToe::RunMenuState()
{
	std::cout << "Tic Tac Toe\n---------------------\n";
	if (m_menuSelection == 1)
		std::cout << ">";
	std::cout << " Play Game\n";
	if (m_menuSelection == 2)
		std::cout << ">";
	std::cout << " Quit Game\n---------------------\n";
}

void ConsoleTicTacToe::RunPlayState()
{
	std::cout << "PlayState\n";
	GameControl();
}

void ConsoleTicTacToe::RunWinState()
{
	std::cout << "RunState\n";
}

void ConsoleTicTacToe::MenuControl()
{
	int input = _getch();

	switch (input)
	{
	case 72:
		m_menuSelection = 1;
		break;
	case 80:
		m_menuSelection = 2;
		break;

	default: NULL;
	}

	if (input == 13)
	{
		if (m_menuSelection == 1) m_gameState = GameStates::PLAY;
		if (m_menuSelection == 2) m_shouldQuit = true;
	}
}

void ConsoleTicTacToe::GameControl()
{
	int input = _getch();

	std::cout << input;

	switch (input)
	{
	case 72:
		m_gameSelection = 1;
		break;
	case 80:
		m_gameSelection = 2;
		break;

	default: NULL;
	}
}