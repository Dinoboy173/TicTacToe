#include "Application.h"

#include <iostream>
#include <string>

Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	std::cout << CheckWinner(board0, 'x') << std::endl;
	std::cout << CheckWinner(board0, 'o') << std::endl;
	std::cout << CheckWinner(board1, 'x') << std::endl;
	std::cout << CheckWinner(board1, 'o') << std::endl;
	std::cout << CheckWinner(board2, 'x') << std::endl;
	std::cout << CheckWinner(board2, 'o') << std::endl;
	std::cout << CheckWinner(board3, 'x') << std::endl;
	std::cout << CheckWinner(board3, 'o') << std::endl;
	std::cout << CheckWinner(board4, 'x') << std::endl;
	std::cout << CheckWinner(board4, 'o') << std::endl;
}

std::string Application::CheckWinner(char board[3][3], char token)
{
	bool cell1 = false;
	bool cell2 = false;
	bool cell3 = false;

	for (int i = 0; i < 3; i++)
	{
		// cell1 = false;
		// cell2 = false;
		// cell3 = false;

		if (board[i][0] == token)
			cell1 = true;
		
		if (board[i][1] == token)
			cell2 = true;

		if (board[i][2] == token)
			cell3 = true;
	}

	if (cell1 && cell2 && cell3 && token == 'x')
		return "x Wins";

	if (cell1 && cell2 && cell3 && token == 'o')
		return "o Wins";


	return "No Winner";
}


