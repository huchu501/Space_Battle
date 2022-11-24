#include "Engine.h"

void Engine::draw()
{
	if (state == State::PLAYING)
	{
		window.clear();
		window.setView(mainView);
		window.draw(background.getBackground(bgClock));

		// draw 2 players on background
		window.draw(player1.getSprite());
		window.draw(player2.getSprite());

		window.display();
	}
}