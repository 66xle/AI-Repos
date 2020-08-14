#pragma once
#include "State.h"
#include "Agent.h"
#include "Player.h"

class ChaseState : public State
{
public:
	ChaseState(Player* target): target(target) {}
	virtual ~ChaseState() {}

	virtual void Update(Agent* agent, float deltaTime);

private:
	Player* target;
	float maxSpeed = 3000;
};

