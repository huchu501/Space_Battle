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
	speedUp.setType(2);
	projUp.setType(3);


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