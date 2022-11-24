#include "Engine.h"
#include "Player.h"
Engine::Engine()
{
	state = State::UPGRADE;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	window.create(VideoMode(resolution.x, resolution.y), "Space Battle", Style::Fullscreen);

	mainView.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));

}
void Engine::run()
{
	//restart clocks before main game loop:
	clock.restart();
	bgClock.restart();

	while (window.isOpen())
	{

		//place some timer stuff, then feed dt.asSeconds() to update
		input();
		update();
		draw();
	}


}

