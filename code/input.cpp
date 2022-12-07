#include "Engine.h"

void Engine::input()
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape)) { window.close(); }  // press escape to quit the game

			if (Keyboard::isKeyPressed(Keyboard::Enter) && state == State::PLAYING) { state = State::PAUSED; } // Pause a game while playing

			else if (Keyboard::isKeyPressed(Keyboard::Enter) && state == State::PAUSED) // Restart Timers when paused ends 
			{
				state = State::PLAYING;
				spawnTime = 3;
				clock.restart();
				bgClock.restart();
				background.resetBackground();
				player1.resetTimeToShoot();
				player2.resetTimeToShoot();
			}
		
			if (Keyboard::isKeyPressed(Keyboard::Num1) && state == State::MENU) //Start the game with num1 from MENU, restart timers
			{
				state = State::PLAYING;
				bgClock.restart();
				spawnTime = 0;
				background.resetBackground();
				healthUp.sendShadowRealm();
				speedUp.sendShadowRealm();
				projUp.sendShadowRealm();
				for (int i = 0; i < enemyContainer.size(); i++)
				{
					enemyContainer[i]->resetEnemy();
				}
			}
			// Reset the game and start over again
			if (Keyboard::isKeyPressed(Keyboard::Enter) && state == State::GAME_OVER) // Display GAMEOVER and return to MENU
			{
				score = 0;
				state = State::MENU;
			}
		}
		//PLAYER INPUTS
		player1.handleInput();
		player2.handleInput();
	} 
}
