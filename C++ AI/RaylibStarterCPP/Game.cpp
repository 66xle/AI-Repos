#include "Game.h"

// Monster
Agent* monster = new Agent();
FiniteStateMachine monsterBehaviour;
// Player
Player* player = new Player();
// Pathfinding Graph
Graph* graph = new Graph();
// Map Textures, Collision
Map* map = new Map();

Object* object = new Object();


void Game::Init()
{
	SetTargetFPS(60);

	// Load Map textures and Create Wall Boundaries
	map->MapSetup(graph, player);

	// Setup Spotlight
	spotShader.shader = spotShader.Init();

	// Load and Create Key
	object->CreateObject("Key.png", graph);

	// Player
	Image image = LoadImage("Player.png");
	player->texture = LoadTextureFromImage(image);
	player->position = { 50, 50 };
	// Monster
	image = LoadImage("Monster.png");
	monster->texture = LoadTextureFromImage(image);
	monster->position = { 300, 100 };

	// Camera Setup
	camera.offset = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	camera.rotation = 0.0f;
	camera.zoom = 5.0f;

	// Create States
	ChaseState* chaseState = new ChaseState(graph, map);
	PatrolState* patrolState = new PatrolState(graph, map);
	SearchAreaState* searchAreaState = new SearchAreaState(graph, map);
	// Create Conditions
	LOSFoundCondition* losFoundCondition = new LOSFoundCondition(monster, player); // Patrol/SearchArea to Chase
	LOSLostCondition* losLostCondition = new LOSLostCondition(monster, player); // Chase to SearchArea
	PlayerLostCondition* playerLostCondition = new PlayerLostCondition(monster, graph); // SearchArea to Patrol
	// Create Transitions
	Transition* toChaseTransition = new Transition(chaseState, losFoundCondition);
	Transition* toSearchAreaTransition = new Transition(searchAreaState, losLostCondition);
	Transition* toPatrolTransition = new Transition(patrolState, playerLostCondition);
	// Add Transition
	patrolState->AddTransition(toChaseTransition);
	chaseState->AddTransition(toSearchAreaTransition);
	searchAreaState->AddTransition(toChaseTransition);
	searchAreaState->AddTransition(toPatrolTransition);

	// Set Behaviours
	monster->AddBehaviour(&monsterBehaviour);
	monsterBehaviour.AddState(chaseState);
	monsterBehaviour.AddState(patrolState);
	monsterBehaviour.AddState(searchAreaState);
	monsterBehaviour.SetCurrentState(chaseState);
}

void Game::Shutdown()
{
	delete player;
	delete monster;
	delete map;
	delete graph;
	delete object;
}

void Game::Update()
{
	deltaTime = GetFrameTime();
	// Check if player wins
	if (object->keys != 4)
	{
		// Check if player is alive
		if (player->dead == false)
		{
			// When monster position spawns outside of map
			if (monster->position.x < 0 || monster->position.y < 0)
			{
				monster->position = { 300, 100 };
			}

			// Update Here
			player->PlayerMovement(deltaTime, *map);
			camera.target = player->position;
			spotShader.shader = spotShader.Update(player);

			monster->Update(deltaTime);

			player->CheckIfDead(monster);

			object->Update(player, graph);
		}
	}

	//Put game logic and input management here.
}

void Game::Draw()
{
	std::stringstream fpsCounter;

	fpsCounter << "FPS: " << GetFPS() << " Monster Pos: " << monster->position.x << ", " << monster->position.y;

	// Player HUD
	BeginDrawing();	//Rendering code comes after this call...
	ClearBackground(BLACK);
		// Check if player wins
		if (object->keys != 4)
		{	
			// Check if player is alive
			if (player->dead == false)
			{
				// Game World
				BeginMode2D(camera);

					// Draw Map Textures
					map->DrawMap(graph);
					object->Draw();

					// Debug 

					/*graph->Draw();
					for (int i = 0; i < (graph->path.size() - 1) && graph->path.size() > 0; i++)
					{
						DrawLineEx(graph->path[i]->position, graph->path[(size_t)i + 1]->position, 1.5, BLUE);
					}
					graph->ResetNodes();*/

					// Draw Objects
					player->Draw();
					monster->Draw();

				EndMode2D();

				// Draw Spotlight Shader
				spotShader.Draw();

				// Display Fps
				//DrawText(fpsCounter.str().c_str(), 10, 10, 20, RED);
			}
			else
			{
				// Player Lose Message
				std::stringstream message;
				message << "You Died!";
				DrawText(message.str().c_str(), 300, GetScreenHeight() / 2, 100, RED);
			}
		}
		else
		{
			// Player Win Message
			std::stringstream message;
			message << "You Win!";
			DrawText(message.str().c_str(), 300, GetScreenHeight() / 2, 100, RED);
		}
		

	EndDrawing();	//...and before this one.
}
