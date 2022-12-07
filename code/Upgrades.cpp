#include "Upgrades.h"

Upgrades::Upgrades() 
{
	secToLive = LIVE_TIME;
	secToWait = WAIT_TIME;
}

void Upgrades::setType(int type)
{
	upgradeType = type;
	if (upgradeType == 1)
	{
		upgradeSprite = Sprite(TextureHolder::GetTexture("Graphics/H_UP.png"));
		value = HEALTH_UP_WORTH;
		upgradeSprite.setOrigin(30, 26);
	}
	else if (upgradeType == 2)
	{
		upgradeSprite = Sprite(TextureHolder::GetTexture("Graphics/S_UP.png"));
		upgradeSprite.setOrigin(30.5, 27.5);
	}
	else if (upgradeType == 3)
	{
		upgradeSprite = Sprite(TextureHolder::GetTexture("Graphics/P_UP.png"));
		upgradeSprite.setOrigin(17, 17);
	}
}

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
void Upgrades::sendShadowRealm()
{
	upgradeSprite.setPosition(4000, 6000);
}

