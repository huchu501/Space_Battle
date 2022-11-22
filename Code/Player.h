#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;

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

	// How much health has the player got?
	int m_Health;
	// What is the maximum health the player can have
	int m_MaxHealth;

	// When was the player last hit
	Time m_LastHit;

	// Speed in pixels per second
	float m_Speed;

	// player number 1 or 2
	int m_Player;


	// All our public functions will come next
public:
	// default constructor
	Player();

	// parameterized constructor: sets the player1 or 2 sprite texture
	Player(int player);

	// spawn the player1 on the left bottom of the screen
	void spawn(IntRect space, Vector2f resolution, int tileSize);

	// Handle the player getting hit by a zombie
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

	// We will call this function once every frame
	void update(float elapsedTime);

	// Give player a speed boost
	void upgradeSpeed();

	// Give the player some health
	void upgradeHealth();

	// Increase the maximum amount of health the player can have
	void increaseHealthLevel(int amount);

	void resetPlayerStats();
};



