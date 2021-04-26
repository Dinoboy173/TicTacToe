#include "RaylibTicTacToeApp.h"
#include "raylib.h"

RaylibTicTacToe::RaylibTicTacToe()
{
	
}
RaylibTicTacToe::~RaylibTicTacToe()
{

}

void RaylibTicTacToe::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Hello Raylib C++");
	Load();
	while(!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}
	Unload();
	CloseWindow();
}

void RaylibTicTacToe::Load()
{
	// Load Game assets here

}

void RaylibTicTacToe::Unload()
{
	// Unload Game assets here
}

void RaylibTicTacToe::Update(float dt)
{
	// Game update logic here
}

void RaylibTicTacToe::Draw()
{
	BeginDrawing();
	ClearBackground(WHITE);

	const char* text = "Hello Raylib";
	auto textsize = MeasureText(text, 32);
	DrawText(
		text,
		m_windowWidth * 0.5f - textsize * 0.5f,
		m_windowHeight * 0.5f + 42,
		24,
		GRAY);
	EndDrawing();
}