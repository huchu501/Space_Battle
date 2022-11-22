#include "Player.h"
#include <cmath>

Player::Player()
{
	// default constructor to reset ship info
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}

Player::Player(int player)
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
	m_Player = player;

	if (m_Player == 1)
	{
		// Associate a texture with the player1
		m_Texture1.loadFromFile("graphics/ship1.png");
		m_Sprite.setTexture(m_Texture1);
	}
	else if (m_Player == 2)
	{
		// do the same for player2
		m_Texture2.loadFromFile("graphics/ship2.png");
		m_Sprite.setTexture(m_Texture2);
	}
	// Set the origin of the sprite to the center
	// m_Sprite.setOrigin(25, 25);
}

void Player::spawn(IntRect space, Vector2f resolution, int tileSize)
{
	if (m_Player == 1)
	{
		// Place the player in the middle left of the space
		m_Position.x = space.width / 4;
		m_Position.y = 1000;
	}
	else if (m_Player == 2)
	{
		// Place the player in the middle right of the space
		m_Position.x = space.width / 2 + space.width / 4;
		m_Position.y = 1000;
	}

	// Copy the details of the space to the player's m_Space
	m_Space.left = space.left;
	m_Space.width = space.width;
	m_Space.top = space.top;
	m_Space.height = space.height;

	// Remember how big the tiles are in this space
	m_TileSize = tileSize;

	// Strore the resolution for future use
	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;
}

Time Player::getLastHitTime()
{
	return m_LastHit;
}

bool Player::hit(Time timeHit)
{
	if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)// 2 tenths of second
	{
		m_LastHit = timeHit;
		m_Health -= 10;
		return true;
	}
	else
	{
		return false;
	}

}

FloatRect Player::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f Player::getCenter()
{
	return m_Position;
}

Sprite Player::getSprite()
{
	return m_Sprite;
}

int Player::getHealth()
{
	return m_Health;
}

void Player::moveLeft()
{
	m_LeftPressed = true;
}

void Player::moveRight()
{
	m_RightPressed = true;
}

void Player::moveUp()
{
	m_UpPressed = true;
}

void Player::moveDown()
{
	m_DownPressed = true;
}

void Player::stopLeft()
{
	m_LeftPressed = false;
}

void Player::stopRight()
{
	m_RightPressed = false;
}

void Player::stopUp()
{
	m_UpPressed = false;
}

void Player::stopDown()
{
	m_DownPressed = false;
}

void Player::update(float elapsedTime)
{

	if (m_UpPressed)
	{
		m_Position.y -= m_Speed * elapsedTime;
	}

	if (m_DownPressed)
	{
		m_Position.y += m_Speed * elapsedTime;
	}

	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}

	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}

	m_Sprite.setPosition(m_Position);


	// Keep the player in the space
	if (m_Position.x > m_Space.width - m_TileSize)
	{
		m_Position.x = m_Space.width - m_TileSize;
	}

	if (m_Position.x < m_Space.left + m_TileSize)
	{
		m_Position.x = m_Space.left + m_TileSize;
	}

	if (m_Position.y > m_Space.height - m_TileSize)
	{
		m_Position.y = m_Space.height - m_TileSize;
	}

	if (m_Position.y < m_Space.top + m_TileSize)
	{
		m_Position.y = m_Space.top + m_TileSize;
	}
	
}

void Player::upgradeSpeed()
{
	// 20% speed upgrade
	m_Speed += (START_SPEED * .2);
}

void Player::upgradeHealth()
{
	// 20% max health upgrade
	m_MaxHealth += (START_HEALTH * .2);

}

void Player::increaseHealthLevel(int amount)
{
	m_Health += amount;

	// But not beyond the maximum
	if (m_Health > m_MaxHealth)
	{
		m_Health = m_MaxHealth;
	}
}

void Player::resetPlayerStats()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}
