#include "Collision.h"

// player can be either the projectile or the player ship
bool Collision::checkCollision(FloatRect player, FloatRect enemy)
{
	hitDetected = false;
	if(player.intersects(enemy))
	//if(abs(projectile.x-enemy.x) <= 20 && abs(projectile.y - enemy.y) <= 20)
	{
		hitDetected = true;
	}

	return hitDetected;
}
