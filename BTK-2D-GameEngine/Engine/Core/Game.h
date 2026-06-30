#pragma once
#include <SDL2/SDL.h>
#include <string>

class Game
{
public:
	Game();
	~Game();
	bool Init(const std::string& title, int width, int height);
	void Run();
	void Shutdown();
private:
	void ProcessInput();
	void Update(float deltaTime);
	void Render();

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	bool m_isRunning = false;
	int m_WindowWidth = 800;
	int m_WindowHeight = 600; 

	bool m_isFullScreen = false;
};