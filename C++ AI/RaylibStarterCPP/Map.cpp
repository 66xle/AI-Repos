#include "Map.h"

void Map::MapSetup(Graph* graph, Player* player)
{
	// Create and Store Textures
	textures.push_back(LoadTexture(1, 1));
	textures.push_back(LoadTexture(153, 34));

	Vector2 position = { 0, 0 };
	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x < 17; x++)
		{
			position.x = (float)x * 32;
			position.y = (float)y * 32;

			if (mapArray[x][y] == 'W')
			{
				// Delete Nodes
				if (x - 1 >= 0 && y - 1 >= 0 && x - 1 <= 14 && y - 1 <= 14)
				{
					graph->nodes[x - 1][y - 1].BlockNode();
				}

				// Create Player Box Wall Collision
				BoundingBox box;
				Vector3 vec3 = { 0, 0, 0 };
				box.min = vec3 + position;
				box.max = vec3 + (position + 32.0f);
				boxes.push_back(box);

				// Create Raycast Wall Collision
				walls.push_back(CreateWall({ position.x, position.y }, { position.x + 32, position.y }));
				walls.push_back(CreateWall({ position.x, position.y }, { position.x, position.y + 32 }));
				walls.push_back(CreateWall({ position.x + 32, position.y }, { position.x + 32, position.y + 32 }));
				walls.push_back(CreateWall({ position.x, position.y + 32 }, { position.x + 32, position.y + 32 }));

				// Player 
				this->player = player;
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
			position.x = (float)x * 32;
			position.y = (float)y * 32;

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



Tile Map::LoadTexture(int x, int y)
{
	Rectangle rec;
	rec.x = (float)x;
	rec.y = (float)y;
	rec.width = 16;
	rec.height = 16;

	Tile tile;

	Image* cropImage = &LoadImage("Map.png");
	ImageCrop(cropImage, rec);
	tile.texture = LoadTextureFromImage(*cropImage);

	return tile;
}

Boundary Map::CreateWall(Vector2 p1, Vector2 p2)
{
	Boundary wall;
	wall.p1 = p1;
	wall.p2 = p2;
	return wall;
}
