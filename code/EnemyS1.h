#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class EnemyS1 : public Enemy
{
public:
	virtual void spawn(float startX, float startY) override;
	virtual void hit() override;
	virtual void update(float elapsedTime, Vector2f playerLocation, Clock imgclock) override;
	virtual Sprite getProjSprite(int i) override;
	virtual void stopProjectile() override;
	virtual void updateProjectile(float elapsedTime, Vector2f playerLocation, Clock imgclock) override;
	virtual FloatRect getProjectilePosition(int i) override;

	EnemyS1();

private:
	int clip = 0;
	Time updateProjTime;
	vector<Projectile*> s1;

};
