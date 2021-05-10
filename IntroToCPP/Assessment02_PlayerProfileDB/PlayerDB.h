#pragma once

#include <fstream>
#include "Player.h"
#include "Application.h"

class PlayerDB
{
public:

    void Add(const char* name, int score);
    void Remove(Player);
    void GetByName(Player);
    void GetByScore();
    void UpdatePlayers(Player);
    void Sort();
    void Save(const char* filename);
    void Load(const char* filename);
    void Clear(const char* filename);
    void GetHighScore();
    Player ShowAllPlayers();

protected:

    Player* m_records = nullptr;
    int m_count = 0;
    std::fstream file;

private:
};