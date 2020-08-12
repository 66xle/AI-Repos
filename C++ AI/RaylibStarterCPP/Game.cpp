#include "Game.h"
#include <sstream>	//String stream, used for the FPS counter


void Game::Init()
{
	SetTargetFPS(60);

	testImage = LoadImage("TestImage.png");

	testTexture = LoadTextureFromImage(testImage);
}

void Game::Shutdown()
{
	
}

void Game::Update()
{
	deltaTime = GetFrameTime();


	position += 10 * deltaTime;

	//Put game logic and input management here.
}

void Game::Draw()
{

	std::stringstream fpsCounter;

	fpsCounter << "FPS: " << GetFPS();


	BeginDrawing();	//Rendering code comes after this call...
	ClearBackground(BLUE);

	DrawText(fpsCounter.str().c_str(), 10, 10, 20, RED);

	DrawTexture(testTexture, position, 50, WHITE);

	EndDrawing();	//...and before this one.

}
