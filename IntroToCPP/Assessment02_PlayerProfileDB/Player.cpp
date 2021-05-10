#include "Player.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h>

Player::Player()
{
    strcpy(name, "");

    score = 0;
}

Player::Player(const char* name, int& score)
{
    strcpy(this->name, name);

    this->score = score;
}

Player::~Player()
{

}