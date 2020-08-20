#pragma once
#include "Condition.h"

class PlayerLostCondition : public Condition
{
public:
	PlayerLostCondition(Agent* agent, Graph* graph) : target(agent), graph(graph) {}
	virtual ~PlayerLostCondition() {}

	virtual bool test(Agent* agent) const;

private:
	Agent* target;
	Graph* graph;
};

