#include "Game.h"
#include <sstream>	//String stream, used for the FPS counter

Agent* monster = new Agent();
Player* player = new Player();

Rectangle rec;
Texture map;

Image* cropImage;
Node* goal;

void Game::Init()
{
	goal = &graph.nodes[1][1];

	SetTargetFPS(60);

	// Player
	Image image = LoadImage("Player.png");
	player->texture = LoadTextureFromImage(image);
	player->position = { 100, 50 };
	// Monster
	image = LoadImage("Monster.png");
	monster->texture = LoadTextureFromImage(image);
	monster->position = { 130, 80 };

	cropImage = &LoadImage("Map.png");

	rec.x = 153;
	rec.y = 34;
	rec.width = 16;
	rec.height = 16;

	ImageCrop(cropImage, rec);

	map = LoadTextureFromImage(*cropImage);
	

	camera.offset = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	camera.rotation = 0.0f;
	camera.zoom = 3.0f;

	camera.target = player->position;
}

void Game::Shutdown()
{
	delete player;
}

void Game::Update()
{
	deltaTime = GetFrameTime();

	player->PlayerMovement(deltaTime);
	camera.target = player->position;

	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			if (player->position.x == graph.nodes[x][y].position.x && player->position.y == graph.nodes[x][y].position.y)
			{
				goal = &graph.nodes[x][y];
			}
		}
	}

	//Put game logic and input management here.
}

void Game::Draw()
{

	std::stringstream fpsCounter;

	fpsCounter << "FPS: " << GetFPS() << ", " << player->position.x << ", " << player->position.y;

	// Player HUD
	BeginDrawing();	//Rendering code comes after this call...

		ClearBackground(WHITE);

		// Game World
		BeginMode2D(camera);
			
			Vector2 position = { -32, -32 };


			for (int x = 0; x < 33; x++)
			{
				for (int y = 0; y < 33; y++)
				{
					position.x += 16;
					DrawTextureEx(map, position, 0.0f, 1.0f, WHITE);
				}
				position.x = -32;
				position.y += 16;
			}

			graph.Draw();
			std::vector<Node*> path = graph.AStar(&graph.nodes[0][0], goal);

			for (int i = 0; i < path.size() - 1; i++)
			{
				DrawLineEx(path[i]->position, path[(int)i + 1]->position, 1.5, BLUE);
			}

			player->Draw();
			monster->Draw();
			DrawCircle(player->position.x, player->position.y, 1, BLACK);

		EndMode2D();

		DrawText(fpsCounter.str().c_str(), 10, 10, 20, RED);

	EndDrawing();	//...and before this one.

}
