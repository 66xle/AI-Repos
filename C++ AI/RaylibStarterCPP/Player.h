#pragma once
#include "raylib.h"
#include "Node.h"
#include "Map.h"
#include "Vector2Math.h"

class Node;
class Map;

class Player
{
public:
	Texture texture;
	Vector2 position;

	void PlayerMovement(float deltaTime, Map map);
	void DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rotation);
	void Draw();

	bool IsNear(Node* node);

private:
	bool WallCollision(Vector2 position, Map map);
	
};

