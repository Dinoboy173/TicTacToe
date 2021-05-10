#pragma once
#pragma once

class Application
{
public:

    static const int numOfDragons = 3;
    static const int numOfDays = 7;

    char dragons[numOfDragons];

    int foodEatenInADay[numOfDragons] [numOfDays]; // probs wrong

public:

    Application();
    ~Application();

    void Run();

protected:
private:
};

