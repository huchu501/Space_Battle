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
				bgClock.restart();
				background.resetBackground();
				spawnTime = 0;
				player1.resetTimeToShoot();
				player2.resetTimeToShoot();
			}

			//Start the game with num1
			if (Keyboard::isKeyPressed(Keyboard::Num1) && state == State::MENU)
			{
				state = State::PLAYING;
				//RESTART EVERYTHING FOR NEW GAME:
				bgClock.restart();
				spawnTime = 0;
				background.resetBackground();
				for (int i = 0; i < enemyContainer.size(); i++)
				{
					enemyContainer[i]->resetEnemy();
				}
			}

			// Reset the game and start over again
			if (Keyboard::isKeyPressed(Keyboard::Enter) && state == State::GAME_OVER)
			{
				state = State::MENU;
			}
		}
		player1.handleInput();
		player2.handleInput();
	} // END while event polling
}