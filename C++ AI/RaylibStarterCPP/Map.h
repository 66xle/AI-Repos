#pragma once
#include "Tile.h"

class Map
{
public:
	void MapSetup();

	void DrawMap();
	
private:
	std::vector<Tile> textures;

	Tile LoadTexture(int x, int y, bool collision);
};

