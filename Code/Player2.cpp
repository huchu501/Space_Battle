#include "Player2.h"
#include "TextureHolder.h"

Player2::Player2()
{
	// associate texture with sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("Graphics/ship2.png"));

	// default constructor to reset ship info
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}

// Virtual function overriding Player.h pure virtual function spawn()
void Player2::spawn(IntRect space, Vector2f resolution)
{
	m_Position.x = 3 * (space.width / 4);
	m_Position.y = 1000;

	// Copy the details of the space to the player's m_Space
	m_Space.left = space.left;
	m_Space.width = space.width;
	m_Space.top = space.top;
	m_Space.height = space.height;

	// Store the resolution for future use
	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;
}

// Virtual function overriding Player.h pure virtual function handleInput()
bool Player2::handleInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		moveUp();
	}
	else
	{
		stopUp();
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		moveLeft();
	}
	else
	{
		stopLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		moveDown();
	}
	else
	{
		stopDown();
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		moveRight();
	}
	else
	{
		stopRight();
	}
}