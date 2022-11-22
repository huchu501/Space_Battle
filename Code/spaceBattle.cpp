#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "spaceBattle.h"
#include "CreateBackground.h"
using namespace sf;

int main()
{

	//Testing push
	// The game will always be in one of four states
	enum class State { PAUSED, UPGRADE, GAME_OVER, PLAYING };

	// Start with the GAME_OVER state
	State state = State::UPGRADE;

	// Get the screen resolution and create an SFML window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y), "Space Battle", Style::Fullscreen);

	// Create a an SFML View for the main action
	View mainView(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));

	// Here is our clock for timing everything
	Clock clock, bgClock;

	// How long has the PLAYING state been active
	Time gameTimeTotal;

	// Create player1 and player2 objects 
	Player player1(1);
	Player player2(2);

	// The boundaries of the space
	IntRect space;
	//Create Background
	CreateBackground background;

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
				if (Keyboard::isKeyPressed(Keyboard::Enter) && state == State::PLAYING)
				{
					state = State::PAUSED;
				}

				// Restart while paused
				else if (Keyboard::isKeyPressed(Keyboard::Enter) && state == State::PAUSED)
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

		if (state == State::PLAYING)
		{
			// Move player 1 spaceship by WASD
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player1.moveUp();
			}
			else
			{
				player1.stopUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player1.moveDown();
			}
			else
			{
				player1.stopDown();
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player1.moveLeft();
			}
			else
			{
				player1.stopLeft();
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player1.moveRight();
			}
			else
			{
				player1.stopRight();
			}

			// Move player 2 spaceship by arrow keys
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				player2.moveUp();
			}
			else
			{
				player2.stopUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				player2.moveDown();
			}
			else
			{
				player2.stopDown();
			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				player2.moveLeft();
			}
			else
			{
				player2.stopLeft();
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				player2.moveRight();
			}
			else
			{
				player2.stopRight();
			}
		} // END moving player1 with WASD and player2 spaceship with arrow keys

		if (state == State::UPGRADE)
		{
			// handle player upgrading
			if (Keyboard::isKeyPressed(Keyboard::Num1))
			{
				state = State::PLAYING;
			}

			if (state == State::PLAYING)
			{
				// background
				space.height = 1080;  //Changed from 1000
				space.width = 1920;   //Changed from 1000
				space.left = 0;
				space.top = 0;
				//int tileSize = createBackground(background, space); //SET TO 50 AND REMOVE THE CREATEBACKGROUND.CPP, CREATE NEW ALGORITHM FOR CHANGING IMAGE
				int tileSize = 50;

				// spawn the player at bottom
				player1.spawn(space, resolution, tileSize);
				player2.spawn(space, resolution, tileSize);
				// reset the clock 
				clock.restart();
			}
		} // END upgrade state


        /*------------------------------------------------*/
        /*                 Update Objects                 */
        /*------------------------------------------------*/
		if (state == State::PLAYING)
		{
			// update the delta time
			Time dt = clock.restart();

			// update the total game time
			gameTimeTotal += dt;

			// make a decimal fraction of 1 from the delta time
			float drAsSeconds = dt.asSeconds();

			// update player1
			player1.update(drAsSeconds);
			player1.update(drAsSeconds);

			// update player2
			player2.update(drAsSeconds);
			player2.update(drAsSeconds);

			// make a note of the players new position
			Vector2f player1Position(player1.getCenter());
			Vector2f player2Position(player2.getCenter());

			// set the center to the center of the background
			//REMOVE THIS TO KEEP BACKGROUND CENTERED(NO BLACK BARS)************
			//mainView.setCenter(player1.getCenter());
		}


        /*------------------------------------------------*/
        /*                     Draw                       */
        /*------------------------------------------------*/
		if (state == State::PLAYING)
		{
			// clear everything before the new program starts
			window.clear();

			// set the mainView of the game
			window.setView(mainView);

			// draw the background
			window.draw(background.getBackground(bgClock));
			// draw the player
			window.draw(player1.getSprite());
			window.draw(player2.getSprite());
		}
		if (state == State::UPGRADE)
		{

		}
		if (state == State::PAUSED)
		{

		}
		if (state == State::GAME_OVER)
		{

		}
        window.display();
    } // END main game loop
}