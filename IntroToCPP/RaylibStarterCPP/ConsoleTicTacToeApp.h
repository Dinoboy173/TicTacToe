#pragma once

class ConsoleTicTacToe
{
public:
    ConsoleTicTacToe();
    ~ConsoleTicTacToe();

    void Run();
    void Load();

    void Unload();
    void Update(float dt);

    void Game();
    void ConsoleMenu();

    void Draw();
    void DrawGame();
    void DrawMenu();

    void Quit();
protected:
private:
    int m_windowWidth = 800;
    int m_windowHeight = 450;
    int m_selection = 1;
};