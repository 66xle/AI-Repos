#include "Game.h"
#include <sstream>	//String stream, used for the FPS counter
#include "Player.h"
#include "Agent.h"

Agent* monster = new Agent();
Player* player = new Player();

void Game::Init()
{
	SetTargetFPS(60);

	Image image = LoadImage("Player.png");
	player->texture = LoadTextureFromImage(image);
	player->position = { 100, 50 };

	image = LoadImage("Monster.png");
	monster->texture = LoadTextureFromImage(image);
	monster->position = { 130, 80 };


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
	//camera.target = player->position;

	//Put game logic and input management here.
}

void Game::Draw()
{

	std::stringstream fpsCounter;

	fpsCounter << "FPS: " << GetFPS();

	BeginDrawing();	//Rendering code comes after this call...

		ClearBackground(BLUE);

		DrawText(fpsCounter.str().c_str(), 10, 10, 20, RED);

		BeginMode2D(camera);

			player->Draw();
			monster->Draw();

		EndMode2D();

	EndDrawing();	//...and before this one.

}
