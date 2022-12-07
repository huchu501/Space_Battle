#include "CreateBackground.h"

CreateBackground::CreateBackground()
{
	background = Sprite(TextureHolder::GetTexture("Graphics/SpaceBackground.png"));
	background.setColor(Color::Transparent);
	t = 255;
	r = 255;
	g = 255;
	b = 255;
	i = 0;
	setRGB = 1;
	vSprites.push_back(Sprite(TextureHolder::GetTexture("Graphics/SpaceBackground.png")));
	vSprites.push_back(Sprite(TextureHolder::GetTexture("Graphics/SpaceBackground2.png")));
	vSprites.push_back(Sprite(TextureHolder::GetTexture("Graphics/SpaceBackground3.png")));
	vSprites.push_back(Sprite(TextureHolder::GetTexture("Graphics/SpaceBackground4.png")));
}

// background for menu screen
Sprite CreateBackground::getMenuBackground()
{
	textureMenu = TextureHolder::GetTexture("Graphics/SpaceBackground.png");
	menuBackground.setTexture(textureMenu);
	menuBackground.setPosition(0, 0);
	return menuBackground;
}

void CreateBackground::resetBackground() 
{ 
	i = 0; 
	bgImage = 0;
	background = vSprites[0];
	setRGB = 0;
	t = 255;
}

void CreateBackground::changeImage(Time gameTime)
{
	if (gameTime.asSeconds() > totalTime.asSeconds() + 5)
	{
		background = vSprites[bgImage];
		totalTime = gameTime;
		bgImage++;
		if (bgImage > 3)
			bgImage = 0;
	}
}
