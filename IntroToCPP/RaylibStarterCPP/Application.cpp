#include "Application.h"
#include "raylib.h"

Application::Application()
{

}
Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_windowHeight, m_windowHeight, "Hello Raylib C++");
	Load();
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}
	Unload();
	CloseWindow();
}

void Application::Load()
{
	// Load Game assets here

}

void Application::Unload()
{
	// Unload Game assets here
}

void Application::Update(float dt)
{
	// Game update logic here
}

void Application::Draw()
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
}