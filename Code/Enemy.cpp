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
//void Enemy::stopProjectile(int i)
//{
//
//}
