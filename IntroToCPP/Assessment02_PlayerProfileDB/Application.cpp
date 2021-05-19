#include "Application.h"
#include "PlayerDB.h"
#include "Player.h"
#include <iostream>
#include <cstring>

PlayerDB db;

Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
    while (true)
    {
        std::cout << "Database < ";
        std::cin >> m_command;

        if (m_command == "load")
        {
            db.Load(filename);

            std::cout << "Database < File Loaded\n";
        }
        
        if (m_command == "save")
        {
            db.Save(filename);

            std::cout << "Database < File Saved\n";
        }
        
        if (m_command == "add")
        {
            std::cout << "Database < Add < ";

            std::cin >> m_newPlayer.name >> m_newPlayer.score;

            db.Add(m_newPlayer.name, m_newPlayer.score);

            std::cout << "Database < Player Added";

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
            std::cin >> m_command2;

            if (m_command2 == "player")
            {
                GetPlayer();
            }
            else if (m_command2 == "score")
            {
                GetScore();
            }
        }
        
        if (m_command == "remove")
        {
            std::cout << "Database < Remove < ";
            std::cin >> m_pGet.name >> m_pGet.score;
            std::cout << std::endl;
            
            m_playerRemoved = db.Remove(m_pGet);

            if (m_playerRemoved)
                std::cout << "Database < Remove Success\n";
            else if (!m_playerRemoved)
                std::cout << "Database < Player Not Found\n";
        }

        if (m_command == "sort")
        {
            std::cin >> m_command2;
        
            m_sorted = db.Sort(m_command2.c_str());
        
            if (m_sorted)
                std::cout << "Database < Sort Successful\n";
            else if (!m_sorted)
                std::cout << "Database < " << m_command2 << " Is Not A Sorting Catagory\n";
        }

        if (m_command == "update")
        {
            std::cout << "Database < Update < Player < ";

            std::cin >> m_pGet.name >> m_pGet.score;

            std::cout << "\nDatabase < Update < New Player < ";

            std::cin >> m_newPlayer.name >> m_newPlayer.score;

            m_updated = db.UpdatePlayers(m_pGet,m_newPlayer);

            if (m_updated)
                std::cout << "Database < Update Successful\n";
            else if (!m_updated)
                std::cout << "Database < Player Not Found\n";
        }

        if (m_command == "high")
        {
            for (int i = 0; i < db.m_count; i++)
            {
                m_pGet = db.GetHighScore();
            }

            std::cout << "Database < High Score\n" << m_pGet.name << " " << m_pGet.score; // not done

            std::cout << std::endl << std::endl;
        }
    }
}

void Application::GetPlayer()
{
    std::cout << "Database < Get < Player < ";
    std::cin >> m_getPlayer;
    std::cout << std::endl;

    std::cout << "Database < Player";

    for (int i = 0; i < db.m_count; i++)
    {
        m_pGet = db.GetByName(m_getPlayer, i);

        if (m_pGet.name != "" && m_pGet.score != NULL)
        {
            std::cout << "\n" << m_pGet.name << " " << m_pGet.score;
            m_getCounter += 1;
        }
    }

    if (m_getCounter == 0)
        std::cout << " Not Found";

    m_getCounter = 0;

    std::cout << std::endl << std::endl;
}

void Application::GetScore()
{
    std::cout << "Database < Get < Score < ";
    std::cin >> m_getScore;
    std::cout << std::endl;

    std::cout << "Database < Score";

    for (int i = 0; i < db.m_count; i++)
    {
        m_pGet = db.GetByScore(m_getScore, i);

        if (m_pGet.name != "" && m_pGet.score != NULL)
        {
            std::cout << "\n" << m_pGet.name << " " << m_pGet.score;
            m_getCounter += 1;
        }
    }

    if (m_getCounter == 0)
        std::cout << " Not Found";

    m_getCounter = 0;

    std::cout << std::endl << std::endl;
}