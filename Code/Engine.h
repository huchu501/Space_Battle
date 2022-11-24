#pragma once
#include <SFML/Graphics.hpp>
#include "CreateBackground.h"
#include "Player.h"
#include "TextureHolder.h"
using namespace sf;

class Engine
{
private:
	enum class State { PAUSED, UPGRADE, GAME_OVER, PLAYING };
	State state;
	Vector2f resolution;
	RenderWindow window;
	View mainView;
	// Here is our clock for timing everything
	Clock clock, bgClock;

	// How long has the PLAYING state been active
	Time gameTimeTotal;

	// Create player1 and player2 objects 
	Player player1(int one);
	Player player2(int two);

	// The boundaries of the space
	IntRect space;
	//Create Background
	CreateBackground background;

	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine(); //constructor initializes any variables needed
	void run(); //Calls all private functions
};
