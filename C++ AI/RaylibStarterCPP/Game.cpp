#include "Game.h"

Agent* monster = new Agent();
FiniteStateMachine monsterBehaviour;

Player* player = new Player();

Rectangle rec;
Texture map;

Image* cropImage;
Node* goal;

void Game::Init()
{
	// Set Graph Goal
	goal = &graph.nodes[1][1];

	SetTargetFPS(60);

	// Player
	Image image = LoadImage("Player.png");
	player->texture = LoadTextureFromImage(image);
	player->position = { 100, 50 };
	// Monster
	image = LoadImage("Monster.png");
	monster->texture = LoadTextureFromImage(image);
	monster->position = { 300, 100 };

	// Map Setup
	cropImage = &LoadImage("Map.png");

	rec.x = 153;
	rec.y = 34;
	rec.width = 16;
	rec.height = 16;

	ImageCrop(cropImage, rec);

	map = LoadTextureFromImage(*cropImage);
	
	// Camera Setup
	camera.offset = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	camera.rotation = 0.0f;
	camera.zoom = 3.0f;

	// State Setup
	auto chaseState = new ChaseState(player);

	monster->AddBehaviour(&monsterBehaviour);
	monsterBehaviour.AddState(chaseState);
	monsterBehaviour.SetCurrentState(chaseState);
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

	monster->Update(deltaTime);

	bool stopLoop = false;
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			if (player->IsNear(&graph.nodes[x][y]))
			{
				goal = &graph.nodes[x][y];
				graph.ResetNodes();

				if (IsKeyPressed(KEY_SPACE))
				{
					graph.nodes[x][y] = graph.nodes[x][y].BlockNode();
				}

				stopLoop = true;
				break;
			}
		}
		if (stopLoop)
		{
			break;
		}
	}

	//Put game logic and input management here.
}

void Game::Draw()
{

	std::stringstream fpsCounter;

	fpsCounter << "FPS: " << GetFPS() << ", Position: " << player->position.x << ", " << player->position.y;

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

			graph.ClearPrevious();
			std::vector<Node*> path = graph.AStar(&graph.nodes[0][0], goal);
			graph.Draw();

			for (int i = 0; i < (path.size() - 1) && path.size() > 0; i++)
			{
				DrawLineEx(path[i]->position, path[(size_t)i + 1]->position, 1.5, BLUE);
			}

			player->Draw();
			monster->Draw();

		EndMode2D();

		DrawText(fpsCounter.str().c_str(), 10, 10, 20, RED);

	EndDrawing();	//...and before this one.

}
