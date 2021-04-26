#include "ConsoleTicTacToeApp.h"
#include "raylib.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>

ConsoleTicTacToe::ConsoleTicTacToe()
{
	
}
ConsoleTicTacToe::~ConsoleTicTacToe()
{

}

void ConsoleTicTacToe::Run()
{
	Load();
	Unload();
}

void ConsoleTicTacToe::Load()
{
	// Load Game assets here
	Draw();

	ConsoleMenu();
}

void ConsoleTicTacToe::Unload()
{
	// Unload Game assets here
}

void ConsoleTicTacToe::Update(float dt)
{
	// Game update logic here
	
}

void ConsoleTicTacToe::Game()
{
	DrawGame();
}

void ConsoleTicTacToe::ConsoleMenu()
{
	while (true)
	{
		int input = _getch();
		switch (input)
		{
		case 72:
			m_selection = 1;
			DrawMenu();
			break;
		case 80:
			m_selection = 2;
			DrawMenu();
			break;

		default: NULL;
		}

		if (input == 13)
		{
			if (m_selection == 1) Game();
			if (m_selection == 2) Quit();
		}
	}
}

void ConsoleTicTacToe::Draw()
{
	DrawMenu();
}

void ConsoleTicTacToe::DrawGame()
{
	system("CLS");
	std::cout << "Game";
}

void ConsoleTicTacToe::DrawMenu()
{
	system("CLS");

	std::cout << "Tic Tac Toe\n---------------------\n";
	if (m_selection == 1) std::cout << ">";
	std::cout << " 1. Play Game\n";
	if (m_selection == 2) std::cout << ">";
	std::cout << " 2. Quit Game\n---------------------\n";
}

void ConsoleTicTacToe::Quit()
{
	system("CLS");
	exit(0);
}