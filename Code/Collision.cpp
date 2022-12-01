#include "Collision.h"

bool Collision::checkCollision(Vector2f projectile, Vector2f enemy)
{
	hitDetected = false;
	if(abs(projectile.x-enemy.x) <= 20 && abs(projectile.y - enemy.y) <= 20)
	{
		hitDetected = true;
	}

	return hitDetected;
}