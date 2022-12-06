#include "EnemyS1.h"

Sprite EnemyS1::getProjSprite(int i) { return s1[i]->getSprite(); }

FloatRect EnemyS1::getProjectilePosition(int i) { return s1[i]->getPosition(); }

void EnemyS1::stopProjectile()
{
    for (int i = 0; i < s1.size(); i++)
    {
        s1[i]->stop();
        s1[i]->setPosition(5000, 5000);
    }
}
void EnemyS1::updateProjectile(float elapsedTime, Vector2f playerLocation, Clock imgclock)
{
    if (updateProjTime.asMilliseconds() > timeToShoot)   //Shoots projectiles on timeToShoot timer
    {
        s1[clip]->setOrigin(15, 15);
        s1[clip]->shoot(m_Position.x, m_Position.y, playerLocation.x, playerLocation.y);
        timeToShoot = updateProjTime.asMilliseconds() + 3000; //lower number for faster rate
        clip++;
        if (clip > s1.size() - 1)
            clip = 0;
    }

    for (int i = 0; i < s1.size(); i++)  //Updates projectiles in flight and sends others to shadowrealm
    {
        if (s1[i]->isInFlight())
            s1[i]->update(elapsedTime);
        else
        {
            s1[i]->stop();
            s1[i]->setPosition(5000, 5000);
        }

    }

    if (gameRestart)  //If gameover, stop all projectiles
    {
        for (int i = 0; i < s1.size(); i++)
        {
            s1[i]->stop();
        }
        gameRestart = false;
    }
}
