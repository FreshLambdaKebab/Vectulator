#include "Graphics.h"

Graphics::Graphics() 
{

}

Graphics::~Graphics()
{
}

void Graphics::DrawLine(SDL_Renderer& renderer, int x1, int y1, int x2, int y2)
{
	SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderDrawLine(&renderer, x1, y1, x2, y2);
}

void Graphics::DrawLine(SDL_Renderer & renderer, int x1, int y1, int x2, int y2, int r, int g, int b)
{
	SDL_SetRenderDrawColor(&renderer,r, g, b, 0xFF);
	SDL_RenderDrawLine(&renderer, x1, y1, x2, y2);
}

void Graphics::DrawLine(SDL_Renderer& renderer, SDVector2& startPos, SDVector2& endPos)
{
	SDL_SetRenderDrawColor(&renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawLine(&renderer, startPos.GetX(), startPos.GetY(), endPos.GetX(), endPos.GetY());
}

void Graphics::DrawLine(SDL_Renderer & renderer, SDVector2 & startPos, SDVector2 & endPos, int r, int g, int b)
{
	SDL_SetRenderDrawColor(&renderer, r, g, b, 0xFF);
	SDL_RenderDrawLine(&renderer, startPos.GetX(), startPos.GetY(), endPos.GetX(), endPos.GetY());
}
