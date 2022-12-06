#include "Upgrades.h"
Upgrades::Upgrades(int type)
{
	upgradeType = type;
	if (upgradeType = 1)
	{
		upgradeSprite = Sprite(TextureHolder::GetTexture("Graphics/upgrade/H_UP"));
	}
	else if (upgradeType = 2)
	{
		upgradeSprite = Sprite(TextureHolder::GetTexture("Graphics/upgrade/S_UP"));
	}
	else if (upgradeType = 3)
	{
		upgradeSprite = Sprite(TextureHolder::GetTexture("Graphics/upgrade/P_UP"));
	}
	upgradeSprite.setOrigin(15, 14);
	secToLive = LIVE_TIME;
	secToWait = WAIT_TIME;
}

void Upgrades::setBoundary(IntRect space)
{
	upgradeSpace.left = space.left + 50;
	upgradeSpace.width = space.width - 50;
	upgradeSpace.top = space.top + 50;
	upgradeSpace.height = space.height - 50;

	spawnPos();
}

void Upgrades::spawnPos()
{
	srand((int)time(0) / upgradeType);
	int x = (rand() % upgradeSpace.width);
	srand((int)time(0) * upgradeType);
	int y = (rand() % upgradeSpace.height);

	secSinceSpawn = 0.0;
	spawned = true;
	upgradeSprite.setPosition(x, y);
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
}

int Upgrades::pickup()
{
	spawned = false;
	secSinceDespawn = 0;
	return upgradeType;
}

FloatRect Upgrades::getPosition()
{
	return upgradeSprite.getGlobalBounds();
}

Sprite Upgrades::getSprite()
{
	return upgradeSprite;
}

bool Upgrades::isSpawned()
{
	return spawned;
}

