#include "Engine.h"
#include "Player.h"
Engine::Engine()
{
	state = State::MENU;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	window.create(VideoMode(resolution.x, resolution.y), "Space Battle", Style::Fullscreen);

	mainView.setSize(resolution);
	mainView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));

	hudView.setSize(resolution);
	hudView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));

	//create container of enemies, will spawn later:
	for (int i = 0; i < numOfEnemy; i++)
	{
		enemyType = rand() % 2;
		enemySpawnPoint = rand() % 1890;
		switch (enemyType)
		{
		case 0:
			enemyContainer.push_back(new EnemyB1);
			break;
		case 1:
			enemyContainer.push_back(new EnemyS1);
			break;

		}
	}
}
/*------------------------------------------------*/
/*                 MAIN GAME LOOP                 */
/*------------------------------------------------*/
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
		update(dtAsSeconds);
		updateEnemies(dtAsSeconds);
		updateCollisions();
		draw();
	}
}

