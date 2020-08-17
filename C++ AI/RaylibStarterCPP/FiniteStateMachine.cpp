#include "FiniteStateMachine.h"

FiniteStateMachine::~FiniteStateMachine()
{
	for (auto state : statesVec)
		delete state;
	for (auto t : transitionVec)
		delete t;
	for (auto c : conditionsVec)
		delete c;
}

eBehaviourResult FiniteStateMachine::Execute(Agent* agent, float deltaTime)
{
	if (currentState != nullptr)
	{
		Transition* transition = currentState->getTriggeredTransition(agent);

		if (transition != nullptr)
		{
			currentState->Exit(agent); // Exit current state
			currentState = transition->getTargetState(); // Get new state
			currentState->Init(agent); // Start new state
		}

		currentState->Update(agent, deltaTime);
		return eBehaviourResult::SUCCESS;
	}
	return eBehaviourResult::FAILURE;
}
