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
	}
	
	if (state == State::PLAYING)
	{
		// update the two players
		stringstream ssScore;
		score++;
		ssScore << "Score:" << score;
		ssScore.str();
		hud.setScoreText(ssScore.str());
		player1.update(dtAsSeconds, bgClock);
		player2.update(dtAsSeconds, bgClock);
		// update healthBar
		healthBar.updateHealthBar(player1.getHealth());
		// end the game when health is 0
		if (healthBar.getHeartCount() == 0) { state = State::GAME_OVER; }

		
	}
	// update HUD
	float msSinceLastHUDUpdate = 0;
	float msHUDFrameInterval = 1000;
	msSinceLastHUDUpdate++; // increment the number of frames since last hud calculation
	if (msSinceLastHUDUpdate > msHUDFrameInterval)  // update HUD every msHUDFrameInterval frames
	{  // update score text


		msSinceLastHUDUpdate = 0;
	}
}

