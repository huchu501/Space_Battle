#include "EnemyS1.h"

EnemyS1::EnemyS1()
{
    type = rand() % ((3 - 2) + 1) + 2;
    for (int i = 0; i < 20; i++)  //create 100 projectiles
    {
        s1.push_back(new Projectile{ "Graphics/enemy_projectile.png" });
        s1.back()->setOrigin(10, 24.5);
    }
}
void EnemyS1::spawn(float startX, float startY)
{
    m_Sprite = Sprite(TextureHolder::GetTexture("Graphics/enemy-medium.png"));
    m_Speed = ENEMY_SPEED;
    m_Health = 5;

    // Initialize its location
    m_Position.x = startX;
    m_Position.y = startY;
    // Set its origin to its center
    m_Sprite.setOrigin(28, 14);
    // Set its position
    m_Sprite.setPosition(m_Position);
    //set to not dead
    m_Dead = false;
}
void EnemyS1::hit()
{
    m_Health--;
    if (m_Health <= 0)
    {
        // dead, send to coordinates 5000,5000
        sendShadowRealm();

    }
    // injured but not dead yet
}
void EnemyS1::update(float elapsedTime, Vector2f playerLocation, Clock imgclock)
{
    updateProjTime = imgclock.getElapsedTime();
    float playerX = playerLocation.x;
    float playerY = playerLocation.y;
    
    if (m_Position.y < 250) { m_Position.y = m_Position.y + m_Speed * elapsedTime; }  //Shooters cant go past 250 pixels
    m_Sprite.setPosition(m_Position);
}
