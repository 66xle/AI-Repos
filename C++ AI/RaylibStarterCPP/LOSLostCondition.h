#pragma once
#include "Condition.h"

class LOSLostCondition : public Condition
{
public:
	LOSLostCondition(Agent* agent, Player* player): target(agent), player(player) {}
	virtual ~LOSLostCondition() {}

	virtual bool test(Agent* agent) const;
private:
	Agent* target;
	Player* player;
};

