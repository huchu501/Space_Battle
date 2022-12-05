#include "Enemy.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void Enemy::spawn(float startX, float startY)
{
    //Make this virtual
}

void Enemy::hit()
{
    //Make this virtual
}


FloatRect Enemy::getPosition()
{
    return m_Sprite.getGlobalBounds();
}
Sprite Enemy::getSprite()
{
    return m_Sprite;
}

void Enemy::update(float elapsedTime, Vector2f playerLocation, Clock imgClock)
{
    float playerX = playerLocation.x;
    float playerY = playerLocation.y;
    // Update the Enemy position variables
    if (playerX > m_Position.x)
    {
        m_Position.x = m_Position.x +
            m_Speed * elapsedTime;
    }
    if (playerY > m_Position.y)
    {
        m_Position.y = m_Position.y +
            m_Speed * elapsedTime;
    }

    if (playerX < m_Position.x)
    {
        m_Position.x = m_Position.x -
            m_Speed * elapsedTime;
    }
    if (playerY < m_Position.y)
    {
        m_Position.y = m_Position.y -
            m_Speed * elapsedTime;
    }
    // Move the sprite
    m_Sprite.setPosition(m_Position);
}

void Enemy::sendShadowRealm()
{
    m_Dead = true;
    m_Sprite.setPosition(2000,2000);
}

bool Enemy::getm_Dead()
{
    return m_Dead;
}
Sprite Enemy::getProjSprite(int i)
{
    return emptySprite;
}
int Enemy::getType()
{
    return type;
}

