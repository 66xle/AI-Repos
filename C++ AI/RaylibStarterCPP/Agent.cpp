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

void DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rotation, std::vector<Ray> rays)
{
	Vector2 offset = pivot * -1;

	float cosTheta = cos((double)rotation * DEG2RAD);
	float sinTheta = sin((double)rotation * DEG2RAD);

	Vector2 rotatedOffset = { 10, 15 };

	for (Ray ray : rays)
	{
		DrawLineEx({ ray.position.x, ray.position.y }, { ray.direction.x, ray.direction.y }, 1.0f, Fade(RED, 0.2));
	}

	DrawTextureEx(tex, pos - rotatedOffset, 0, 0.2, WHITE);

	//DrawLineEx(pos, { (float)(500 * cos(rotation)) + pos.x, (float)(500 * sin(rotation)) + pos.y }, 1.0f, RED);
}

void Agent::Draw()
{
	Vector2 pivot{ texture.width / 8, texture.height / 8 };
	DrawTextureWithPivot(texture, position, pivot, rotation, raycast.rays);
}

void Agent::AddBehaviour(Behaviour* behaviour)
{
	behaviourVec.push_back(behaviour);
}
