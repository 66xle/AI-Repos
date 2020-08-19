#pragma once
#include "Condition.h"

class LOSLostCondition : public Condition
{
public:
	LOSLostCondition(Agent* agent): target(agent) {}
	virtual ~LOSLostCondition() {}

	virtual bool test(Agent* agent) const;
private:
	Agent* target;
};

