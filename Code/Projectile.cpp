#include "Projectile.h"
Projectile::Projectile(String tex)
{
	m_Sprite = Sprite((TextureHolder::GetTexture(tex)));
	m_Sprite.setOrigin(15, 15);
	m_Speed = START_SPEED;
}

bool Projectile::isInFlight() { return m_InFlight; }

FloatRect Projectile::getPosition() { return m_Sprite.getGlobalBounds(); }

Sprite Projectile::getSprite() { return m_Sprite; }

void Projectile::setPosition(float x, float y) { m_Sprite.setPosition(x, y); }

void Projectile::setOrigin(float x, float y) { m_Sprite.setOrigin(x, y); }

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
	if (m_Position.y < 10|| m_Position.y > 2000)
	{
		stop();
	}
}
void Projectile::stop()
{
	m_InFlight = false;
	m_Sprite.setPosition(5000, 5000);
}
