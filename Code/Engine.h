#pragma once
#include <SFML/Graphics.hpp>
#include "CreateBackground.h"
#include "Player1.h"
#include "Player2.h"
#include "TextureHolder.h"
#include "Enemy1.h"
using namespace sf;

class Engine
{
private:
	enum class State { PAUSED, UPGRADE, GAME_OVER, PLAYING };
	State state;
	Vector2f resolution;
	RenderWindow window;

	TextureHolder th;

	// create a mainView
	View mainView;

	// Here is our clock for timing everything
	Clock clock, bgClock;

	// How long has the PLAYING state been active
	Time dt, gameTimeTotal;

	// Create player1 and player2 objects 
	Player1 player1;
	Player2 player2;

	// The boundaries of the space
	IntRect space;

	//Create Background
	CreateBackground background;

	vector<Enemy*> enemy1;   //remember to delete the pointers
	int spawnTime = 0;
	int enemySpawnPoint = 0;
	int numOfEnemy = 0;
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine(); //constructor initializes any variables needed

	void run(); //Calls all private functions
};
