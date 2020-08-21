#pragma once
#include "raylib.h"
#include "Vector2Math.h"
#include "Player.h"
#include <string>
#include <vector>

class Object
{
public:
	Texture texture;
	Vector2 position;

	int keys = 0;

	void CreateObject(const char* texName, Graph* graph);
	void Update(Player* player, Graph* graph);
	void Draw();
};

