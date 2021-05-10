#include <iostream>
#include <fstream>
#include "PlayerDB.h"
#include "Player.h"

void PlayerDB::Add(const char* name, int score)
{
    Player newPlayer(name, score);

    Player* temp = new Player[m_count + 1];

    for (int i = 0; i < m_count; i++)
    {
        temp[i] = m_records[i];
    }

    temp[m_count] = newPlayer;

    delete[] m_records;
    m_records = temp;
    m_count += 1;
}

void PlayerDB::Remove(Player)
{

}

void PlayerDB::GetByName(Player)
{

}

void PlayerDB::GetByScore()
{

}

void PlayerDB::UpdatePlayers(Player)
{

}

void PlayerDB::Sort()
{

}

void PlayerDB::Save(const char* filename)
{
    file.open(filename, std::ios_base::out | std::ios_base::binary);

    if (file.is_open())
    {
        file.write((char*)&m_count, sizeof(int));

        file.write((char*)m_records, sizeof(Player) * m_count);

        file.close();
    }
}

void PlayerDB::Load(const char* filename)
{
    file.open(filename, std::ios_base::in | std::ios_base::binary);

    if (file.is_open())
    {
        file.read((char*)&m_count, sizeof(int));

        m_records = new Player[m_count];

        file.read((char*)m_records, sizeof(Player) * m_count);

        file.close();
    }
}

void PlayerDB::Clear(const char* filename)
{

}

void PlayerDB::GetHighScore()
{

}

Player PlayerDB::ShowAllPlayers()
{
    for (int i = 0; i < m_count; i++)
    {
        return m_records[i * 32];
    }

    return m_records[0];
}