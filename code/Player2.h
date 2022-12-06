#pragma once
#include "Player.h"

class Player2 : public Player
{
public:
	// player 2 constructor
	Player2();

	// override spawn function for player1
	virtual void spawn(IntRect space, Vector2f resolution, int tileSize) override;

	// override input function for player1
	virtual void handleInput();
};
