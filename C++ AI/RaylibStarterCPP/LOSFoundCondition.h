#pragma once
#include "Condition.h"

class LOSFoundCondition : public Condition
{
public:
	LOSFoundCondition(Agent* agent, Player* player) : target(agent), player(player) {}
	virtual ~LOSFoundCondition() {}

	virtual bool test(Agent* agent) const;
private:
	Agent* target;
	Player* player;
};

