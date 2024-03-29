#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include "TextureHolder.h"
using namespace sf;

class Player
{
// protected, so that the subclasses can use all these variables
protected:
	const float START_SPEED = 200;
	const float START_HEALTH = 10;

	// position of the player on screen
	Vector2f m_Position;

	// set the sprite
	Sprite m_Sprite;

	// add a texture to player1
	Texture m_Texture1;

	// And a texture to player2
	Texture m_Texture2;

	// What is the screen resolution
	Vector2f m_Resolution;

	// What size is the space
	IntRect m_Space;

	// How big is each tile of the space
	int m_TileSize;

	// Which directions is the player currently moving in
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;
	bool m_SpacePressed;
	// health from 0 to 10
	int m_Health;
	// What is the maximum health the player can have
	int m_MaxHealth;

	// When was the player last hit
	Time m_LastHit, updateProjTime;

	// Speed in pixels per second
	float m_Speed;

	int clipSpeed = 300;
	vector<Projectile*> p1;
	int MaxClip = 0;
	int clip = 0;
	float timeToShoot = 0;

	float upTime;

	Time upTime1, upTime2;

public:
	// this is the abstract base class, so it won't have a contructor.

	// pure virtual functions, now this class cannot be instantiated
	// spawns the player1 on the bottom left or right of the screen
	virtual void spawn(IntRect space, Vector2f resolution, int tileSize) = 0;

	// input function
	virtual void handleInput() = 0;

	// Handle the player getting hit by a Enemy
	bool hit(Time timeHit);

	// How long ago was the player last hit
	Time getLastHitTime();

	// Where is the player
	FloatRect getPosition();

	// Where is the center of the player
	Vector2f getCenter();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// How much health has the player currently got?
	int getHealth();

	// Decrement player health when got hit by enemy ship
	void decHealth();

	// The next four functions move the player
	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();

	// Stop the player moving in a specific direction
	void stopLeft();

	void stopRight();

	void stopUp();

	void stopDown();

	//Get player to shoot projectile
	void shootPressed();

	void stopShoot();

	// We will call this function once every frame
	void update(float elapsedTime, Clock imgClock);

	// Give player a speed boost
	void upgradeSpeed();

	// Give the player some health
	void upgradeProjSpeed();

	// Increase the maximum amount of health the player can have
	void increaseHealthLevel(int amount);

	void resetPlayerStats();

	//Returns number of projectiles
	int getProjectileSize();

	FloatRect getProjectilePosition(int i);

	Sprite getProjectileSprite(int i);

	void stopProjectile(int i);

	void sendShadowRealm();

	void resetTimeToShoot();

	void upgradeTime(Clock upClock);

	void updateUpgrade(Clock upClock);
};