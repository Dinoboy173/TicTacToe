#pragma once

enum class GameStates
{
    MENU,
    PLAY,
    WIN
};

class ConsoleTicTacToe
{
public:
    ConsoleTicTacToe();
    ~ConsoleTicTacToe();

    void Run();
    void RunMenuState();
    void RunPlayState();
    void RunWinState();

    void MenuControl();

protected:
    bool m_shouldQuit = false;
    int m_selection = 1;
    GameStates m_gameState = GameStates::MENU;

private:
    int m_windowWidth = 800;
    int m_windowHeight = 450;
};