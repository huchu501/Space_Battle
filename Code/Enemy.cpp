#include "Enemy.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void Enemy::spawn(float startX, float startY)
{

    //switch (type)
    //{
   // case 0:
        // Bloater
        m_Sprite = Sprite(TextureHolder::GetTexture("graphics/enemy-small.png"));
        m_Explosion = Sprite(TextureHolder::GetTexture("graphics/explosion1.png"));
        m_Speed = ENEMY_SPEED;
        m_Health = ENEMY_HEALTH;
        //break;
        /*
        case 1:
            // Chaser
            m_Sprite = Sprite(TextureHolder::GetTexture(
                "graphics/chaser.png"));
            m_Speed = CHASER_SPEED;
            m_Health = CHASER_HEALTH;
            break;
        case 2:
            // Crawler
            m_Sprite = Sprite(TextureHolder::GetTexture(
                "graphics/crawler.png"));
            m_Speed = CRAWLER_SPEED;
            m_Health = CRAWLER_HEALTH;
            break;
        }
        */
   // }
    // Modify the speed to make the Enemy unique

    // Initialize its location
    m_Position.x = startX;
    m_Position.y = startY;
    // Set its origin to its center
    m_Sprite.setOrigin(50, 50);
    // Set its position
    m_Sprite.setPosition(m_Position);
}

bool Enemy::hit()
{
    m_Health--;
    if (m_Health < 0)
    {
        // dead
        m_Alive = false;
        //m_Sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));
        return true;
    }
    // injured but not dead yet
    return false;
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

void Enemy::setSprite()
{
    m_Sprite = m_Explosion;
}