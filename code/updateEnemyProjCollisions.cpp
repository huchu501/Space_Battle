#include "Engine.h"

void Engine::updateEnemyProjCollisions()
{
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