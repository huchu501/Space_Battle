#pragma once
#include <SFML/Graphics.hpp>
#include "CreateBackground.h"
#include "Player1.h"
#include "Player2.h"
#include "TextureHolder.h"
#include "EnemyB1.h"
#include "EnemyS1.h"
#include "Hud.h"
#include "Projectile.h"
#include "Collision.h"
#include "HealthBar.h"
#include "Upgrades.h"
#include <SFML/Audio.hpp>

using namespace sf;

class Engine
{
private:
	enum class State { PAUSED, GAME_OVER, PLAYING, MENU };
	State state;
	Vector2f resolution;
	RenderWindow window;

	TextureHolder th;

	// create a mainView and hudView
	View mainView, hudView;

	// Here is our clock for timing everything
	Clock clock, bgClock, upClock;

	// How long has the PLAYING state been active
	Time dt, gameTimeTotal, enemyTime, upTime;

	// Create player1 and player2 objects 
	Player1 player1;
	Player2 player2;

	// The boundaries of the space
	IntRect space;

	//Create Background
	CreateBackground background;

	// time as seconds
	float dtAsSeconds;

	// HUD variables
	Hud hud;
	HealthBar healthBar;
	int score = 0;

	Collision col;

	vector<Enemy*> enemyContainer;   //remember to delete the pointers
	bool checkCol, checkColP1, checkColP2;

	float spawnTime = 0;
	float rateOfSpawn = 5; //Higher the number, slower the enemies spawn
	int enemySpawnPoint = 0; //Random num for spawn point on x axis
	int numOfEnemy = 50;  //Create 50 enemies on stack
	int enemyIterator = 0;
	int enemyType; //random num for Bomber or shooter


	float upTotal = 0; //30
	Music mTheme;

	// upgrade variables
	Upgrades healthUp;
	Upgrades speedUp;
	Upgrades projUp;

	void input();
	void updatePlayers(float dtAsSeconds);
	void updateEnemies(float dtAsSeconds);
	void updatePlayerProjCollisions();
	void updateEnemyProjCollisions();
	void updateShipCollisions();
	void updateUpgradesCollisions();
	void drawPLAYING();
	void drawELSE();

public:
	Engine(); //constructor initializes any variables needed

	void run(); //Calls all private functions
};
