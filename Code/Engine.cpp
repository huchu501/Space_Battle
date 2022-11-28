#include "Engine.h"
#include "Player.h"
Engine::Engine()
{
	state = State::UPGRADE;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	window.create(VideoMode(resolution.x, resolution.y), "Space Battle", Style::Fullscreen);

	mainView.setSize(resolution);
	mainView.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
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
		dt = clock.restart();
		// keep on updating the total game time
		gameTimeTotal += dt;
		// convert float to seconds
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}

