#include "ChaseState.h"

void ChaseState::Update(Agent* agent, float deltaTime)
{
	Vector2 velocity = targetPath->position - agent->position;

	// Set Rotation facing Target
	agent->rotation = atan2f(map->player->position.y - agent->position.y, map->player->position.x - agent->position.x);
	agent->raycast.Cast(map->walls, *agent);

	Vector2 force = Vector2Normalise(velocity) * maxSpeed;

	agent->velocity = (force * deltaTime);
	agent->position = agent->position + (agent->velocity * deltaTime);

	// Reached Target
	float dx = abs(agent->position.x - targetPath->position.x);
	float dy = abs(agent->position.y - targetPath->position.y);
	float radius = 1;

	if ((dx * dx) + (dy * dy) <= radius * radius)
	{
		bool stopLoop = false;
		for (int x = 0; x < GRAPH_SIZE; x++)
		{
			for (int y = 0; y < GRAPH_SIZE; y++)
			{
				if (!graph->nodes[x][y].blocked)
				{
					// Gets the nearest node where the player is
					if (map->player->IsNear(&graph->nodes[x][y]))
					{
						playerNode = &graph->nodes[x][y];
						graph->ClearPrevious();
						// Calculate path from monster to player
						std::vector<Node*> path = graph->AStar(targetPath, playerNode); 

						graph->path = path; // Debug

						if (path.size() >= 2)
						{
							targetPath = path[path.size() - 2];
						}
						else
						{
							targetPath = path[0];
						}

						stopLoop = true;
						break;
					}
				}
			}
			if (stopLoop)
			{
				break;
			}
		}
	}
}

void ChaseState::Exit(Agent* agent)
{
	targetPath = nullptr;
	playerNode = nullptr;
}

void ChaseState::Init(Agent* agent)
{
	bool stopLoop = false;
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			// Find the nearest node to the monster
			if (!graph->nodes[x][y].blocked)
			{
				float dx = abs(agent->position.x - graph->nodes[x][y].position.x);
				float dy = abs(agent->position.y - graph->nodes[x][y].position.y);
				float radius = 30;

				if ((dx * dx) + (dy * dy) <= radius * radius)
				{
					targetPath = &graph->nodes[x][y];
					stopLoop = true;
					break;
				}
			}
		}
		if (stopLoop)
		{
			break;
		}
	}
}
