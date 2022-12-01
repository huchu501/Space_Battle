#include "Enemy1.h"

void Enemy1::spawn(float startX, float startY)
{
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/enemy-small.png"));
    m_Explosion = Sprite(TextureHolder::GetTexture("graphics/explosion1.png"));
    m_Speed = ENEMY_SPEED;
    m_Health = ENEMY_HEALTH;

    float modifier = (rand() % MAX_VARRIANCE) + OFFSET;
    // Express this as a fraction of 1
    modifier /= 100; // Now equals between .7 and 1
    m_Speed *= modifier;
    // Modify the speed to make the Enemy unique
    // Initialize its location
    m_Position.x = startX;
    m_Position.y = startY;
    // Set its origin to its center
    m_Sprite.setOrigin(14, 14);
    // Set its position
    m_Sprite.setPosition(m_Position);
}

bool Enemy1::hit()
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

void Enemy1::update(float elapsedTime, Vector2f playerLocation)
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

    //check if sprite has contacted player
    if (abs(playerX - m_Position.x) <= 1 && abs(playerY - m_Position.y) <= 1)
    {
        m_Sprite = m_Explosion;
    }

    // Move the sprite
    m_Sprite.setPosition(m_Position);

    float angle = (atan2(playerY - m_Position.y,
        playerX - m_Position.x)
        * 180) / 3.141;
    m_Sprite.setRotation(angle);
}

