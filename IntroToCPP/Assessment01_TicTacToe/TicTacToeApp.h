#pragma once
#include <vector>

enum class GameStates
{
    MENU,
    CONTROLS,
    PLAY,
    WIN
};

enum class Controls
{
    BACK = 8,
    ENTER = 13,
    QUIT = 27,
    SELECTGAMEPOS = 32,
    UP = 72,
    LEFT = 75,
    RIGHT = 77,
    DOWN = 80
};

class TicTacToeApp
{
public:
    TicTacToeApp();
    ~TicTacToeApp();

    void Run();
    void RunMenuState();
    void RunControlsState();
    void RunPlayState();
    void RunWinState();

    void MenuControl();
    void ControlsControl();
    void GameControl();

protected:
    bool m_shouldQuit = false;
    int m_menuSelection = 1;
    int m_gameSelection = 1;
    GameStates m_gameState = GameStates::MENU;

private:
    int m_windowWidth = 800;
    int m_windowHeight = 450;
};