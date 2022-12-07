#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
using namespace sf;

class Projectile
{
protected:
	const float START_SPEED = 400;

	//RectangleShape m_ProjectileShape;

	// position of the projectile on screen
	Vector2f m_Position;

	// set the sprite
	Sprite m_Sprite;

	// add a texture to the default projectile
	Texture m_DefaultTexture;

	// add a texture to the upgraded projectile
	Texture m_UpgradedTexture;

	// Speed of projectile in pixels per second
	float m_Speed;

	// is the projectile currently in air
	bool m_InFlight;

	// the horizontal and vertical fraction of 1 pixel the projectile travels
	// these values will be derived from m_Speed
	float m_ProjectileDistanceX;
	float m_ProjectileDistanceY;

	// where the projectile is headed to
	float m_XTarget;
	float m_YTarget;

	// boundaries for the projectiles
	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;


public:
	// default constructor
	Projectile(String tex);

	// stop the projectile
	void stop();

	// returns the value of m_InFlight
	bool isInFlight();

	// launch a new projectile
	void shoot(float startX, float startY, float xTarget, float yTarget);

	// tell the calling code where the position of projectile is at
	FloatRect getPosition();  //floatrect

	// return the copy of the sprite
	Sprite getSprite();

	// update the projectiles each frame
	void update(float elapsedTime);

	void setPosition(float x, float y);
	void setOrigin(float x, float y);
};