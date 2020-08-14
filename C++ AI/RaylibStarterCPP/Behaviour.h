#pragma once
#include "Agent.h"

enum class eBehaviourResult {
	SUCCESS,
	FAILURE,
	RUNNING
};

class Behaviour
{
public:
	Behaviour() {}
	virtual ~Behaviour() {}

	virtual eBehaviourResult Execute(Agent* agent, float deltaTime) = 0;
};

