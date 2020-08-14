#include "State.h"
#include "State.h"

Transition* State::getTriggeredTransition(Agent* agent)
{
    for (auto transition : transitionsVec)
    {
        if (transition->hasTriggered(agent))
        {
            return transition;
        }
    }

    return nullptr;
}
