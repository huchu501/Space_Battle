#include "Engine.h"

void Engine::drawPLAYING()
{
	if (state == State::PLAYING)
	{
		//window.clear();
		// DRAW ON MAIN VIEW
		window.setView(mainView);
		window.draw(background.getBackground(bgClock, gameTimeTotal));
		// draw 2 players on background
		window.draw(player1.getSprite());
		window.draw(player2.getSprite());
		// draw upgrades if spawned
		if (healthUp.isSpawned()) { window.draw(healthUp.getSprite()); }
		if (speedUp.isSpawned()) { window.draw(speedUp.getSprite()); }
		if (projUp.isSpawned()) { window.draw(projUp.getSprite()); }

		//draw projectiles for both players:
		for (int i = 0; i < player1.getProjectileSize(); i++) 
		{
			window.draw(player1.getProjectileSprite(i));
		}
		for (int i = 0; i < player2.getProjectileSize(); i++)
		{
			window.draw(player2.getProjectileSprite(i));
		}

		//Draw enemies and the re projectiles
		for (int i = 0; i < numOfEnemy; i++)
		{
			window.draw(enemyContainer[i]->getSprite());
			//If shooter, draw projectiles:
			if (enemyContainer[i]->getType() > 1)
			{
				for (int j = 0; j < 20; j++)
				{
					window.draw(enemyContainer[i]->getProjSprite(j));
				}
			}
		}
		// hud elements
		window.draw(hud.getScoreText()); //UNCOMMENT THIS TO SHOW SCORE
		window.draw(healthBar.getHealthBar());

	}
}