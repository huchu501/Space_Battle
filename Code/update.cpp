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
	}
}