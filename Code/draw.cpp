#include "Engine.h"

void Engine::draw()
{
	if (state == State::PLAYING)
	{
		window.clear();
		window.setView(mainView);
		window.draw(background.getBackground(bgClock));
		window.draw(hud.getScoreText());
		// draw 2 players on background
		window.draw(player1.getSprite());
		window.draw(player2.getSprite());

		//draw projectiles for both players:
		for (int i = 0; i < player1.getProjectileSize(); i++) 
		{
			window.draw(player1.getProjectileSprite(i));
		}
		for (int i = 0; i < player2.getProjectileSize(); i++)
		{
			window.draw(player2.getProjectileSprite(i));
		}

		//Draw enemies
		for (int i = 0; i < numOfEnemy; i++)
		{
			window.draw(enemyContainer[i]->getSprite());
		}
		window.display();
	}
}