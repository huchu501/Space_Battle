#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
using namespace sf;

class Enemy
{
protected:
    // How fast is each Enemy type?
    const float ENEMY_SPEED = 100;
    //const float CHASER_SPEED = 80;
    //const float CRAWLER_SPEED = 20;

    // How tough is each Enemy type
    const float ENEMY_HEALTH = 5;
    //const float CHASER_HEALTH = 1;
    //const float CRAWLER_HEALTH = 3;
    // Make each zombie vary its speed slightly
    const int MAX_VARRIANCE = 30;
    const int OFFSET = 101 - MAX_VARRIANCE;
    // Where is this Enemy?
    Vector2f m_Position;
    // A sprite for the Enemy
    Sprite m_Sprite, m_Explosion;
    // How fast can this one run/crawl?
    float m_Speed;
    // How much health has it got?
    float m_Health;
    // Is it still alive?
    bool m_Alive;

    // Public prototypes go here    
public:

    // Handle when a bullet hits a Enemy
    virtual bool hit() = 0;
    // Find out if the Enemy is alive
    bool isAlive();
    // Spawn a new Enemy
    virtual void spawn(float startX, float startY) = 0;
    // Return a rectangle that is the position in the world
    FloatRect getPosition();
    // Get a copy of the sprite to draw
    Sprite getSprite();
    // Update the Enemy each frame
    virtual void update(float elapsedTime, Vector2f playerLocation) = 0;

    Vector2f getVector2f();

    void setSprite();
};
