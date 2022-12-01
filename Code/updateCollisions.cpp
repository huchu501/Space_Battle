#include "Engine.h"

void Engine::updateCollisions()
{
	if (state == State::PLAYING)
	{
		//Checks collision of friendly projectile and enemy ship
		for (int i = 0; i < player1.getProjectileSize(); i++)
		{
			for (int j = 0; j < enemy1.size(); j++)
			{
				checkCol = col.checkCollision(player1.getProjectilePosition(i), enemy1[j]->getPosition());
				if (checkCol)
				{
					enemy1[j]->hit(); //reduces health till death
					player1.stopProjectile(i); //sends projectile off map
				}
			}
		}

	}
}