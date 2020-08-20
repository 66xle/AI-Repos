#pragma once
#include <sstream>	//String stream, used for the FPS counter
#include "raylib.h"
#include "Graph.h"
#include "Player.h"
#include "Agent.h"
#include "Map.h"
#include "FiniteStateMachine.h"
#include "SpotlightShader.h"

#include "ChaseState.h"
#include "PatrolState.h"
#include "SearchAreaState.h"

#include "LOSLostCondition.h"
#include "LOSFoundCondition.h"
#include "PlayerLostCondition.h"

class Game
{
private:
	Camera2D camera;

	SpotlightShader spotShader;

	float deltaTime;
public:
	Game() {}

	void Init();
	void Shutdown();
	void Update();
	void Draw();

};