#pragma once
#include "raylib.h"
#include "Boundary.h"
#include "Player.h"
#include <vector>

class Agent;

class Raycast
{
public:
	std::vector<Ray> rays;

	void Cast(std::vector<Boundary> walls, Agent agent);
	bool PlayerDetect(Player* player);
};

