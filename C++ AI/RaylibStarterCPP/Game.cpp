#include "Game.h"
#include <sstream>	//String stream, used for the FPS counter


void Game::Init()
{
	SetTargetFPS(60);

	testImage = LoadImage("Player.png");

	testTexture = LoadTextureFromImage(testImage);

	camera.target = { 120, 70 };
	camera.offset = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	camera.zoom = 2.0f;
}

void Game::Shutdown()
{
	
}

void Game::Update()
{
	deltaTime = GetFrameTime();


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

			//DrawTexture(testTexture, position, 50, WHITE);
			DrawTextureEx(testTexture, { 100, 50 }, 0, 0.5, WHITE);

		EndMode2D();

	EndDrawing();	//...and before this one.

}
