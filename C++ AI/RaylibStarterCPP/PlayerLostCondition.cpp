#include "PlayerLostCondition.h"

// Search Area to Patrol
bool PlayerLostCondition::test(Agent* agent) const
{
    // If monster reaches the end of path
    if (graph->path.size() == 0)
    {
        return true;
    }

    return false;
}
