#include "EnemyB1.h"

EnemyB1::EnemyB1()
{
    type = rand() % 2;
}
void EnemyB1::spawn(float startX, float startY)
{
    m_Sprite = Sprite(TextureHolder::GetTexture("Graphics/enemy-small.png"));
    m_Speed = ENEMY_SPEED;
    m_Health = 5;

    float modifier = (rand() % MAX_VARRIANCE) + OFFSET; //Speed has slight variance
    modifier /= 100; 
    m_Speed *= modifier;

    m_Position.x = startX; // Initialize its location
    m_Position.y = startY;

    m_Sprite.setOrigin(20, 20); //Set its origin to its center
    m_Sprite.setPosition(m_Position); // Set its position
    m_Dead = false; //Not dead
}
void EnemyB1::hit()
{
    m_Health--;
    if (m_Health <= 0)
    {
        sendShadowRealm(); // dead, send to coordinates 5000,5000
    }
    // injured but not dead yet
}
void EnemyB1::update(float elapsedTime, Vector2f playerLocation, Clock imgclock)
{
    float playerX = playerLocation.x;
    float playerY = playerLocation.y;
    // Update the Enemy position variables
    if (playerX > m_Position.x) { m_Position.x = m_Position.x + m_Speed * elapsedTime; }
    if (playerY > m_Position.y) { m_Position.y = m_Position.y + m_Speed * elapsedTime; }
    if (playerX < m_Position.x) { m_Position.x = m_Position.x - m_Speed * elapsedTime; }
    if (playerY < m_Position.y) { m_Position.y = m_Position.y - m_Speed * elapsedTime; }
    m_Sprite.setPosition(m_Position);

    float angle = (atan2(playerY - m_Position.y, playerX - m_Position.x) * 180) / 3.141;
    m_Sprite.setRotation(angle);
}
//DO NOTHING FOR B1
Sprite EnemyB1::getProjSprite(int i) { return emptySprite; }
void EnemyB1::stopProjectile() {}
void EnemyB1::updateProjectile(float elapsedTime, Vector2f playerLocation, Clock imgclock) {}
FloatRect EnemyB1::getProjectilePosition(int i) { return getPosition(); }