#include "Engine.h"


//feed engine seconds
void Engine::update(float dtAsSeconds)
{
	// background boundaries
	space.height = 1080;
	space.width = 1920;
	space.left = 0;
	space.top = 0;

	if (state == State::PLAYING)
	{
		// spawn the two players at its spawn location
		player1.spawn(space, resolution);
		player2.spawn(space, resolution);

		// update the two players
		player1.update(dtAsSeconds);
		player2.update(dtAsSeconds);
	}
}