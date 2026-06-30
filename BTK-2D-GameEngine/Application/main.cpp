#include <iostream>
#include <SDL2/SDL.h>
#include "../Engine/Core/Game.h"


int main(int argc, char** argv)
{
	Game game;
	if (!game.Init("BTK Engine", 800, 600))
	{
		return -1;
	}

	game.Run();

	return 0;
}