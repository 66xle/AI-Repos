#pragma once
#include "State.h"
#include "Agent.h"
#include "Graph.h"

class PatrolState : public State
{
public:
	PatrolState(Graph* graph): graph(graph) {}
	virtual ~PatrolState() {}

	virtual void Update(Agent* agent, float deltaTime);
	virtual void Exit(Agent* agent);
	virtual void Init(Agent* agent);

private:
	Node* targetPath = nullptr;
	Node* previousPath = nullptr;

	Graph* graph;

	float maxSpeed = 2500;
};

