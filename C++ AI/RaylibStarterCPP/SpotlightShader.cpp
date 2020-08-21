#include "SpotlightShader.h"

Shader SpotlightShader::Init()
{
	// Use default vert shader
	shader = LoadShader(0, "spotlight.glsl");

	for (int i = 0; i < MAXSPOT; i++)
	{
		char posName[32] = "spots[x].pos\0";
		char innerName[32] = "spots[x].inner\0";
		char radiusName[32] = "spots[x].radius\0";

		posName[6] = '0' + i;
		innerName[6] = '0' + i;
		radiusName[6] = '0' + i;

		spots[i].posLoc = GetShaderLocation(shader, posName);
		spots[i].innerLoc = GetShaderLocation(shader, innerName);
		spots[i].radiusLoc = GetShaderLocation(shader, radiusName);

	}

	// tell the shader how wide the screen is so we can have
	// a pitch black screen.
	{
		unsigned int wLoc = GetShaderLocation(shader, "screenWidth");
		float sw = 512;
		SetShaderValue(shader, wLoc, &sw, UNIFORM_FLOAT);
	}

	for (int i = 0; i < MAXSPOT; i++)
	{
		spots[i].pos.x = 0;
		spots[i].pos.y = 0;
		spots[i].vel = { 0, 0 };

		spots[i].inner = 200;
		spots[i].radius = 220;

		SetShaderValue(shader, spots[i].posLoc, &spots[i].pos.x, UNIFORM_VEC2);
		SetShaderValue(shader, spots[i].innerLoc, &spots[i].inner, UNIFORM_FLOAT);
		SetShaderValue(shader, spots[i].radiusLoc, &spots[i].radius, UNIFORM_FLOAT);
	}

	return shader;
}

Shader SpotlightShader::Update(Player* player)
{
	// Update the spots, send them to the shader
	for (int i = 0; i < MAXSPOT; i++)
	{
		spots[i].pos.x = GetScreenWidth() / 2;
		spots[i].pos.y = GetScreenHeight() / 2;

		SetShaderValue(shader, spots[i].posLoc, &spots[i].pos.x, UNIFORM_VEC2);
	}

	return shader;
}

void SpotlightShader::Draw()
{
	BeginShaderMode(shader);
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
	EndShaderMode();
}
