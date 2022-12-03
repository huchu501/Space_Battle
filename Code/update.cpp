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

	if (state == State::MENU)
	{
		// spawn the two players at its spawn location
		player1.spawn(space, resolution, tileSize);
		player2.spawn(space, resolution, tileSize);
	}
	
	if (state == State::PLAYING)
	{

		// update the two players
		player1.update(dtAsSeconds, bgClock);
		player2.update(dtAsSeconds, bgClock);
	}
	
	if (state == State::GAME_OVER)
	{
		
	}
	// update HUD
	float msSinceLastHUDUpdate = 0;
	float msHUDFrameInterval = 1000;
	msSinceLastHUDUpdate++; // increment the number of frames since last hud calculation
	if (msSinceLastHUDUpdate > msHUDFrameInterval)  // update HUD every msHUDFrameInterval frames
	{  // update score text
		stringstream ssScore;
		ssScore << "Score:" << 55;
		hud.setScoreText(ssScore.str());

		msSinceLastHUDUpdate = 0;
	}
}