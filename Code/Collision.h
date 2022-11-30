#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Collision
{
private:
	bool hitDetected = false;


public:
	bool checkCollision(Vector2f projectile, Vector2f enemy);

};