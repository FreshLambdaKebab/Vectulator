#pragma once
#include <SDL\SDL.h>
#include "Window.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	//overloaded functions
	void DrawLine(SDL_Renderer& renderer,int x1,int y1,int x2,int y2);
	void DrawLine(SDL_Renderer& renderer, int x1, int y1, int x2, int y2,int r,int g,int b);

private:
	
};

