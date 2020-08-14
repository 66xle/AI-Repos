#pragma once
#include "raylib.h"
#include "Node.h"
#include "Vector2Math.h"


class Player
{
public:
	Texture texture;
	Vector2 position;

	void PlayerMovement(float deltaTime);
	void DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rotation);
	void Draw();

	bool IsNear(Node* node);
};

