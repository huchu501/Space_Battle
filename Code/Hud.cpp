#include "Hud.h"


Hud::Hud()
{
	font.loadFromFile("Fonts/Retro Gaming.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(55);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(20, 0);

	stringstream ssScore;
	ssScore << "Score:" << 55;
	scoreText.setString(ssScore.str());
}

Text Hud::getScoreText()
{
	return scoreText;
}
