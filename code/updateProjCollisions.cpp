#include "Engine.h"

void Engine::updateProjCollisions()
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
					//if (enemyContainer[j]->getm_Dead())
					player1.stopProjectile(i); //sends projectile off map
					score += 5;
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
					score += 5;
				}
			}
		}
		//Checks collision of enemy projectiles and players
		for (int i = 0; i < enemyContainer.size(); i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (enemyContainer[i]->getType() > 1)
				{
					checkCol = col.checkCollision(player1.getPosition(), enemyContainer[i]->getProjectilePosition(j));
					if (checkCol)
					{
						//reduces player1 health till here
						enemyContainer[i]->stopProjectile();
						player1.decHealth();
					}
				}
				if (enemyContainer[i]->getType() > 1)
				{
					checkCol = col.checkCollision(player2.getPosition(), enemyContainer[i]->getProjectilePosition(j));
					if (checkCol)
					{
						//reduces player2 health till here
						enemyContainer[i]->stopProjectile();
						player1.decHealth();
					}
				}
			}
		}
	}
}