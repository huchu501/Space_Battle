#include "Engine.h"
//feed engine seconds
void Engine::updatePlayers(float dtAsSeconds)
{
	// background boundaries
	space.height = 1030;
	space.width = 1890;
	space.left = 0;
	space.top = 0;
	// set to 50 to create new algorithm for color changing imgae
	int tileSize = 50;

	if (state == State::MENU)
	{
		// spawn the two players at its spawn location, RESET all player stuff
		player1.spawn(space, resolution, tileSize);
		player2.spawn(space, resolution, tileSize);
		player1.resetPlayerStats();
		player2.resetPlayerStats();
		for (int i = 0; i < player1.getProjectileSize(); i++)
		{
			player1.stopProjectile(i);
			player2.stopProjectile(i);
		}
		upClock.restart();
		upTotal = 0;
	}
	
	if (state == State::PLAYING)
	{
		// update the two players and score
		stringstream ssScore;
		ssScore << "Score:" << score;
		ssScore.str();
		hud.setScoreText(ssScore.str());
		player1.update(dtAsSeconds, bgClock);
		player2.update(dtAsSeconds, bgClock);
		// update healthBar
		healthBar.updateHealthBar(player1.getHealth());
		// end the game when health is 0
		if (healthBar.getHeartCount() == 0) { state = State::GAME_OVER; }
		// upgrades
		player1.updateUpgrade(upClock);
		player2.updateUpgrade(upClock);
		upTime = upClock.getElapsedTime();
		if (upTime.asSeconds() > upTotal)
		{
			int num = rand() % 5;
			if (num == 0 || num == 1)
				speedUp.spawnPos();
			else if (num == 2 || num ==3)
				projUp.spawnPos();
			else if (num == 4)
				healthUp.spawnPos();
			upTotal += 15;
		}
	}
}

