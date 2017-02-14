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

private:
	Window m_window;
	Graphics m_graphics;
	State m_state;
	int m_screenWidth;
	int m_screenHeight;

	//x and y coords for the vector
	float m_x;
	float m_y;
};

#endif
