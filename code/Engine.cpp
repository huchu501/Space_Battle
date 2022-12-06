#include "Engine.h"
#include "Player.h"
Engine::Engine()
{
	state = State::MENU; //Set game to menu view

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	window.create(VideoMode(resolution.x, resolution.y), "Space Battle", Style::Fullscreen);
	mainView.reset(sf::FloatRect(0, 0, 1920, 1080));
	hudView.reset(sf::FloatRect(0, 0, 1920, 1080));
	// upgrades
	healthUp.setType(1);
	healthUp.setBoundary(space);
	speedUp.setType(2);
	speedUp.setBoundary(space);
	projUp.setType(3);
	projUp.setBoundary(space);


	if (!mTheme.openFromFile("bgMusic.wav"))
	{
	}
	mTheme.setVolume(60);
	mTheme.play();
	mTheme.setLoop(true);
	//create container of enemies, will spawn later:
	for (int i = 0; i < numOfEnemy; i++)
	{
		enemyType = rand() % 2;
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
		updateProjCollisions();
		updateShipCollisions();
		window.clear();
		drawPLAYING();
		drawELSE();
		window.display();
	}
}

