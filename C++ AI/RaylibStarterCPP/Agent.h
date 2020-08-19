#pragma once
#include "Vector2Math.h"
#include "Raycast.h"
#include <vector>

class Behaviour;
class Raycast;

class Agent
{
public:
	std::vector<Behaviour*> behaviourVec;

	Texture texture;
	Vector2 position = { 0, 0 };
	Vector2 velocity = { 0, 0 };
	float rotation = 0;
	Raycast raycast;

	Agent();
	~Agent();

	// Update agent and behaviour
	virtual void Update(float deltaTime);

	// Draw the agent
	virtual void Draw();

	// Add behaviour to target
	void AddBehaviour(Behaviour* behaviour);
};

