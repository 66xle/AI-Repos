#pragma once
#include <vector>

class Agent;
class Transition;

class State
{
public:
	State();
	virtual ~State();

	virtual void Update(Agent* agent, float deltaTime) = 0;
	virtual void Init(Agent* agent) {};
	virtual void Exit(Agent* agent) {};

	void AddTransition(Transition* transition) { transitionsVec.push_back(transition); }

	Transition* getTriggeredTransition(Agent* agent);

protected:
	std::vector<Transition*> transitionsVec;
};

