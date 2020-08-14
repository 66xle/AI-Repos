#include "ChaseState.h"

void ChaseState::Update(Agent* agent, float deltaTime)
{
	Vector2 velocity = target->position - agent->position;

	// Set Rotation facing Target
	agent->rotation = atan2f(target->position.y - agent->position.y, target->position.x - agent->position.x);

	Vector2 desiredVelocity = Vector2Normalise(velocity) * maxSpeed;

	//Vector2 force = desiredVelocity - agent->velocity;
	Vector2 force = desiredVelocity;

	agent->velocity = (force * deltaTime);
	agent->position = agent->position + (agent->velocity * deltaTime);
}
