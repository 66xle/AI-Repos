#include "Raycast.h"
#include "Agent.h"
#include <iostream>

void Raycast::Cast(std::vector<Boundary> walls, Agent agent)
{
	rays.clear();
	float rayAngle = agent.rotation - (22.50f * DEG2RAD);

	for (float i = 0; i < 45; i += 0.5)
	{
		Ray ray;
		Vector3 adjustPosition = { 0, 0, 0 };
		ray.position = adjustPosition + agent.position;
		ray.direction = { (float)(500 * cos(rayAngle + (i * DEG2RAD))) + agent.position.x, (float)(500 * sin(rayAngle + (i * DEG2RAD))) + agent.position.y, 0 };

		for (Boundary wall : walls)
		{
			float x1 = wall.p1.x;
			float y1 = wall.p1.y;
			float x2 = wall.p2.x;
			float y2 = wall.p2.y;

			float x3 = ray.position.x;
			float y3 = ray.position.y;
			float x4 = ray.direction.x;
			float y4 = ray.direction.y;

			float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
			if (den == 0)
			{
				continue;
			}

			// Math for intersecting lines
			float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
			float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;
			if (t > 0 && t < 1 && u > 0) // Raycast Collision
			{
				Vector2 point = { x1 + t * (x2 - x1), y1 + t * (y2 - y1) };

				double dx = (double)ray.position.x - point.x;
				double dy = (double)ray.position.y - point.y;
				float distance = sqrt((dx * dx) + (dy * dy));

				double rx = (double)ray.position.x - ray.direction.x;
				double ry = (double)ray.position.y - ray.direction.y;
				float shortDistance = sqrt((rx * rx) + (ry * ry));

				if (distance < shortDistance)
				{
					Vector3 adjust = { 0, 0, 0 };
					ray.direction = adjust + point;
				}
			}
		}
		rays.push_back(ray);
	}
}

Boundary CreateWall(Vector2 p1, Vector2 p2)
{
	Boundary wall;
	wall.p1 = p1;
	wall.p2 = p2;
	return wall;
}

bool Raycast::PlayerDetect(Player* player)
{
	std::vector<Boundary> playerWalls;
	playerWalls.push_back(CreateWall(player->position - 6.5, { player->position.x + 6.5f, player->position.y - 6.5f }));
	playerWalls.push_back(CreateWall(player->position - 6.5, { player->position.x - 6.5f, player->position.y + 6.5f }));
	playerWalls.push_back(CreateWall(player->position + 6.5, { player->position.x - 6.5f, player->position.y + 6.5f }));
	playerWalls.push_back(CreateWall(player->position + 6.5, { player->position.x + 6.5f, player->position.y - 6.5f }));


	for (Ray ray : rays)
	{
		for (Boundary wall : playerWalls)
		{
			float x1 = wall.p1.x;
			float y1 = wall.p1.y;
			float x2 = wall.p2.x;
			float y2 = wall.p2.y;

			float x3 = ray.position.x;
			float y3 = ray.position.y;
			float x4 = ray.direction.x;
			float y4 = ray.direction.y;

			float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
			if (den == 0)
			{
				continue;
			}

			// Math for intersecting lines
			float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
			float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;
			if (t > 0 && t < 1 && u > 0) // Raycast Collision
			{
				// Check if no walls are blocking LOS to Player
				Vector2 point = { x1 + t * (x2 - x1), y1 + t * (y2 - y1) };

				double dx = (double)ray.position.x - point.x;
				double dy = (double)ray.position.y - point.y;
				float distance = sqrt((dx * dx) + (dy * dy));

				double rx = (double)ray.position.x - ray.direction.x;
				double ry = (double)ray.position.y - ray.direction.y;
				float shortDistance = sqrt((rx * rx) + (ry * ry));

				if (distance < shortDistance)
				{
					return true;
				}
			}
		}
	}
	return false;
}
