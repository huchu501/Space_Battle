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
		// check collisions of player1 or 2 ships and enemy ships
		for (int z = 0; z < enemyContainer.size(); z++)
		{
			checkColP1 = col.checkCollision(player1.getPosition(), enemyContainer[z]->getPosition());
			checkColP2 = col.checkCollision(player2.getPosition(), enemyContainer[z]->getPosition());
			if (checkColP1 || checkColP2)
			{
				player1.decHealth(); //reduces health till death
			}
		}
	}
}