#include "Condition.h"

eBehaviourResult Condition::Execute(Agent* agent, float deltaTime)
{
    if (test(agent))
    {
        return eBehaviourResult::SUCCESS;
    }
    return eBehaviourResult::FAILURE;
}
