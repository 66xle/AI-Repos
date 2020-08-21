#include "SearchAreaState.h"

void SearchAreaState::Update(Agent* agent, float deltaTime)
{
	Vector2 velocity = targetPath->position - agent->position;

	// Set Rotation facing Target
	agent->rotation = atan2f(targetPath->position.y - agent->position.y, targetPath->position.x - agent->position.x);
	agent->raycast.Cast(map->walls, *agent);

	// Reached Target
	float dx = abs(agent->position.x - targetPath->position.x);
	float dy = abs(agent->position.y - targetPath->position.y);
	float radius = 1;

	if ((dx * dx) + (dy * dy) <= radius * radius)
	{
		// Erase current node the monster is on
		graph->path.erase(graph->path.begin() + graph->path.size() - 1);
		if (graph->path.size() >= 2)
		{
			targetPath = graph->path[graph->path.size() - 2];
		}
		else if (graph->path.size() == 1)
		{
			targetPath = graph->path[0];
			float dx = abs(map->player->position.x - targetPath->position.x);
			float dy = abs(map->player->position.y - targetPath->position.y);
			float radius = 100;

			if ((dx * dx) + (dy * dy) <= radius * radius)
			{
				bool stopLoop = false;
				for (int x = 0; x < GRAPH_SIZE; x++)
				{
					for (int y = 0; y < GRAPH_SIZE; y++)
					{
						if (!graph->nodes[x][y].blocked)
						{
							// Finds nearest node where the player is
							if (map->player->IsNear(&graph->nodes[x][y]))
							{
								searchNode = &graph->nodes[x][y];
								graph->ClearPrevious();
								std::vector<Node*> path = graph->AStar(targetPath, searchNode);

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
		else
		{
			
		}
	}

	Vector2 force = Vector2Normalise(velocity) * maxSpeed;

	agent->velocity = (force * deltaTime);
	agent->position = agent->position + (agent->velocity * deltaTime);

	
}

void SearchAreaState::Exit(Agent* agent)
{
	targetPath = nullptr;
	searchNode = nullptr;
}

void SearchAreaState::Init(Agent* agent)
{
	bool stopLoop = false;
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			if (!graph->nodes[x][y].blocked)
			{
				// Find nearest node the monster is at
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

	stopLoop = false;
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			if (!graph->nodes[x][y].blocked)
			{
				// Find nearest node the player is at
				if (map->player->IsNear(&graph->nodes[x][y]))
				{
					searchNode = &graph->nodes[x][y];
					graph->ClearPrevious();
					std::vector<Node*> path = graph->AStar(targetPath, searchNode);

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
