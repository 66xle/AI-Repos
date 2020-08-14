#pragma once
#include "raylib.h"
#include <vector>

class Node
{
public:
	Vector2 position;
	float gScore = 0;
	float hScore = 0;
	float fScore = 0;

	std::vector<Node*> connections;

	bool blocked = false;

	bool visited = false;

	Node* previous = nullptr;

	Node BlockNode();
};

