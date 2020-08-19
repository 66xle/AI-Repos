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
		behaviourVec[i]->Execute(this, deltaTime);
	}
}

void DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rotation, Ray ray)
{
	Vector2 offset = pivot * -1;

	float cosTheta = cos((double)rotation * DEG2RAD);
	float sinTheta = sin((double)rotation * DEG2RAD);

	Vector2 rotatedOffset = { 10, 15 };

	//rotatedOffset.x = offset.x * cosTheta + offset.y * -sinTheta;
	//rotatedOffset.y = offset.x * sinTheta + offset.y * cosTheta;

	DrawTextureEx(tex, pos - rotatedOffset, 0, 0.2, WHITE);
	//DrawTextureEx(tex, pos + rotatedOffset, rotation, 0.2, WHITE);

	//DrawLineEx({ ray.position.x, ray.position.y }, { ray.direction.x, ray.direction.y }, 1.0f, RED);

	//DrawLineEx(pos, { (float)(15 * cos(rotation)) + pos.x, (float)(15 * sin(rotation)) + pos.y }, 1.0f, RED);
	//DrawLine(pos.x, pos.y, (30 * cos(rotation / RAD2DEG)) + pos.x, (30 * sin(rotation / RAD2DEG)) + pos.y, RED);
}

void Agent::Draw()
{
	Vector2 pivot{ texture.width / 8, texture.height / 8 };
	DrawTextureWithPivot(texture, position, pivot, rotation, raycast.ray);
}

void Agent::AddBehaviour(Behaviour* behaviour)
{
	behaviourVec.push_back(behaviour);
}
