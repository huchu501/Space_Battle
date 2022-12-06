#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
using namespace sf;
class CreateBackground
{
private:
	bool change = true;
	Sprite background;
	Texture textureBackground;
	Sprite menuBackground;
	Texture textureMenu;
	Uint8 t, r, g, b;
	Time updateImgTime, totalTime;
	float i;
	bool toggleT = true;
	int setRGB;
	int bgImage = 0;
	vector<Sprite> vSprites;

public:
	CreateBackground();
	Sprite getBackground(Clock, Time);
	Sprite getMenuBackground();
	void resetBackground();
	void changeImage(Time gameTime);
};
