#pragma once
#include "raylib.h"

class Player
{
public:
	Texture texture;
	Vector2 position;

	void PlayerMovement(float deltaTime);
	void Draw();
};

