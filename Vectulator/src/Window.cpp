#include "Window.h"
#include <iostream>

Window::Window():
	m_window(nullptr),
	m_renderer(nullptr)
{
}

Window::~Window()
{
	//destroy the window	
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	m_window = NULL;
	m_renderer = NULL;

	SDL_Quit();
}

int Window::CreateWindow(std::string windowName, int screenWidth, int screenHeight)
{
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	m_window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		                        screenWidth,screenHeight,SDL_WINDOW_SHOWN);

	if (m_window == nullptr)
	{   //check if the window was created
		std::cout << "failed to create window" << std::endl;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr)
	{
		std::cout << "failed to create renderer" << std::endl;
	}
	else
	{
		SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}

	return 0;
}

void Window::BeginRender(int r, int g, int b, int a)
{   //Clear screen
	SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
	SDL_RenderClear(m_renderer);
}

void Window::EndRender()
{
	//render and present then swap the buffers
	SDL_RenderPresent(m_renderer);
	SDL_GL_SwapWindow(m_window);
}
