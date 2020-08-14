#include "Player.h"

void Player::PlayerMovement(float deltaTime)
{
	if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D))
	{
		position.y -= 70 * deltaTime;
		position.x += 70 * deltaTime;
	}
	else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_A))
	{
		position.y -= 70 * deltaTime;
		position.x -= 70 * deltaTime;
	}
	else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_D))
	{
		position.y += 70 * deltaTime;
		position.x += 70 * deltaTime;
	}
	else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_A))
	{
		position.y += 70 * deltaTime;
		position.x -= 70 * deltaTime;
	}
	else
	{
		if (IsKeyDown(KEY_W))
		{
			position.y -= 100 * deltaTime;
		}
		if (IsKeyDown(KEY_S))
		{
			position.y += 100 * deltaTime;
		}
		if (IsKeyDown(KEY_A))
		{
			position.x -= 100 * deltaTime;
		}
		if (IsKeyDown(KEY_D))
		{
			position.x += 100 * deltaTime;
		}
	}
}

void Player::DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rotation)
{
	Vector2 offset = pivot * -1;

	float cosTheta = cos((double)rotation * DEG2RAD);
	float sinTheta = sin((double)rotation * DEG2RAD);

	Vector2 rotatedOffset;

	rotatedOffset.x = offset.x * cosTheta + offset.y * -sinTheta;
	rotatedOffset.y = offset.x * sinTheta + offset.y * cosTheta;

	DrawTextureEx(tex, pos + rotatedOffset, rotation, 1, WHITE);
}

void Player::Draw()
{
	Vector2 pivot = { texture.width / 2, texture.height / 2 };
	DrawTextureWithPivot(texture, position, pivot, 0);
}

bool Player::IsNear(Node* node)
{
	float dx = abs(position.x - node->position.x);
	float dy = abs(position.y - node->position.y);
	float radius = 16;

	if ((dx * dx) + (dy * dy) <= radius * radius)
	{
		return true;
	}
	return false;
}
