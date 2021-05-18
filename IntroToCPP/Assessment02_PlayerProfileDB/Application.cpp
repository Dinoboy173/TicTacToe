#include "Application.h"
#include "PlayerDB.h"
#include "Player.h"
#include <iostream>
#include <cstring>

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
        std::cout << "Database < ";
        std::cin >> m_command;

        if (m_command == "load")
        {
            db.Load(filename); // step2

            std::cout << "Database < File Loaded\n";
        }

        if (m_command == "save")
        {
            db.Save(filename); // Step 1

            std::cout << "Database < File Saved\n";
        }
        
        if (m_command == "add")
        {
            std::cout << "Database < Add < ";

            std::cin >> m_newPlayer.name >> m_newPlayer.score;

            db.Add(m_newPlayer.name, m_newPlayer.score);

            std::cout << std::endl;
        }

        if (m_command == "list")
        {
            std::cout << "Database < List\n";

            for (int i = 0; i < db.m_count; i++)
            {
                std::cout << db.ShowAllPlayers(i).name << " " << db.ShowAllPlayers(i).score << std::endl;
            }

            std::cout << std::endl;
        }

        if (m_command == "clear")
        {
            db.Clear(filename);

            std::cout << "Database < File Cleared\n";
        }

        if (m_command == "get")
        {
            std::cout << "Database < Get < ";
            std::cin >> m_get;
            std::cout << std::endl;

            if (m_get == "player")
            {
                std::cout << "Database < Get < Player < ";
                std::cin >> m_getPlayer;
                std::cout << std::endl;


                m_pGet = db.GetByName(m_getPlayer);

                std::cout << "Database < Player\n" << m_pGet.name << " " << m_pGet.score << std::endl;
            }
            else if (m_get == "score")
            {
                std::cout << "Database < Get < Score < ";
                std::cin >> m_getScore;
                std::cout << std::endl;

                
            }
        }
    }
}