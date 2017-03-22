#ifndef _FRAME_WORK_H
#define _FRAME_WORK_H

//#include "Window.h"
#include "Graphics.h"

enum class State
{
	APP,
	EXIT
};

class AppScene
{
public:
	AppScene();
	~AppScene();

	void Init();
	void Run();
	void Render();
	void Update();

	//functions to display info
	void DisplayAddInfo();
	void DisplaySubInfo();
	//void DisplayDivInfo();
	void DisplayMultInfo();


private:
	Window m_window;
	Graphics m_graphics;
	State m_state;
	int m_screenWidth;
	int m_screenHeight;
	SDL_Rect m_cameraRect = { 0,0,800,600 };
	SDL_Rect m_viewPort;

	//initialize the two vectors
	SDVector2 vec1;
	SDVector2 vec2;
	SDVector2 resultantVec;

	//x and y coords for the vectors
	float m_vec1X, m_vec1Y;
	float m_vec2X, m_vec2Y;

	//origin coordinates for vectors and axis
	float m_x;
	float m_y;

	//opration char
	char op;

};

#endif
