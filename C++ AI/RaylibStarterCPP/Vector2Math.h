#pragma once
#include "raylib.h"


Vector2 operator *(Vector2 vec, float deltaTime);
Vector2 operator *(Vector2 lhs, Vector2 rhs);

Vector2 operator /(Vector2 vec, float value);
Vector2 operator /(Vector2 lhs, Vector2 rhs);

Vector2 operator +(Vector2 lhs, Vector2 rhs);
Vector2 operator +(Vector2 lhs, float value);

Vector2 operator -(Vector2 lhs, Vector2 rhs);

Vector2 Vector2Normalise(Vector2 vec);

