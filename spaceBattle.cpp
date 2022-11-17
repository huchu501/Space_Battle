#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int main() {

    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Space Battle", Style::Default);

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