#include <iostream>
#include <SDL2/SDL.h>


int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL Yuklenemedi. Hata! ->" << SDL_GetError << std::endl;
	}

	SDL_Window* window = SDL_CreateWindow(
		"BTK_Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_SHOWN
	);

	// olay donguleri (event loop)
	bool is_working = true;
	SDL_Event event;

	while (is_working)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				is_working = false;
			}
		}

		SDL_Delay(16);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}