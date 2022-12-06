#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Upgrades
{
private:
	const int WAIT_TIME = 30;
	const int LIVE_TIME = 5;

	Sprite upgradeSprite;
	int upgradeType; // 1 = Health, 2 = Speed, 3 = Projectile speed
	// spawing & despawning
	float secSinceSpawn;
	float secSinceDespawn;
	float secToLive;
	float secToWait;

	IntRect upgradeSpace;
	bool spawned;
	

public:
	Upgrades(int type);
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