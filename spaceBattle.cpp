#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
	// The game will always be in one of four states
	enum class State {PAUSED, LEVELING_UP,GAME_OVER, PLAYING};

	// Start with the GAME_OVER state
	State state = State::GAME_OVER;

	// Get the screen resolution and create an SFML window
	Vector2f resolution; 
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y),"Space Battle", Style::Fullscreen);

	// Create a an SFML View for the main action
	View mainView(sf::FloatRect(0, 0,resolution.x, resolution.y));

	// Here is our clock for timing everything
	Clock clock;

	// How long has the PLAYING state been active
	Time gameTimeTotal;

	// The boundaries of the arena
	IntRect arena;

	// The main game loop
	while (window.isOpen())
	{

	}


	return 0;
}