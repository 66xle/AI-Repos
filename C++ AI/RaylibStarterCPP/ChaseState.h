#pragma once
#include "State.h"
#include "Agent.h"
#include "Map.h"

class ChaseState : public State
{
public:
	ChaseState(Graph* graph, Map* map) : graph(graph), map(map) {}
	virtual ~ChaseState() {}

	virtual void Update(Agent* agent, float deltaTime);
	virtual void Exit(Agent* agent);
	virtual void Init(Agent* agent);

private:
	Graph* graph;
	Map* map;

	Node* targetPath = nullptr;
	Node* playerNode = nullptr;

	float maxSpeed = 5000;
};

