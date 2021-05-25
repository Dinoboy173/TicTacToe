#include "App.h"
#include "Dragon.h"
#include <iostream>
#include <string>
#include <stdlib.h>

App::App()
{
}

App::~App()
{
}

void App::Run()
{
	const char* filename = "data.dat";

	srand(time(0)); // fix

	m_dragons[0] = Dragon("fluffy");
	m_dragons[1] = Dragon("bunny");
	m_dragons[2] = Dragon("kittens");
	m_dragons[3] = Dragon("spike");
	m_dragons[4] = Dragon("bob");

	// save the above numbers to file
	SaveToFile(filename);

	m_dragons[0] = Dragon();
	m_dragons[1] = Dragon();
	m_dragons[2] = Dragon();
	m_dragons[3] = Dragon();
	m_dragons[4] = Dragon();

	LoadFromFile(filename);

	for (int i = 0; i < NUM_DRAGONS; i++)
	{
		m_dragons[i].Print();
	}
}

void App::SaveToFile(const char* filename)
{
	std::fstream file;
	file.open(filename, std::ios_base::out);

	for (int i = 0; i < NUM_DRAGONS; i++)
	{
		// save each dragon individually
		SaveDragon(file, &m_dragons[i]);
	}

	file.close();

}

void App::LoadFromFile(const char* filename)
{
	// TODO: write your code here
	// See how we've structured the SaveToFile method
	// this should look simular

	std::fstream file;
	file.open(filename, std::ios_base::in);

	for (int i = 0; i < NUM_DRAGONS; i++)
	{
		LoadDragon(file, &m_dragons[i]);
	}

	file.close();
}

void App::SaveDragon(std::fstream& file, const Dragon* dragon)
{
	// TODO: write code to write the dragons data to file
	// remember, this time the dragons name is an std::string
	// so you'll need to read/write its data seperatelly as the name
	// is a variable length.

	int nameLen = dragon->name.length();

	file.write((char*)&nameLen, sizeof(int));

	for (int i = 0; i < nameLen; i++)
	{
		file.write((char*)&dragon->name[i], sizeof(char));
	}

	file.write((char*)&dragon->foodEatenPerDay[0], sizeof(int) * 7);
}

void App::LoadDragon(std::fstream& file, Dragon* dragon)
{
	// TODO: write code to read the dragons data from file
	// remember, this time the dragons name is an std::string
	// so you'll need to read/write its data seperatelly as the name
	// is a variable length.

	int nameLen = 0;

	file.read((char*)&nameLen, sizeof(int));

	for (int i = 0; i < nameLen; i++)
	{
		char c;

		file.read((char*)&c, sizeof(char));

		dragon->name += c;
	}

	file.read((char*)&dragon->foodEatenPerDay[0], sizeof(int) * 7);
}
