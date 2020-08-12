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

void Player::Draw()
{
	DrawTextureEx(texture, position, 0, 1.0f, WHITE);
}
