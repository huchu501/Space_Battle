#include "HealthBar.h"
#include "TextureHolder.h"

HealthBar::HealthBar()
{
	size.x = 7.5;
	size.y = 4.5;
	heartCount = 10;
}

Sprite HealthBar::getHealthBar()
{
	return healthBar;
}

int HealthBar::getHeartCount()
{
	return heartCount;
}

void HealthBar::resetHealthBar()
{
	heartCount = 10;
}
