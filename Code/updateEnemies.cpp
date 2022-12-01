#include "Engine.h"

void Engine::updateEnemies(float dtAsSeconds)
{
	if (state == State::PLAYING)
	{
		//Spawns in an enemy based on spawnTime(seconds), caps enemies at 5;
		if (gameTimeTotal.asSeconds() > spawnTime && numOfEnemy < 100)
		{
			enemySpawnPoint = rand() % 1891;
			enemyContainer.push_back(new EnemyB1);  //need to randomize this for different enemies
			enemyContainer.back()->spawn(enemySpawnPoint, -10);
			enemySpawnPoint = rand() % 1891;
			enemyContainer.push_back(new EnemyB2);  //need to randomize this for different enemies
			enemyContainer.back()->spawn(enemySpawnPoint, -10);
			spawnTime += 5;  //controlls when next enemy will begin moving(seconds)
			numOfEnemy += 2;
		}
		else if (gameTimeTotal.asSeconds() > spawnTime)
		{
			enemySpawnPoint = rand() % 1891;
			enemyContainer[enemyIterator]->spawn(enemySpawnPoint, -10);
			spawnTime += 5;
			enemyIterator += 1;
			if (enemyIterator > 4)
				enemyIterator = 0;
		}

		//updates enemies
		for (int i = 0; i < enemyContainer.size(); i++)
		{
			if (i % 2 == 0)
			{
				if (!enemyContainer[i]->getm_Dead())
					enemyContainer[i]->update(dtAsSeconds, player1.getCenter());  //updates each enemy
			}
			else
			{
				if (!enemyContainer[i]->getm_Dead())
					enemyContainer[i]->update(dtAsSeconds, player2.getCenter());  //updates each enemy
			}
		}
	}
}