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
	Time updateImgTime;
	float i;
	bool toggleT = true;
	int setRGB;

public:
	CreateBackground();
	Sprite getBackground(Clock);
	Sprite getMenuBackground();
};