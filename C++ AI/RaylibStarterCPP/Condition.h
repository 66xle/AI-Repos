#pragma once
#include "Behaviour.h"

class Condition : public Behaviour
{
public:
	Condition() {}
	virtual ~Condition() {}

	virtual bool test(Agent* agent) const = 0;

	virtual eBehaviourResult Execute(Agent* agent, float deltaTime);
};

