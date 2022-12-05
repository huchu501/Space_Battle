#include "EnemyS1.h"


EnemyS1::EnemyS1()
{
    type = rand() % ((3 - 2) + 1) + 2;
    for (int i = 0; i < 100; i++)  //create 100 projectiles
    {
        s1.push_back(new Projectile{ "Graphics/enemy_projectile.png" });
        s1.back()->setOrigin(10, 24.5);
    }
}

void EnemyS1::spawn(float startX, float startY)
{
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/enemy-medium.png"));
    m_Explosion = Sprite(TextureHolder::GetTexture("graphics/explosion1.png"));
    m_Speed = ENEMY_SPEED;
    m_Health = 5;

    // Modify the speed to make the Enemy unique
    // Initialize its location
    m_Position.x = startX;
    m_Position.y = startY;
    // Set its origin to its center
    m_Sprite.setOrigin(28, 14);
    m_Explosion.setOrigin(14, 14);
    // Set its position
    m_Sprite.setPosition(m_Position);
    m_Dead = false;


}

void EnemyS1::hit()
{
    FloatRect shape;
    m_Health--;
    m_Sprite.setColor(Color(255, 255, 255));
    if (m_Health < 0)
    {
        // dead, can update score here maybe
        sendShadowRealm();

    }
    // injured but not dead yet
}

void EnemyS1::update(float elapsedTime, Vector2f playerLocation, Clock imgclock)
{
    updateProjTime = imgclock.getElapsedTime();
    float playerX = playerLocation.x;
    float playerY = playerLocation.y;
    // Update the Enemy position variables
    if (m_Position.y < 250)
    {
        m_Position.y = m_Position.y +
            m_Speed * elapsedTime;
    }
   
    // Move the sprite
    m_Sprite.setPosition(m_Position);

    //Update projectiles

}

Sprite EnemyS1::getProjSprite(int i)
{
    return s1[i]->getSprite();
}
void EnemyS1::stopProjectile()
{
    for (int i = 0; i < 100; i++)
    {
        s1[i]->stop();
        s1[i]->setPosition(5000, 5000);
    }
}
void EnemyS1::updateProjectile(float elapsedTime, Vector2f playerLocation, Clock imgclock)
{
    if (updateProjTime.asMilliseconds() > timeToShoot)
    {
        s1[clip]->setOrigin(15, 15);
        s1[clip]->shoot(m_Position.x, m_Position.y, playerLocation.x, playerLocation.y);
        timeToShoot = updateProjTime.asMilliseconds() + 3000; //lower number for faster rate
        clip++;
        if (clip > 99)
            clip = 0;
    }

    for (int i = 0; i < 100; i++)
    {
        if (s1[i]->isInFlight())
            s1[i]->update(elapsedTime);
        else
        {
            s1[i]->stop();
            s1[i]->setPosition(5000, 5000);
        }

    }
    if (gameRestart)
    {
        for (int i = 0; i < 100; i++)
        {
            s1[i]->stop();
        }
        gameRestart = false;
    }

}
FloatRect EnemyS1::getProjectilePosition(int i)
{
    return s1[i]->getPosition();
}