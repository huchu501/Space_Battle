#pragma once
#include "Player.h"

class Player1 : public Player
{
public:
	// player 1 constructor
	Player1::Player1();
	
	// override spawn function for player1
	virtual void spawn(IntRect space, Vector2f resolution, int tileSize) override;

	// override input function for player1
	virtual void handleInput();
};