#include "PatrolState.h"
#include <iostream>
#include <time.h>

void PatrolState::Update(Agent* agent, float deltaTime)
{
	Vector2 velocity = targetPath->position - agent->position;

	// Set Rotation facing Target
	agent->rotation = atan2f(targetPath->position.y - agent->position.y, targetPath->position.x - agent->position.x);
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
		// Remove last 2 previous nodes the monster has visited
		std::vector<Node*> randomPath = targetPath->connections;
		for (Node* previous : previousPath)
		{
			for (int i = 0; i < randomPath.size(); i++)
			{
				if (previous == randomPath[i])
				{
					randomPath.erase(randomPath.begin() + i);
					break;
				}
			}
		}
		srand(time(NULL));
		if (previousPath.size() >= 2)
		{
			previousPath.erase(previousPath.begin());
		}
		previousPath.push_back(targetPath);
		if (randomPath.size() == 0)
		{
			//std::cout << "No Path";
			targetPath = targetPath->connections[0];
		}
		else
		{
			targetPath = randomPath[rand() % randomPath.size()];
		}
		
	}
}

void PatrolState::Exit(Agent* agent)
{
	targetPath = nullptr;
	previousPath.clear();
}

void PatrolState::Init(Agent* agent)
{
	bool stopLoop = false;
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			// Find nearest node to the monster
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
