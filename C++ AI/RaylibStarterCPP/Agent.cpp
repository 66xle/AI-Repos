#include "Agent.h"
#include "Behaviour.h"

Agent::Agent()
{

}

Agent::~Agent()
{

}

void Agent::Update(float deltaTime)
{
	for (int i = 0; i < behaviourVec.size(); i++)
	{
		Vector2 force = behaviourVec[i]->Update(this, deltaTime);

		velocity = velocity + (force * deltaTime);
		position = position + (velocity * deltaTime);
	}
}

void DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rotation)
{
	Vector2 offset = pivot * -1;

	float cosTheta = cos(rotation * DEG2RAD);
	float sinTheta = sin(rotation * DEG2RAD);

	Vector2 rotatedOffset;

	rotatedOffset.x = offset.x * cosTheta + offset.y * -sinTheta;
	rotatedOffset.y = offset.x * sinTheta + offset.y * cosTheta;

	DrawTextureEx(tex, pos + rotatedOffset, rotation, 0.2, WHITE);

	DrawLine(pos.x, pos.y, (30 * cos(rotation / RAD2DEG)) + pos.x, (30 * sin(rotation / RAD2DEG)) + pos.y, RED);
}

void Agent::Draw()
{
	Vector2 pivot{ texture.width / 8, texture.height / 8 };
	DrawTextureWithPivot(texture, position, pivot, rotation * RAD2DEG);
}

void Agent::AddBehaviour(Behaviour* behaviour)
{
	behaviourVec.push_back(behaviour);
}
