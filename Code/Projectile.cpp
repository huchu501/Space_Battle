#include "Projectile.h"

Projectile::Projectile()
{
	m_Sprite = Sprite(TextureHolder::GetTexture("Graphics/projectile1.png"));
	m_Sprite.setOrigin(10, 25);
	m_Speed = START_SPEED;
}
void Projectile::stop()
{
	m_InFlight = false;
}

bool Projectile::isInFlight()
{
	return m_InFlight;
}

FloatRect Projectile::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Projectile::getSprite()
{
	return m_Sprite;
}

void Projectile::shoot(float startX, float startY, float xTarget, float yTarget)
{
	m_InFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;

	float gradient = (startX - xTarget) / (startY - yTarget);

	if (gradient < 0)
	{
		gradient *= -1;
	}

	float ratioXY = m_Speed / (1 + gradient);

	m_ProjectileDistanceY = ratioXY;
	m_ProjectileDistanceX = ratioXY * gradient;

	if (xTarget < startX)
	{
		m_ProjectileDistanceX *= -1;
	}

	if (yTarget < startY)
	{
		m_ProjectileDistanceY *= -1;
	}

	m_Sprite.setPosition(m_Position);
}

void Projectile::update(float elapsedTime)
{
	// Update the bullet position variables
	m_Position.x += m_ProjectileDistanceX * elapsedTime;
	m_Position.y += m_ProjectileDistanceY * elapsedTime;
	// Move the bullet
	m_Sprite.setPosition(m_Position);
	// Has the bullet gone out of range?
	if (m_Position.y < 10)
	{
		stop();
	}
}

void Projectile::setPosition(float x, float y)
{
	m_Sprite.setPosition(x, y);
}