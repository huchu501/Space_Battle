#include "Collision.h"

bool Collision::checkCollision(FloatRect projectile, FloatRect enemy)
{
	hitDetected = false;
	if(projectile.intersects(enemy))
	//if(abs(projectile.x-enemy.x) <= 20 && abs(projectile.y - enemy.y) <= 20)
	{
		hitDetected = true;
	}

	return hitDetected;
}