#include "Engine.h"

void Engine::input()
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// press escape to quit the game
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			// Pause a game while playing
			if (Keyboard::isKeyPressed(Keyboard::Enter) && state == State::PLAYING)
			{
				state = State::PAUSED;
			}

			// Restart while paused
			else if (Keyboard::isKeyPressed(Keyboard::Enter) && state == State::PAUSED)
			{
				state = State::PLAYING;
				// Reset the clock so there isn't a frame jump
				clock.restart();
			}
		}
	} // END while event polling
}