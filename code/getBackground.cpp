#include "CreateBackground.h"

Sprite CreateBackground::getBackground(Clock imgClock, Time gameTime)
{
	updateImgTime = imgClock.getElapsedTime();
	if (updateImgTime.asMilliseconds() >= i)
	{
		if (t >= 245)
			toggleT = true;
		if (t <= 25)
		{
			toggleT = false;
			if (setRGB == 0)
			{
				r = 255;
				g = 255;
				b = 255;
				setRGB = 1;
				changeImage(gameTime);
			}
			else if (setRGB == 1)
			{
				r = 0;
				g = 255;
				b = 255;
				setRGB = 2;
			}
			else if (setRGB == 2)
			{
				r = 150;
				g = 0;
				b = 255;
				setRGB = 0;
			}

		}

		if (toggleT)
			t -= 5; //default was 5
		else
			t += 5;

		i += 50;
	}

	background.setColor(Color(r, g, b, t));
	return background;
}