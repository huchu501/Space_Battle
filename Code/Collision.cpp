#include "Collision.h"

bool Collision::checkCollision(Vector2f projectile, Vector2f enemy)
{
	hitDetected = false;
	if(abs(projectile.x-enemy.x) <= 10 && abs(projectile.y - enemy.y) <= 10)
	{
		hitDetected = true;
	}

	return hitDetected;
}