#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
using namespace std;

class Enemy1 : public Enemy
{
public:
	virtual void spawn(float startX, float startY) override;
	virtual void hit() override;
	virtual void update(float elapsedTime, Vector2f playerLocation) override;
	
};
