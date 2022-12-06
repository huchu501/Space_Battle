#include "Engine.h"

void Engine::draw()
{
	window.clear();
	if (state == State::MENU)
	{
		window.setView(hudView);
		window.draw(background.getMenuBackground());
		window.draw(hud.getMenuText());
		window.draw(hud.getMenuSubtext());
	}
	if (state == State::PLAYING)
	{
		// DRAW ON MAIN VIEW
		window.setView(mainView);
		window.draw(background.getBackground(bgClock));
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

		//Draw enemies and there projectiles
		for (int i = 0; i < numOfEnemy; i++)
		{
			window.draw(enemyContainer[i]->getSprite());
			//If shooter, draw projectiles:
			if (enemyContainer[i]->getType() > 1)
			{
				for (int j = 0; j < 100; j++)
				{
					window.draw(enemyContainer[i]->getProjSprite(j));
				}
			}
		}

		// DRAW ON HUD VIEW
		window.setView(hudView);
		// hud elements
		window.draw(hud.getScoreText());
		window.draw(healthBar.getHealthBar());

	}
	if (state == State::PAUSED)
	{
		window.setView(hudView);
		window.draw(hud.getPausedText());
	}
	if (state == State::GAME_OVER)
	{
		window.setView(hudView);
		window.draw(background.getMenuBackground());
		window.draw(hud.getGameOverText());
	}
	window.display();

}