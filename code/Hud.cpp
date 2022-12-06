#include "Hud.h"

Hud::Hud()
{
	// load font
	font.loadFromFile("Fonts/Retro Gaming.ttf");
	// MENU
	menuText.setFont(font);
	menuText.setCharacterSize(150);
	menuText.setFillColor(Color::White);
	menuText.setPosition(230, 330);
	menuText.setString("SPACE BATTLE");
	menuSubtext.setFont(font);
	menuSubtext.setCharacterSize(50);
	menuSubtext.setFillColor(Color::White);
	menuSubtext.setPosition(450, 700);
	menuSubtext.setString("-Press 1 to start the game-");
	// PAUSED
	pausedText.setFont(font);
	pausedText.setCharacterSize(100);
	pausedText.setFillColor(Color::White);
	pausedText.setPosition(110, 310);
	pausedText.setString("          Game paused!\n\nPress Enter to continue");
	// GAME_OVER
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(100);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(170, 430);
	gameOverText.setString("Press Enter to replay");
	// score
	scoreText.setFont(font);
	scoreText.setCharacterSize(100);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(500, 500);	
}
// getters
Text Hud::getMenuText()
{
	return menuText;
}
Text Hud::getMenuSubtext()
{
	return menuSubtext;
}
Text Hud::getScoreText()
{
	return scoreText;
}
Text Hud::getPausedText()
{
	return pausedText;
}
Text Hud::getGameOverText()
{
	return gameOverText;
}
// score updater
void Hud::setScoreText(String text)
{
	scoreText.setString(text);
}
