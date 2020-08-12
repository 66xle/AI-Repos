#pragma once

#include "raylib.h"

class Game
{
private:
	Camera2D camera;

	float deltaTime;

	float position = 50.0f;
public:
	Game() {}

	void Init();

	void Shutdown();

	void Update();

	void Draw();

};