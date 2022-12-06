#include "Engine.h"

void Engine::drawELSE()
{
	if (state == State::MENU)
	{
		window.setView(hudView);
		window.draw(background.getMenuBackground());
		window.draw(hud.getMenuText());
		window.draw(hud.getMenuSubtext());
	}
	if (state == State::PAUSED)
	{
		window.setView(hudView);
		window.draw(hud.getPausedText());
	}
	if (state == State::GAME_OVER)
	{
		window.setView(hudView);
		window.draw(background.getMenuBackground());
		window.draw(hud.getGameOverText());
	}
}