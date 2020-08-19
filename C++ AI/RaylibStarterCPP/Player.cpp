#include "Player.h"

void Player::PlayerMovement(float deltaTime, Map map)
{
	Vector2 tempPosition;
	if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D))
	{
		tempPosition = position;
		tempPosition.y -= 70 * deltaTime;
		tempPosition.x += 70 * deltaTime;
		if (WallCollision(tempPosition, map) == false)
		{
			position.y -= 70 * deltaTime;
			position.x += 70 * deltaTime;
		}
	}
	else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_A))
	{
		tempPosition = position;
		tempPosition.y -= 70 * deltaTime;
		tempPosition.x -= 70 * deltaTime;
		if (WallCollision(tempPosition, map) == false)
		{
			position.y -= 70 * deltaTime;
			position.x -= 70 * deltaTime;
		}
	}
	else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_D))
	{
		tempPosition = position;
		tempPosition.y += 70 * deltaTime;
		tempPosition.x += 70 * deltaTime;
		if (WallCollision(tempPosition, map) == false)
		{
			position.y += 70 * deltaTime;
			position.x += 70 * deltaTime;
		}
	}
	else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_A))
	{
		tempPosition = position;
		tempPosition.y += 70 * deltaTime;
		tempPosition.x -= 70 * deltaTime;
		if (WallCollision(tempPosition, map) == false)
		{
			position.y += 70 * deltaTime;
			position.x -= 70 * deltaTime;
		}
	}
	else
	{
		if (IsKeyDown(KEY_W))
		{
			tempPosition = position;
			tempPosition.y -= 100 * deltaTime;
			if (WallCollision(tempPosition, map) == false)
			{
				position.y -= 100 * deltaTime;
			}
		}
		if (IsKeyDown(KEY_S))
		{
			tempPosition = position;
			tempPosition.y += 100 * deltaTime;
			if (WallCollision(tempPosition, map) == false)
			{
				position.y += 100 * deltaTime;
			}
		}
		if (IsKeyDown(KEY_A))
		{
			tempPosition = position;
			tempPosition.x -= 100 * deltaTime;
			if (WallCollision(tempPosition, map) == false)
			{
				position.x -= 100 * deltaTime;
			}
		}
		if (IsKeyDown(KEY_D))
		{
			tempPosition = position;
			tempPosition.x += 100 * deltaTime;
			if (WallCollision(tempPosition, map) == false)
			{
				position.x += 100 * deltaTime;
			}
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

bool Player::WallCollision(Vector2 position, Map map)
{
	BoundingBox playerBox;
	Vector3 adjust = { 0, 0, 0 };
	playerBox.min = adjust + (position - 6.5f);
	playerBox.max = adjust + (position + 6.5f);

	for (BoundingBox box : map.boxes)
	{
		if (CheckCollisionBoxes(box, playerBox))
		{
			return true;
		}
	}
	return false;
}
