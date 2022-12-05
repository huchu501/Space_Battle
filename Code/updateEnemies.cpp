#include "Engine.h"

void Engine::updateEnemies(float dtAsSeconds)
{
	if (state == State::PLAYING)
	{
		//Spawns in an enemy based on spawnTime(seconds)
		if (gameTimeTotal.asSeconds() > spawnTime)
		{
			enemySpawnPoint = rand() % 1890;
			enemyContainer[enemyIterator]->spawn(enemySpawnPoint, -10);

			spawnTime += rateOfSpawn;  //rate of spawn
			enemyIterator += 1;

			if (enemyIterator >= enemyContainer.size())
				enemyIterator = 0;
		}

		//updates enemies
		for (int i = 0; i < enemyContainer.size(); i++)
		{
			switch (enemyContainer[i]->getType())
			{
			case 0:
				if (!enemyContainer[i]->getm_Dead())
					enemyContainer[i]->update(dtAsSeconds, player1.getCenter(), bgClock);  //updates each enemy
				break;
			case 1:
				if (!enemyContainer[i]->getm_Dead())
					enemyContainer[i]->update(dtAsSeconds, player2.getCenter(), bgClock);
				break;
			case 2:
				if (!enemyContainer[i]->getm_Dead())
				{
					enemyContainer[i]->update(dtAsSeconds, player1.getCenter(), bgClock);  //updates each enemy
				}
				enemyContainer[i]->updateProjectile(dtAsSeconds, player1.getCenter(), bgClock);
				break;
			case 3:
				if (!enemyContainer[i]->getm_Dead())
				{
					enemyContainer[i]->update(dtAsSeconds, player2.getCenter(), bgClock);
				}
				enemyContainer[i]->updateProjectile(dtAsSeconds, player2.getCenter(), bgClock);
				break;
			}

		}
	}
}