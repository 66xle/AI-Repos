#include "PlayerLostCondition.h"

// Search Area to Patrol
bool PlayerLostCondition::test(Agent* agent) const
{
    if (graph->path.size() == 0)
    {
        return true;
    }

    return false;
}
