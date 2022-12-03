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
	Text menuText;
	Text menuSubtext;
	Text pausedText;
	Text scoreText;
	Text gameOverText;
public:
	Hud();
	Text getMenuText();
	Text getMenuSubtext();
	Text getScoreText();
	Text getPausedText();
	Text getGameOverText();
	void setScoreText(String text);

};