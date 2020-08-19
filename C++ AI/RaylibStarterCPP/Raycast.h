#pragma once
#include "raylib.h"
#include <vector>

class Agent;

class Raycast
{
public:
	Ray ray;

	void Cast(std::vector<BoundingBox> walls, Agent agent);
};

