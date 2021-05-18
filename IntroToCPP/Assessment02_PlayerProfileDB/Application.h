#pragma once

#include <string>

#include "Player.h"
#include "PlayerDB.h"

class Application
{
public:

	Application();
	~Application();

	void Run();

protected:

	std::string m_command;
	std::string m_get;
	Player m_newPlayer;
	Player m_pGet;
	char m_getPlayer[32];
	int m_getScore;

	const char* filename = "dateBase.dat";

private:
};