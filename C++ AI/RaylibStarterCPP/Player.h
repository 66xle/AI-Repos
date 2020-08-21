#pragma once
#include "raylib.h"
#include "Node.h"
#include "Map.h"

class Node;
class Map;
class Agent;

class Player
{
public:
	Texture texture;
	Vector2 position;

	bool dead = false;


	void PlayerMovement(float deltaTime, Map map);
	void DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rotation);
	void Draw();

	void CheckIfDead(Agent* agent);
	bool IsNear(Node* node);

private:
	bool WallCollision(Vector2 position, Map map);
	
};

