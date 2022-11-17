#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int main()
{
	// The game will always be in one of four states
	enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };

	// Start with the GAME_OVER state
	State state = State::GAME_OVER;

	// Get the screen resolution and create an SFML window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y), "Space Battle", Style::Fullscreen);

	// Create a an SFML View for the main action
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	// Here is our clock for timing everything
	Clock clock;

	// How long has the PLAYING state been active
	Time gameTimeTotal;

	// The boundaries of the arena
	IntRect arena;

	//Load Background Texture(Testing)
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/Space Background.png");

	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	/*------------------------------------------------*/
	/*                 MAIN GAME LOOP                 */
	/*------------------------------------------------*/
	while (window.isOpen())
	{
        /*------------------------------------------------*/
        /*               Handle User Input                */
        /*------------------------------------------------*/
        Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				// Pause a game while playing
				if (event.key.code == Keyboard::Return &&
					state == State::PLAYING)
				{
					state = State::PAUSED;
				}

				// Restart while paused
				else if (event.key.code == Keyboard::Return &&
					state == State::PAUSED)
				{
					state = State::PLAYING;
					// Reset the clock so there isn't a frame jump
					clock.restart();
				}
			}
		} // END while event polling

		// Press escape to quit the game
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

        /*------------------------------------------------*/
        /*                 Update Objects                 */
        /*------------------------------------------------*/


        /*------------------------------------------------*/
        /*                     Draw                       */
        /*------------------------------------------------*/
        window.clear();

		window.draw(spriteBackground);

        window.display();
    } // END main game loop
}