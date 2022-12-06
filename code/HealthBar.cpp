#include "HealthBar.h"
#include "TextureHolder.h"

HealthBar::HealthBar()
{
	size.x = 7.5;
	size.y = 4.5;
	heartCount = 10;
}

void HealthBar::updateHealthBar(int playerHeartNum)
{
	heartCount = playerHeartNum;
	if (heartCount == 10)
	{
		healthBar = Sprite(TextureHolder::GetTexture("Graphics/10Health.png"));
		healthBar.setScale(size.x, size.y);
		healthBar.setPosition(0, 0);
	}
	else if (heartCount == 9)
	{
		healthBar = Sprite(TextureHolder::GetTexture("Graphics/9Health.png"));
		healthBar.setScale(size.x, size.y);
		healthBar.setPosition(0, 0);
	}
	else if (heartCount == 8)
	{
		healthBar = Sprite(TextureHolder::GetTexture("Graphics/8Health.png"));
		healthBar.setScale(size.x, size.y);
		healthBar.setPosition(0, 0);
	}
	else if (heartCount == 7)
	{
		healthBar = Sprite(TextureHolder::GetTexture("Graphics/7Health.png"));
		healthBar.setScale(size.x, size.y);
		healthBar.setPosition(0, 0);
	}
	else if (heartCount == 6)
	{
		healthBar = Sprite(TextureHolder::GetTexture("Graphics/6Health.png"));
		healthBar.setScale(size.x, size.y);
		healthBar.setPosition(0, 0);
	}
	else if (heartCount == 5)
	{
		healthBar = Sprite(TextureHolder::GetTexture("Graphics/5Health.png"));
		healthBar.setScale(size.x, size.y);
		healthBar.setPosition(0, 0);
	}
	else if (heartCount == 4)
	{
		healthBar = Sprite(TextureHolder::GetTexture("Graphics/4Health.png"));
		healthBar.setScale(size.x, size.y);
		healthBar.setPosition(0, 0);
	}
	else if (heartCount == 3)
	{
		healthBar = Sprite(TextureHolder::GetTexture("Graphics/3Health.png"));
		healthBar.setScale(size.x, size.y);
		healthBar.setPosition(0, 0);
	}
	else if (heartCount == 2)
	{
		healthBar = Sprite(TextureHolder::GetTexture("Graphics/2Health.png"));
		healthBar.setScale(size.x, size.y);
		healthBar.setPosition(0, 0);
	}
	else if (heartCount == 1)
	{
		healthBar = Sprite(TextureHolder::GetTexture("Graphics/1Health.png"));
		healthBar.setScale(size.x, size.y);
		healthBar.setPosition(0, 0);
	}
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
