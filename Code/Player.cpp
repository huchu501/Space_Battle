#include "Player.h"
#include <cmath>
bool Player::hit(Time timeHit)
{
	if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)// 2 tenths of second
	{
		m_LastHit = timeHit;
		m_Health -= 1;
		return true;
	}
	else
	{
		return false;
	}

}

Time Player::getLastHitTime()
{
	return m_LastHit;
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
Sprite Player::getProjectileSprite(int i)
{
	return p1[i]->getSprite();
}

int Player::getHealth()
{
	return m_Health;
}

void Player::decHealth()
{
	m_Health--;
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

void Player::shootPressed()
{
	m_SpacePressed = true;
}

void Player::stopShoot()
{
	m_SpacePressed = false;
}

void Player::update(float elapsedTime, Clock imgclock)
{
	updateProjTime = imgclock.getElapsedTime();

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
	if (m_Position.x > m_Space.width)
	{
		m_Position.x = m_Space.width;
	}

	if (m_Position.x < m_Space.left)
	{
		m_Position.x = m_Space.left;
	}

	if (m_Position.y > m_Space.height)
	{
		m_Position.y = m_Space.height;
	}

	if (m_Position.y < m_Space.top)
	{
		m_Position.y = m_Space.top;
	}


	if (m_SpacePressed && updateProjTime.asMilliseconds() > timeToShoot)
	{
			timeToShoot = updateProjTime.asMilliseconds() + clipSpeed;
			p1[clip]->shoot(m_Position.x, m_Position.y, m_Position.x, 0);
			clip++;
				if (clip > 99) //99
					clip = 0;
	}

	for (int i = 0; i < p1.size(); i++)
	{
		if (p1[i]->isInFlight())
		{
			p1[i]->update(elapsedTime);
		}
		else
			stopProjectile(i);
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

int Player::getProjectileSize()
{
	return p1.size();
}

FloatRect Player::getProjectilePosition(int i)
{
	return p1[i]->getPosition();
}

void Player::stopProjectile(int i)
{
	p1[i]->stop();
	p1[i]->setPosition(2000, 3000);
}
