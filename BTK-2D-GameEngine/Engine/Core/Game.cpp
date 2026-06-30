#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>

Game::Game() {}
Game::~Game() { Shutdown(); }

bool Game::Init(const std::string& title, int width, int height)
{
	m_WindowWidth = width;
	m_WindowHeight = height;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "SDL Init Failed" << SDL_GetError() << std::endl;
		return false;
	}

	m_Window = SDL_CreateWindow
	(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_SHOWN
	);

	if (!m_Window)
	{
		std::cerr << "Window Creation Failed" << SDL_GetError() << std::endl;
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_Renderer)
	{
		std::cerr << "Renderer Creation Failed " << SDL_GetError() << std::endl;
	}

	m_isRunning = true;
	return true;
}

void Game::Run()
{
	while (m_isRunning)
	{
		ProcessInput();
		Update(0.0f);
		Render();
	}
}

void Game::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_isRunning = false;
		}

		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					m_isRunning = false;
					break;
				case SDLK_F11:
					m_isFullScreen = !m_isFullScreen;
					if (m_isFullScreen)
					{
						SDL_SetWindowFullscreen(m_Window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					}
					else
					{
						SDL_SetWindowFullscreen(m_Window, 0); // return to windowed screen
					}
					break;
				default:
					break;
			}
		}
	}
}

void Game::Update(float deltaTime)
{

}

void Game::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 30, 30, 255); // Background
	SDL_RenderClear(m_Renderer);
	SDL_RenderPresent(m_Renderer);
}

void Game::Shutdown()
{
	if (m_Window) 
	{
		SDL_DestroyWindow(m_Window);
		m_Window = nullptr;
	}
	if (m_Renderer) 
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
	SDL_Quit();
}