#pragma once

#include <SDL\SDL.h>
#include <string>

class Window
{
public:
	Window();
	~Window();

	int CreateWindow(std::string windowName,int screenWidth,int screenHeight);

	SDL_Window* GetWindow() { return m_window; }
	SDL_Renderer* GetRenderer() { return m_renderer; }

	int GetScreenWidth() { return m_screenWidth;}
	int GetScreenHeight() { return m_screenHeight; }

	void BeginRender(int r,int g,int b,int a = 255);
	void EndRender();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	int m_screenWidth;
	int m_screenHeight;


};