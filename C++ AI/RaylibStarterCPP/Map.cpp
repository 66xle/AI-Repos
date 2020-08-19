#include "Map.h"

void Map::MapSetup(Graph* graph)
{
	textures.push_back(LoadTexture(1, 1, true));
	textures.push_back(LoadTexture(153, 34, false));

	Vector2 position = { 0, 0 };
	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x < 17; x++)
		{
			position.x = x * 32;
			position.y = y * 32;

			if (mapArray[x][y] == 'W')
			{
				if (x - 1 >= 0 && y - 1 >= 0 && x - 1 <= 14 && y - 1 <= 14)
				{
					graph->nodes[x - 1][y - 1].BlockNode();
				}

				// Create Wall
				BoundingBox box;
				Vector3 vec3 = { 0, 0, 0 };
				box.min = vec3 + position;
				box.max = vec3 + (position + 32.0f);
				walls.push_back(box);
			}
		}
	}
}

void Map::DrawMap(Graph* graph)
{
	Vector2 position = { 0, 0 };
	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x < 17; x++)
		{
			position.x = x * 32;
			position.y = y * 32;

			if (mapArray[x][y] == 'W')
			{
				DrawTextureEx(textures[0].texture, position, 0, 2.0f, BLACK);
			}
			else if (mapArray[x][y] == 'P')
			{
				DrawTextureEx(textures[1].texture, position, 0, 2.0f, WHITE);
			}
		}
	}
}



Tile Map::LoadTexture(int x, int y, bool collision)
{
	Rectangle rec;
	rec.x = x;
	rec.y = y;
	rec.width = 16;
	rec.height = 16;

	Tile tile;
	tile.collision = collision;

	Image* cropImage = &LoadImage("Map.png");
	ImageCrop(cropImage, rec);
	tile.texture = LoadTextureFromImage(*cropImage);

	return tile;
}
