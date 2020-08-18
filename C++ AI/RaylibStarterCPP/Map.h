#pragma once
#include "Tile.h"
#include "Graph.h"

class Map
{
public:
	void MapSetup();

	void DrawMap(Graph* graph);

	std::vector<Vector2> walls;
	
private:
	Tile LoadTexture(int x, int y, bool collision);

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

