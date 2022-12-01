#include "Engine.h"

void Engine::updateEnemies(float dtAsSeconds)
{
	if (state == State::PLAYING)
	{
		//Spawns in an enemy based on spawnTime(seconds), caps enemies at 5;
		if (gameTimeTotal.asSeconds() > spawnTime && numOfEnemy < 100)
		{
			enemySpawnPoint = rand() % 1891;
			enemy1.push_back(new Enemy1);  //need to randomize this for different enemies
			enemy1.back()->spawn(enemySpawnPoint, -10);
			spawnTime += 1;  //controlls when next enemy will begin moving(seconds)
			numOfEnemy += 1;
		}
		else if (gameTimeTotal.asSeconds() > spawnTime)
		{
			enemySpawnPoint = rand() % 1891;
			enemy1[enemyIterator]->spawn(enemySpawnPoint, -10);
			spawnTime += 5;
			enemyIterator += 1;
			if (enemyIterator > 4)
				enemyIterator = 0;
		}

		//updates enemies
		for (int i = 0; i < enemy1.size(); i++)
		{
			if (!enemy1[i]->getm_Dead())
				enemy1[i]->update(dtAsSeconds, player1.getCenter());  //updates each enemy
		}
	}
}