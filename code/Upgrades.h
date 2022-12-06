#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Upgrades
{
private:
	const int WAIT_TIME = 1;
	const int LIVE_TIME = 5;
	const int HEALTH_UP_WORTH = 1;

	Sprite upgradeSprite;
	int upgradeType; // 1 = Health, 2 = Speed, 3 = Projectile speed
	int value;
	// spawing & despawning
	float secSinceSpawn = 0;
	float secSinceDespawn = 0;
	float secToLive = 0;
	float secToWait = 0;

	IntRect upgradeSpace;
	bool spawned;
public:
	Upgrades();
	// set what type of upgrade the object is
	void setType(int type);
	// set boundary space of the upgrades
	void setBoundary(IntRect space);
	// spawn position of the upgrade pickups
	void spawnPos();
	// spawn duration of the upgrade pickups
	void spawnTime(float elaspedTime);
	int pickup();
	FloatRect getPosition();
	Sprite getSprite();
	bool isSpawned();
};