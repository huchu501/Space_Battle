#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Projectile
{
private:
	const float START_SPEED = 200;

	// position of the projectile on screen
	Vector2f m_Position;

	// set the sprite
	Sprite m_Sprite;

	// add a texture to the projectile
	Texture m_Texture;

	// Speed of projectile in pixels per second
	float m_Speed;

public:
	// default constructor
	Projectile();


};
