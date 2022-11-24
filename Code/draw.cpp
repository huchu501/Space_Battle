#include "Engine.h"

void Engine::draw()
{
	if (state == State::PLAYING)
	{
		window.clear();
		window.setView(mainView);
		window.draw(background.getBackground(bgClock));

		//draw players here

		window.display();

	}
}