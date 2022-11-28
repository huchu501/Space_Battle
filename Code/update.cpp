#include "Engine.h"


//feed engine seconds
void Engine::update(float dtAsSeconds)
{
	// background boundaries
	space.height = 1030;
	space.width = 1890;
	space.left = 0;
	space.top = 0;

	// set to 50 to create new algorithm for color changing imgae
	int tileSize = 50;
	if (state == State::UPGRADE)
	{
		// spawn the two players at its spawn location
		player1.spawn(space, resolution, tileSize);
		player2.spawn(space, resolution, tileSize);
	}
	if(state == State::PLAYING)
	{
		// update the two players
		player1.update(dtAsSeconds);
		player2.update(dtAsSeconds);

		//Spawns in an enemy based on spawnTime(seconds);
		if (gameTimeTotal.asSeconds() > spawnTime)
		{
			enemySpawnPoint = rand() % 1891;
			enemy1.push_back(new Enemy1);  //need to randomize this for different enemies
			enemy1.back()->spawn(enemySpawnPoint, -10);
			spawnTime += 5;  //controlls when next enemy will begin moving(seconds)
			numOfEnemy += 1;
		}
		for (int i = 0; i < numOfEnemy; i++)
		{
			enemy1[i]->update(dtAsSeconds, player1.getCenter());  //updates each enemy
		}
		
	}
}