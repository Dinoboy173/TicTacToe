#include "RaylibTicTacToeApp.h"
#include "ConsoleTicTacToeApp.h"

int main(int argc, char** argv)
{
    bool createConsoleApp = true;

    if (createConsoleApp)
    {
        ConsoleTicTacToe app;
        app.Run();
    }
    else
    {
        RaylibTicTacToe app;
        app.Run();
    }

    return 0;
}