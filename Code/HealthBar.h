#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class HealthBar
{
private:
	Sprite healthBar;
	Texture heart;
	// size of healthBar
	Vector2f size;
	// keeps track of current heart count
	int heartCount;
public:
	// constructs heart texture of 6 hearts
	HealthBar();
	// updates the health bar depending on remaining number of hearts
	void updateHealthBar(int hearts);
	// returns healthBar sprite
	Sprite getHealthBar();
	// returns the number of hearts left
	int getHeartCount();
	// resets the health bar to 6 hearts
	void resetHealthBar();
};