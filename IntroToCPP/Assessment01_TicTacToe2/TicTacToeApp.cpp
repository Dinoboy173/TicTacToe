#include "TicTacToeApp.h"
#include "TicTacToeGame.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
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
		//system("CLS");

		if (m_gameState == GameStates::MENU)
		{
			RunMenuState();
			MenuControl();
		}
		else if (m_gameState == GameStates::PLAY) RunPlayState();
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
	std::cout << "PlayState\n";
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

void TicTacToeApp::GameControl()
{
	int input = _getch();

	switch (input)
	{
	case 72:
		m_gameSelection = 1;
		break;
	case 75:
		m_gameSelection = 2;
		break;
	case 77:
		m_gameSelection = 3;
		break;
	case 80:
		m_gameSelection = 4;
		break;

	default: NULL;
	}
}