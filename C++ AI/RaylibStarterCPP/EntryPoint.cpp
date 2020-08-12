#include "raylib.h"
#include "Game.h"

int main()
{
	Game game;

	InitWindow(1024, 1024, "Hello, world!");

	game.Init();

	while (!WindowShouldClose())
	{
		game.Update();
		game.Draw();
	}

	game.Shutdown();
	CloseWindow();
} 