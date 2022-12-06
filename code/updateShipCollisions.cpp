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
		// Checks collision of player1 ship and health upgrade
		checkCol = col.checkCollision(player1.getPosition(), healthUp.getPosition());
		if (checkCol && healthUp.pickup()) 
		{ 
			player1.increaseHealthLevel(healthUp.pickup());
		}
		// Checks collision of player2 ship and health upgrade
		checkCol = col.checkCollision(player2.getPosition(), healthUp.getPosition());
		if (checkCol && healthUp.pickup())
		{
			player1.increaseHealthLevel(healthUp.pickup());
		}

		// Checks collision of player1 ship and speed upgrade
		checkCol = col.checkCollision(player1.getPosition(), speedUp.getPosition());
		if (checkCol && speedUp.pickup())
		{
			player1.upgradeSpeed();
			player1.upgradeTime(upClock);
		}
		// Checks collision of player2 ship and speed upgrade
		checkCol = col.checkCollision(player2.getPosition(), speedUp.getPosition());
		if (checkCol && speedUp.pickup())
		{
			player2.upgradeSpeed();
			player2.upgradeTime(upClock);
		}

		// Checks collision of player1 ship and projectile speed upgrade
		checkCol = col.checkCollision(player1.getPosition(), projUp.getPosition());
		if (checkCol && projUp.pickup())
		{
			player1.upgradeProjSpeed();
			player1.upgradeTime(upClock);
		}
		// Checks collision of player2 ship and projectile speed upgrade
		checkCol = col.checkCollision(player2.getPosition(), projUp.getPosition());
		if (checkCol && projUp.pickup())
		{
			player2.upgradeProjSpeed();
			player2.upgradeTime(upClock);
		}
	}
}