#include "Enemy.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

FloatRect Enemy::getPosition() { return m_Sprite.getGlobalBounds(); }

Sprite Enemy::getSprite() { return m_Sprite; }

bool Enemy::getm_Dead() { return m_Dead; }

Sprite Enemy::getProjSprite(int i) { return emptySprite; }

int Enemy::getType() { return type; }

void Enemy::sendShadowRealm()
{
    m_Dead = true;
    m_Sprite.setPosition(5000,5000);
}

void Enemy::resetEnemy()
{
    timeToShoot = 0;
    sendShadowRealm();
    stopProjectile();
    gameRestart = true;
}


