#include "Hud.h"

Hud::Hud()
{
	// load font
	font.loadFromFile("Fonts/Retro Gaming.ttf");
	// MENU
	menuText.setFont(font);
	menuText.setCharacterSize(150);
	menuText.setFillColor(Color::White);
	menuText.setPosition(280, 330); // 230
	menuText.setString("SPACE BATTLE");
	menuSubtext.setFont(font);
	menuSubtext.setCharacterSize(50);
	menuSubtext.setFillColor(Color::White);
	menuSubtext.setPosition(500, 700); // 450
	menuSubtext.setString("-Press 1 to start the game-");
	// PAUSED
	pausedText.setFont(font);
	pausedText.setCharacterSize(100);
	pausedText.setFillColor(Color::White);
	pausedText.setPosition(160, 310); // 110
	pausedText.setString("          Game paused!\n\nPress Enter to continue");
	// GAME_OVER
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(100);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(230, 430); // 170
	gameOverText.setString("Press Enter to replay");
	// score
	scoreText.setFont(font);
	scoreText.setCharacterSize(80);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(1420, -20);	
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
