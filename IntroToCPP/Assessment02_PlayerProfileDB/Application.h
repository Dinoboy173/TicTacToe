#pragma once

#include "Player.h"
#include "PlayerDB.h"

class Application
{
public:

	Application();
	~Application();

	void Run();

protected:

	const char* filename = "dateBase.dat";

private:
};