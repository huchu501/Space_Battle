#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Space Battle", Style::Default);

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

	/*------------------------------------------------*/
	/*                 MAIN GAME LOOP                 */
	/*------------------------------------------------*/
	while (window.isOpen())
	{
        /*------------------------------------------------*/
        /*               Handle User Input                */
        /*------------------------------------------------*/
        Event event;

        /*------------------------------------------------*/
        /*                 Update Objects                 */
        /*------------------------------------------------*/


        /*------------------------------------------------*/
        /*                     Draw                       */
        /*------------------------------------------------*/
        window.clear();

        window.display();
    } // END main game loop
}