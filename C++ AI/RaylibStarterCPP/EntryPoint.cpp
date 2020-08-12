#include "raylib.h"
#include "Game.h"

int main()
{
	Game game;

	InitWindow(1080, 1080, "Hello, world!");

	game.Init();

	while (!WindowShouldClose())
	{
		game.Update();
		game.Draw();
	}

	game.Shutdown();
	CloseWindow();
} 