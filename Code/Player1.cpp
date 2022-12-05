#include "Player1.h"

Player1::Player1()
{
	// associate texture with sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("Graphics/ship1.png"));
	m_Sprite.setOrigin(16, 24);
	// default constructor to reset ship info
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}

// Virtual function overriding Player.h pure virtual function spawn()
void Player1::spawn(IntRect space, Vector2f resolution, int tileSize)
{
	m_Position.x = space.width / 4;
	m_Position.y = 1000;

	// Copy the details of the space to the player's m_Space
	m_Space.left = space.left;
	m_Space.width = space.width;
	m_Space.top = space.top;
	m_Space.height = space.height;

	// Remember how big the tiles are in this space
	m_TileSize = tileSize;

	// Store the resolution for future use
	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;
}

// Virtual function overriding Player.h pure virtual function handleInput()
void Player1::handleInput()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		moveUp();
	}
	else
	{
		stopUp();
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		moveLeft();
	}
	else
	{
		stopLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		moveDown();
	}
	else
	{
		stopDown();
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		moveRight();
	}
	else
	{
		stopRight();
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		shootPressed();
	}
	else
	{
		stopShoot();
	}
}

