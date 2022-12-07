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

void Upgrades::sendShadowRealm()
{
	upgradeSprite.setPosition(4000, 6000);
}