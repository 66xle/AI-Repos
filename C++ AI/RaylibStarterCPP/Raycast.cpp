#include "Raycast.h"
#include "Agent.h"
#include <iostream>

void Raycast::Cast(std::vector<BoundingBox> walls, Agent agent)
{
	Vector3 adjustPosition = { 0, 0, 0 };
	ray.position = adjustPosition + agent.position;
	ray.direction = { (float)(30 * cos(agent.rotation) * RAD2DEG ) + agent.position.x, (float)(30 * sin(agent.rotation) * RAD2DEG) + agent.position.y, 0 };

	for (BoundingBox box : walls)
	{
		if (CheckCollisionRayBox(ray, box))
		{
			//Vector2 boxMiddle = { box.min.x + 16.0f, box.min.y + 16.0f };

			//float angle = atan2(ray.position.y - boxMiddle.y, ray.position.x - boxMiddle.x );

			//angle /= 6.28319;

			//double x = 32.0;
			//double y = 32.0;
			//
			//Vector3 direction;
			//direction.z = 0.0f;

			//float s1x = -atan2(y, x);
			//float s1y = atan2(y, x);

			//float s3x = PI - atan2(y, x);
			//float s3y = PI + atan2(y, x);

			//float s2x = atan2(y, x);
			//float s2y = PI - atan2(y, x);

			//float s4x = PI + atan2(y, x);
			//float s4y = -atan2(y, x);

			//if (angle > -atan2(y, x) && angle <= atan2(y, x) || angle > (PI - atan2(y, x) && angle <= (PI + atan2(y, x)))) // East and West
			//{
			//	direction.x = boxMiddle.x + (x / 2);
			//	direction.y = (x / 2 * tan(angle) + boxMiddle.y);
			//}
			//else if (angle > atan2(y, x) && angle <= (PI - atan2(y, x) || angle > (PI + atan2(y, x) && angle <= -atan2(y, x)))) // North and South
			//{
			//	direction.x = boxMiddle.x + y / (2 * tan(angle));
			//	direction.y = y / 2 + boxMiddle.y;
			//}

			//double dx = (double)ray.position.x - direction.x;
			//double dy = (double)ray.position.y - direction.y;
			//float distance = sqrt((dx * dx) + (dy * dy));

			//double rx = (double)ray.position.x - ray.direction.x;
			//double ry = (double)ray.position.y - ray.direction.y;
			//float shortDistance = sqrt((rx * rx) + (ry * ry));

			//if (distance < shortDistance)
			//{
			//	ray.direction = direction;
			//}
		}
	}

	ray.direction = { (float)(30 * cos(agent.rotation)) + agent.position.x, (float)(30 * sin(agent.rotation)) + agent.position.y, 0 };

}
