#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Projectile.h"
using namespace sf;

class Enemy
{
protected:
    // How fast is each Enemy type?
    const float ENEMY_SPEED = 150;

    // How tough is each Enemy type
    const float ENEMY_HEALTH = 500;
    // Make each Enemy vary its speed slightly
    const int MAX_VARRIANCE = 30;
    const int OFFSET = 101 - MAX_VARRIANCE;
    // Where is this Enemy?
    Vector2f m_Position;
    // A sprite for the Enemy
    Sprite m_Sprite, emptySprite;
    // How fast can this one run/crawl?
    float m_Speed;
    // How much health has it got?
    float m_Health;
    // Is it still alive?
    bool m_Dead = false;

    bool m_Shooter = false;

    bool gameRestart = false;

    int type;

    float timeToShoot = 0;

    // Public prototypes go here    
public:

    // Handle when a bullet hits a Enemy
    virtual void hit() = 0;

    // Spawn a new Enemy
    virtual void spawn(float startX, float startY) = 0;
    // Return a rectangle that is the position in the world
    FloatRect getPosition();
    // Get a copy of the sprite to draw
    Sprite getSprite();
    // Update the Enemy each frame
    virtual void update(float elapsedTime, Vector2f playerLocation, Clock imgclock) = 0;

    bool getm_Dead();

    void sendShadowRealm();

    //Projectile functions:
    virtual Sprite getProjSprite(int i) = 0;
    virtual void stopProjectile() = 0;
    virtual void updateProjectile(float elapsedTime, Vector2f playerLocation, Clock imgclock) = 0;
    virtual FloatRect getProjectilePosition(int i) = 0;

    int getType();
    void resetEnemy();
};