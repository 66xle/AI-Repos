#include "Map.h"

void Map::MapSetup()
{
	textures.push_back(LoadTexture(1, 1, true));
	textures.push_back(LoadTexture(136, 34, false));
	textures.push_back(LoadTexture(153, 34, false));
	textures.push_back(LoadTexture(170, 34, false));
	textures.push_back(LoadTexture(187, 34, false));
}

void Map::DrawMap()
{
	Vector2 position = { 0, 0 };
	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x < 17; x++)
		{
			position.x = x * 32;
			position.y = y * 32;

			if (x == 0 || x == 16 || y == 0 || y == 16)
			{
				textures[0].position = position;
				DrawTextureEx(textures[0].texture, position, 0, 2.0f, BLACK);
			}
			else
			{
				DrawTextureEx(textures[2].texture, position, 0, 2.0f, WHITE);
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
