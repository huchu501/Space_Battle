#include "Engine.h"

void Engine::run()
{
	//restart clocks before main game loop:
	clock.restart();
	bgClock.restart();

	while (window.isOpen())
	{

		// update time
		Time dt = clock.restart();
		// keep on updating the total game time
		gameTimeTotal += dt;
		// convert float to seconds
		float dtAsSeconds = dt.asSeconds();

		input();
		updatePlayers(dtAsSeconds);
		updateEnemies(dtAsSeconds);
		updatePlayerProjCollisions();
		updateEnemyProjCollisions();
		updateShipCollisions();
		updateUpgradesCollisions();
		window.clear();
		drawPLAYING();
		drawELSE();
		window.display();
	}
}