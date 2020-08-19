#include "Vector2Math.h"

Vector2 operator *(Vector2 vec, float deltaTime)
{
	vec.x *= deltaTime;
	vec.y *= deltaTime;

	return vec;
}

Vector2 operator*(Vector2 lhs, Vector2 rhs)
{
	lhs.x *= rhs.x;
	lhs.y *= rhs.y;

	return lhs;
}

Vector2 operator/(Vector2 vec, float value)
{
	vec.x /= value;
	vec.y /= value;

	return vec;
}

Vector2 operator/(Vector2 lhs, Vector2 rhs)
{
	lhs.x /= rhs.x;
	lhs.y /= rhs.y;

	return lhs;
}

Vector2 operator +(Vector2 lhs, Vector2 rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	return lhs;
}

Vector2 operator+(Vector2 lhs, float value)
{
	lhs.x += value;
	lhs.y += value;

	return lhs;
}

Vector2 operator - (Vector2 lhs, Vector2 rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;

	return lhs;
}

Vector2 operator-(Vector2 lhs, float value)
{
	lhs.x -= value;
	lhs.y -= value;

	return lhs;
}

Vector3 operator+(Vector3 lhs, Vector2 rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	lhs.z = 0;

	return lhs;
}

Vector3 operator-(Vector3 lhs, Vector3 rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	lhs.z = 0;

	return lhs;
}

Vector2 Vector2Normalise(Vector2 vec)
{
	float magnitude = sqrtf((vec.x * vec.x) + (vec.y * vec.y));

	vec.x /= magnitude;
	vec.y /= magnitude;

	return vec;
}