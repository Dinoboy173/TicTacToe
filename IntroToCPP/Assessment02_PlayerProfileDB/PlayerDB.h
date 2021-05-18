#pragma once

#include <fstream>
#include "Player.h"
#include "Application.h"

class PlayerDB
{
public:

    void Add(const char* name, int score);
    void Remove(Player);
    Player GetByName(char player[32]);
    void GetByScore();
    void UpdatePlayers(Player);
    void Sort();
    void Save(const char* filename);
    void Load(const char* filename);
    void Clear(const char* filename);
    void GetHighScore();
    Player ShowAllPlayers(int count);

    int m_count = 0;

protected:

    Player* m_records = nullptr;
    std::fstream file;

private:
};