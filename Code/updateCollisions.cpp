#include "Engine.h"

void Engine::updateCollisions()
{
	if (state == State::PLAYING)
	{
		//Checks collision of player1 projectiles and enemy ships
		for (int i = 0; i < player1.getProjectileSize(); i++)
		{
			for (int j = 0; j < enemyContainer.size(); j++)
			{
				checkCol = col.checkCollision(player1.getProjectilePosition(i), enemyContainer[j]->getPosition());
				if (checkCol)
				{
					enemyContainer[j]->hit(); //reduces health till death
					player1.stopProjectile(i); //sends projectile off map
				}
			}
		}
		//Checks collision of player2 projectiles and enemy ships
		for (int i = 0; i < player2.getProjectileSize(); i++)
		{
			for (int j = 0; j < enemyContainer.size(); j++)
			{
				checkCol = col.checkCollision(player2.getProjectilePosition(i), enemyContainer[j]->getPosition());
				if (checkCol)
				{
					enemyContainer[j]->hit(); //reduces health till death
					player2.stopProjectile(i); //sends projectile off map
				}
			}
		}

	}
}