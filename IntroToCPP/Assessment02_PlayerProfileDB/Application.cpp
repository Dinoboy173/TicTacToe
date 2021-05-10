#include "Application.h"
#include "PlayerDB.h"
#include "Player.h"
#include <iostream>

Application::Application()
{

}
Application::~Application()
{

}

void Application::Run()
{
    PlayerDB db;

    while (true)
    {
        db.Load(filename); // step2

        std::cout << db.ShowAllPlayers().name << " " << db.ShowAllPlayers().score << std::endl;

        db.Add("hello", 12);
        db.Add("world", 13);
        db.Add("jordan", 14);
        db.Add("craig", 15);

        db.Save(filename); // Step 1
    }
}