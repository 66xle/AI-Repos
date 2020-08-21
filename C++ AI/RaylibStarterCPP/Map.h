#pragma once
#include "Tile.h"
#include "Graph.h"
#include "Vector2Math.h"
#include "Boundary.h"
#include "Player.h"

class Player;

class Map
{
public:
	void MapSetup(Graph* graph, Player* player);

	void DrawMap(Graph* graph);

	std::vector<Boundary> walls;
	std::vector<BoundingBox> boxes;
	Player* player;

	
private:
	Tile LoadTexture(int x, int y);

	Boundary CreateWall(Vector2 p1, Vector2 p2);

	std::vector<Tile> textures;

	char mapArray[17][17] =
	{
		{'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
		{'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'W', 'P', 'P', 'P', 'P', 'P', 'P', 'W' },
		{'W', 'P', 'P', 'W', 'P', 'W', 'W', 'P', 'P', 'P', 'P', 'W', 'W', 'W', 'P', 'P', 'W' },
		{'W', 'W', 'P', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W' },
		{'W', 'P', 'P', 'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'W' },
		{'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W' },
		{'W', 'P', 'P', 'P', 'P', 'P', 'P', 'W', 'P', 'P', 'P', 'W', 'P', 'W', 'P', 'P', 'W' },
		{'W', 'P', 'W', 'W', 'P', 'P', 'P', 'W', 'P', 'W', 'P', 'P', 'P', 'W', 'P', 'W', 'W' },
		{'W', 'P', 'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'W', 'P', 'P', 'W' },
		{'W', 'P', 'P', 'P', 'W', 'P', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'P', 'W' },
		{'W', 'W', 'P', 'P', 'W', 'P', 'P', 'P', 'P', 'P', 'P', 'W', 'P', 'P', 'P', 'P', 'W' },
		{'W', 'P', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'P', 'P', 'P', 'P', 'P', 'W', 'W' },
		{'W', 'P', 'P', 'W', 'P', 'P', 'P', 'P', 'W', 'P', 'W', 'P', 'W', 'P', 'P', 'W', 'W' },
		{'W', 'W', 'P', 'W', 'P', 'W', 'W', 'P', 'W', 'P', 'W', 'P', 'W', 'P', 'W', 'W', 'W' },
		{'W', 'W', 'P', 'P', 'P', 'W', 'P', 'P', 'P', 'P', 'W', 'P', 'P', 'P', 'W', 'W', 'W' },
		{'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
	};
};

