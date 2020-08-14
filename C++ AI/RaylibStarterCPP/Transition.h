#pragma once
#include "Condition.h"

class State;
class Agent;

class Transition
{
public:
	Transition(State* target, Condition* condition) : target(target), condition(condition) {}
	~Transition() {}

	State* getTargetState() { return target; }

	bool hasTriggered(Agent* agent) { return condition->test(agent); }

private:
	State* target;
	Condition* condition;
};

