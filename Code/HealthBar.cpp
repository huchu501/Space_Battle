#include "HealthBar.h"

HealthBar::HealthBar()
{
	size.x = 1750;
	size.y = 25;
	healthBar.setFillColor(Color::Red);
	healthBar.setSize(size);
	healthBar.setPosition(10, 0);
}

RectangleShape HealthBar::getHealthBar()
{
	return healthBar;
}