#pragma once
#include "State.h"

class SearchAreaState : public State
{
public:
	SearchAreaState(Graph* graph, Map* map) : graph(graph), map(map) {}
	virtual ~SearchAreaState() {}

	virtual void Update(Agent* agent, float deltaTime);
	virtual void Exit(Agent* agent);
	virtual void Init(Agent* agent);

private:
	Graph* graph;
	Map* map;

	Node* targetPath = nullptr;
	Node* searchNode = nullptr;

	float maxSpeed = 7000;
};

