#include "AppScene.h"
#include <iostream>

AppScene::AppScene():
	m_x(0),
	m_y(0),
	m_screenWidth(800),
	m_screenHeight(600),
	m_state(State::APP)
{
}

AppScene::~AppScene()
{
}

void AppScene::Init()
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window.CreateWindow("Vectulator ~ Developed by Stefan Duranski", m_screenWidth, m_screenHeight);

	/*char c;
	std::cout << "****Welcome to Vectulator!****\nEnter any key to start!" << std::endl;
	std::cin >> c;
	printf("Set X coord for vector1: ");
	std::cin >> m_x;
	printf("Set Y coord for vector1: ");
	std::cin >> m_y;*/

}

void AppScene::Run()
{
	//keep the window running until user quits
	while (m_state != State::EXIT)
	{   //update and render the application every frame
		Update();
		Render();
	}

}

void AppScene::Render()
{
	glClearDepth(1.0f);
	//clear color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//draw everything here
	m_window.BeginRender(0,0,0);
	m_graphics.DrawLine(*m_window.GetRenderer(),0,0,800,600);
	m_graphics.DrawLine(*m_window.GetRenderer(), 800, 0, 0, 600,255,0,0);
	//SDL_RenderDrawLine(m_renderer, 0, 0, 800, 600);

	m_window.EndRender();
}

void AppScene::Update()
{
	SDL_Event windowEvent;

	while (SDL_PollEvent(&windowEvent))
	{
		switch (windowEvent.type)
		{
		case SDL_QUIT:
			m_state = State::EXIT;
			break;
		}

		//check if user has pressed escaped to exit window
		if (windowEvent.type == SDL_KEYDOWN && windowEvent.key.keysym.sym == SDLK_ESCAPE)
		{
			m_state = State::EXIT;
		}
	}

}