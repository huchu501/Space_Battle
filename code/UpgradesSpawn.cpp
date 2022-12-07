#include "Upgrades.h"

// all the spawn related functions for spawn is here

void Upgrades::spawnPos()
{

	int x1 = rand() % 1801 + 100;
	int y1 = rand() % 701 + 300;
	spawned = true;
	upgradeSprite.setPosition(x1, y1);

}

void Upgrades::spawnTime(float elaspedTime)
{
	// update spawn time
	if (spawned)
	{
		secSinceSpawn += elaspedTime;
	}
	else
	{
		secSinceDespawn += elaspedTime;
	}

	// hide upgrades?
	if (secSinceSpawn > secToLive && spawned)
	{ // remove upgrades
		spawned = false;
		secSinceDespawn = 0;
	}
	if (secSinceDespawn > secToWait && !spawned)
	{ // show upgrades
		spawned = true;
		secSinceSpawn = 0;
	}

	float timePlus30 = elaspedTime + 30;
}

bool Upgrades::isSpawned()
{
	return spawned;
}