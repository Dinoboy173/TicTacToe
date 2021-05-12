#pragma once

enum class GameStates
{
    MENU,
    PLAY,
    WIN
};

class TicTacToeApp
{
public:
    TicTacToeApp();
    ~TicTacToeApp();

    void Run();
    void RunMenuState();
    void RunPlayState();
    void RunWinState();

    void MenuControl();
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