#include "Engine.h"
void Engine::updateShipCollisions()
{
	if (state == State::PLAYING)
	{
		//Checks collision of player1 Ship and enemy ships
		for (int j = 0; j < enemyContainer.size(); j++)
		{
			checkCol = col.checkCollision(player1.getPosition(), enemyContainer[j]->getPosition());
			if (checkCol)
			{
				enemyContainer[j]->sendShadowRealm(); //reduces enemy health till death
				//Make player lose health here
				player1.decHealth();
			}
		}
		//Checks collision of player2 Ship and enemy ships
		for (int j = 0; j < enemyContainer.size(); j++)
		{
			checkCol = col.checkCollision(player2.getPosition(), enemyContainer[j]->getPosition());
			if (checkCol)
			{
				enemyContainer[j]->sendShadowRealm(); //reduces enemy health till death
				//Make player lose health here
				player1.decHealth();
			}
		}
	}
}