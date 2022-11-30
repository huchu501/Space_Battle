#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "sstream"
using namespace std;
using namespace sf;

class Hud
{

private:

	Font font;
	Text scoreText;
	



public:
	Hud();
	Text getScoreText();


};