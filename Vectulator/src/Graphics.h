#pragma once
#include <SDL\SDL.h>
#include "Window.h"
#include "SDVector.h"

class Graphics : public SDVector2
{
public:
	Graphics();
	~Graphics();

	//overloaded line drawing functions
	void DrawLine(SDL_Renderer& renderer,int x1,int y1,int x2,int y2);
	void DrawLine(SDL_Renderer& renderer, int x1, int y1, int x2, int y2,int r,int g,int b);
	void DrawLine(SDL_Renderer& renderer, SDVector2& startPos, SDVector2& endPos);
	void DrawLine(SDL_Renderer& renderer, SDVector2& startPos, SDVector2& endPos,int r,int g,int b);

	//TODO:maybe add other shapes for fun

private:
	
};

