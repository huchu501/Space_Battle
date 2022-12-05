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
					if (enemyContainer[j]->getm_Dead())
						score += 50;
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
		//Checks collision of player1 Ship and enemy ships
		for (int j = 0; j < enemyContainer.size(); j++)
		{
			checkCol = col.checkCollision(player1.getPosition(), enemyContainer[j]->getPosition());
			if (checkCol)
			{
				enemyContainer[j]->sendShadowRealm(); //reduces enemy health till death
				//Make player lose health here
			}
		}
		//Checks collision of player2 Ship and enemy ships
		for (int j = 0; j < enemyContainer.size(); j++)
		{
			checkCol = col.checkCollision(player2.getPosition(), enemyContainer[j]->getPosition());
			if (checkCol)
			{
				enemyContainer[j]->sendShadowRealm(); //reduces enemy health till death
				//Make player lose health here
			}
		}

		//Checks collision of enemy projectiles and players
		for (int i = 0; i < enemyContainer.size(); i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (enemyContainer[i]->getType() > 1)
				{
					checkCol = col.checkCollision(player1.getPosition(), enemyContainer[i]->getProjectilePosition(j));
					if (checkCol)
					{
						//reduces player1 health till here
						enemyContainer[i]->stopProjectile();
					}
				}
				if (enemyContainer[i]->getType() > 1)
				{
					checkCol = col.checkCollision(player2.getPosition(), enemyContainer[i]->getProjectilePosition(j));
					if (checkCol)
					{
						//reduces player2 health till here
						enemyContainer[i]->stopProjectile();
					}
				}
			}
		}
	}
}