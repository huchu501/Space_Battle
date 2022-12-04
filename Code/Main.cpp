#include "Engine.h"
#include <stdlib.h>
#include <time.h>
int main()
{
	// create Engine object
	srand(time(NULL));
	Engine engine;
	
	// run the engine main game loop
	engine.run();

	// stop the program when the engine is stopped
	return 0;
}