#include "Enemy.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void Enemy::spawn(float startX, float startY)
{
    //Make this virtual
}

bool Enemy::hit()
{
    //Make this virtual
    return true;
}

bool Enemy::isAlive()
{
    return m_Alive;
}
FloatRect Enemy::getPosition()
{
    return m_Sprite.getGlobalBounds();
}
Sprite Enemy::getSprite()
{
    return m_Sprite;
}

void Enemy::update(float elapsedTime,
    Vector2f playerLocation)
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

Vector2f Enemy::getVector2f()
{
    return m_Position;
}

