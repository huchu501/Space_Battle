#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class HealthBar
{
private:
	RectangleShape healthBar;
	Vector2f size;
public:
	HealthBar();
	RectangleShape getHealthBar();
};