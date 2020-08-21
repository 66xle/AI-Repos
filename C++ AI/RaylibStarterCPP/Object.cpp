#include "Object.h"

void Object::CreateObject(const char* texName, Vector2 position)
{
	Image image = LoadImage(texName);
	texture = LoadTextureFromImage(image);
	this->position = position;
}

void Object::Update(Player* player)
{
	Vector3 adjust = { 0, 0, 0 };

	BoundingBox playerBox;
	playerBox.min = adjust + (player->position - 6.5f);
	playerBox.max = adjust + (player->position + 6.5f);

	BoundingBox objectBox;
	objectBox.min = adjust + (position - 3.5f);
	objectBox.max = adjust + (position + 3.5f);

	if (CheckCollisionBoxes(playerBox, objectBox))
	{
		keys++;

		if (keys == 1)
		{
			position = { 467, 215 };
		}
		if (keys == 2)
		{
			Image image = LoadImage("Door.png");
			texture = LoadTextureFromImage(image);
			position = { 240, 185 };
		}
	}
}

void DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rotation, float scale)
{
	Vector2 offset = pivot * -1;

	float cosTheta = cos((double)rotation * DEG2RAD);
	float sinTheta = sin((double)rotation * DEG2RAD);

	Vector2 rotatedOffset = { 10, 15 };

	DrawTextureEx(tex, pos - rotatedOffset, 0, scale, WHITE);

}

void Object::Draw()
{
	Vector2 pivot = { 0, 0 };
	float scale = 0.2;
	if (keys < 2)
	{
		pivot = { (float)texture.width / 8, (float)texture.height / 8 };
	}
	else
	{
		pivot = { (float)texture.width, (float)texture.height};
		scale = 0.5;
	}
	
	DrawTextureWithPivot(texture, position, pivot, 0, scale);
}
