#pragma once
#include "raylib.h"
#include "Graph.h"
#include "Player.h"
#include "Agent.h"

class Game
{
private:
	Camera2D camera;

	Graph graph;

	float deltaTime;
public:
	Game() {}

	void Init();
	void Shutdown();
	void Update();
	void Draw();

};