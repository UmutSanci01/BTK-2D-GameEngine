#include <iostream>
#include <SDL2/SDL.h>


int main(int argc, char** argv)
{
	Game game;
	if (!game.Init("BTK Engine", 800, 600))
	{
		return -1;
	}

	Game.Run();

	return 0;
}