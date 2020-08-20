#include "LOSLostCondition.h"
#include <iostream>

// Chase to Patrol
bool LOSLostCondition::test(Agent* agent) const
{
    if (agent->raycast.PlayerDetect(player))
    {
        return false; // Player is in LOS
    }
    return true; // Lost sight of Player
}
