#include "HealthBar.h"

HealthBar::HealthBar()
{
	size.x = 15;
	size.y = 9;
	heart.loadFromFile("Graphics/health/heart_6.png");
	healthBar.setTexture(heart);
	healthBar.setPosition(0,0);
	healthBar.setScale(size.x, size.y);
	heartCount = 6;
}

void HealthBar::updateHealthBar(int playerHeartNum)
{
	heartCount = playerHeartNum;
	if (heartCount == 6)
	{
		heart.loadFromFile("Graphics/health/heart_6.png");
		healthBar.setTexture(heart);
	}
	else if (heartCount == 5)
	{
		heart.loadFromFile("Graphics/health/heart_5.png");
		healthBar.setTexture(heart);
	}
	else if (heartCount == 4)
	{
		heart.loadFromFile("Graphics/health/heart_4.png");
		healthBar.setTexture(heart);
	}
	else if (heartCount == 3)
	{
		heart.loadFromFile("Graphics/health/heart_3.png");
		healthBar.setTexture(heart);
	}
	else if (heartCount == 2)
	{
		heart.loadFromFile("Graphics/health/heart_2.png");
		healthBar.setTexture(heart);
	}
	else if (heartCount == 1)
	{
		heart.loadFromFile("Graphics/health/heart_1.png");
		healthBar.setTexture(heart);
	}
	else if (heartCount == 0)
	{
		heart.loadFromFile("Graphics/health/heart_0.png");
		healthBar.setTexture(heart);
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
	heartCount = 6;
}
