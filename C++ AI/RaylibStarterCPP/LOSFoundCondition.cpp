#include "LOSFoundCondition.h"

// Patrol To Chase
bool LOSFoundCondition::test(Agent* agent) const
{
    if (agent->raycast.PlayerDetect(player))
    {
        return true; // Player is in LOS
    }
    return false; // Player not in LOS
}
