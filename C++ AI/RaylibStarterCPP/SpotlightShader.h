#pragma once
#include "raylib.h"
#include "Player.h"

// Spot data
typedef struct {
	Vector2 pos;
	Vector2 vel;
	float inner;
	float radius;

	// Shader locations
	unsigned int posLoc;
	unsigned int innerLoc;
	unsigned int radiusLoc;
} Spot;

#define MAXSPOT           3	// NB must be the same as define in shader

class SpotlightShader
{
public:
	Shader shader;

	// Get the locations of spots in the shader
	Spot spots[MAXSPOT];

	Shader Init();
	Shader Update(Player* player);
	void Draw();
};

