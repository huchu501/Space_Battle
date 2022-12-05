#include "EnemyB1.h"


EnemyB1::EnemyB1()
{
    type = rand() % 2;
}

void EnemyB1::spawn(float startX, float startY)
{
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/enemy-small.png"));
    m_Explosion = Sprite(TextureHolder::GetTexture("graphics/explosion1.png"));
    m_Speed = ENEMY_SPEED;
    m_Health = 5;

    float modifier = (rand() % MAX_VARRIANCE) + OFFSET;
    // Express this as a fraction of 1
    modifier /= 100; // Now equals between .7 and 1
    m_Speed *= modifier;
    // Modify the speed to make the Enemy unique
    // Initialize its location
    m_Position.x = startX;
    m_Position.y = startY;
    // Set its origin to its center
    m_Sprite.setOrigin(20, 20);
    m_Explosion.setOrigin(14, 14);
    // Set its position
    m_Sprite.setPosition(m_Position);
    m_Dead = false;
}

void EnemyB1::hit()
{
    m_Health--;
    m_Sprite.setColor(Color(255, 255, 255));
    if (m_Health < 0)
    {
        // dead, can update score here maybe
        sendShadowRealm();
    }
    // injured but not dead yet
}

void EnemyB1::update(float elapsedTime, Vector2f playerLocation, Clock imgclock)
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

    float angle = (atan2(playerY - m_Position.y, playerX - m_Position.x) * 180) / 3.141;
    m_Sprite.setRotation(angle);

}

Sprite EnemyB1::getProjSprite(int i)
{
    return emptySprite;
}
void EnemyB1::stopProjectile()
{

}
void EnemyB1::updateProjectile(float elapsedTime, Vector2f playerLocation, Clock imgclock)
{

}
FloatRect EnemyB1::getProjectilePosition(int i)
{
    return getPosition();
}

