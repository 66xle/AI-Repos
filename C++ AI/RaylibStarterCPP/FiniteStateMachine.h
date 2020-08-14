#pragma once
#include <vector>
#include "Behaviour.h"
#include "State.h"
#include "Transition.h"

class FiniteStateMachine : public Behaviour
{
public:
	FiniteStateMachine() : currentState(nullptr) {}
	virtual ~FiniteStateMachine();

	State* AddState(State* state) { statesVec.push_back(state); return state; }
	Transition* AddTransition(Transition* transition) { transitionVec.push_back(transition); return transition; }
	Condition* AddCondition(Condition* condition) { conditionsVec.push_back(condition); return condition; }

	void SetCurrentState(State* state) { currentState = state; }

	virtual eBehaviourResult Execute(Agent* agent, float deltaTime);

protected:
	std::vector<State*> statesVec;
	std::vector<Transition*> transitionVec;
	std::vector<Condition*> conditionsVec;

	State* currentState;
};

