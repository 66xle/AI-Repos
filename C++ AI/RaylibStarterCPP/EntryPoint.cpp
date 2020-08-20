#include "raylib.h"
#include "Game.h"

int main()
{
	Game game;

	InitWindow(1024, 1024, "Escape the Monster - Crappy AI Game");

	game.Init();

	while (!WindowShouldClose())
	{
		game.Update();
		game.Draw();
	}

	game.Shutdown();
	CloseWindow();
} 