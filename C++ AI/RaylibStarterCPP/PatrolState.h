#pragma once
#include "State.h"
#include "Agent.h"
#include "Graph.h"
#include "Map.h"

class PatrolState : public State
{
public:
	PatrolState(Graph* graph, Map* map): graph(graph), map(map) {}
	virtual ~PatrolState() {}

	virtual void Update(Agent* agent, float deltaTime);
	virtual void Exit(Agent* agent);
	virtual void Init(Agent* agent);

private:
	Node* targetPath = nullptr;
	std::vector<Node*> previousPath;

	Graph* graph;
	Map* map;

	float maxSpeed = 3000;
};

