#include "AppScene.h"
#include <iostream>
#include "SDVector.h"
//using c standard library(6/3/17)
#include <cstdlib>

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
	m_soundEngine->drop();
}

void AppScene::Init()
{
	//initialize sdl and create the window
	SDL_Init(SDL_INIT_VIDEO);
	m_window.CreateWindow("Vectulator ~ Developed by Stefan Duranski", m_screenWidth, m_screenHeight);

	printf("Which operation do you want to do with 2 vectors? \n");
	std::cin >> op;

	switch (op)
	{
	case '+':
	{
		printf("Set X coord for vector1: ");
		std::cin >> m_vec1X;
		vec1.SetX(m_vec1X);
		printf("Set Y coord for vector1: ");
		std::cin >> m_vec1Y;
		vec1.SetY(m_vec1Y);
		vec1.PrintVector("Vector1");

		//get input for second vector
		printf("Set X coord for vector2: ");
		std::cin >> m_vec2X;
		vec2.SetX(m_vec2X);
		printf("Set Y coord for vector2: ");
		std::cin >> m_vec2Y;
		vec2.SetY(m_vec2Y);
		vec2.PrintVector("Vector2");
		DisplayAddInfo();
	}break;
	case '-':
	{
		printf("Set X coord for vector1: ");
		std::cin >> m_vec1X;
		vec1.SetX(m_vec1X);
		printf("Set Y coord for vector1: ");
		std::cin >> m_vec1Y;
		vec1.SetY(m_vec1Y);
		vec1.PrintVector("Vector1");

		//get input for second vector
		printf("Set X coord for vector2: ");
		std::cin >> m_vec2X;
		vec2.SetX(m_vec2X);
		printf("Set Y coord for vector2: ");
		std::cin >> m_vec2Y;
		vec2.SetY(m_vec2Y);
		vec2.PrintVector("Vector2");
		DisplaySubInfo();
	}break;
	case '*':
	{
		printf("Set X coord for vector1: ");
		std::cin >> m_vec1X;
		vec1.SetX(m_vec1X);
		printf("Set Y coord for vector1: ");
		std::cin >> m_vec1Y;
		vec1.SetY(m_vec1Y);
		vec1.PrintVector("Vector1");
																
		//get input for second vector
		printf("Set X coord for vector2: ");
		std::cin >> m_vec2X;
		vec2.SetX(m_vec2X);
		printf("Set Y coord for vector2: ");
		std::cin >> m_vec2Y;
		vec2.SetY(m_vec2Y);
		vec2.PrintVector("Vector2");

		DisplayMultInfo();
	}break;
	case '/':
	{
		printf("DOING DIVISION\n");

	}break;
	default:
		printf("THAT IS NOT A VALID OPERATION!\n");
	}

	


	//setup viewport
	m_viewPort.x = 0;
	m_viewPort.y = 0;
	m_viewPort.w = m_screenWidth;
	m_viewPort.h = m_screenHeight;

	m_x = 200;
	m_y = 450;
	//initialize the sound engine
	m_soundEngine->play2D("res/Developers.mp3", GL_TRUE);

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

	//render the view port
	SDL_RenderSetViewport(m_window.GetRenderer(), &m_viewPort);

	//draw all the test lines(Axis lines)
	m_graphics.DrawLine(*m_window.GetRenderer(),SDVector2(0,m_y),SDVector2(800,m_y),255,0,0);
	m_graphics.DrawLine(*m_window.GetRenderer(), SDVector2(m_x, 0), SDVector2(m_x, 600), 0, 0, 255);

	if(op == '+')
	{//////////////////////RENDER ADDITION(+) VECTORS///////////////////////////////////////////
		//draw vector 1
		m_graphics.DrawLine(*m_window.GetRenderer(), SDVector2(m_x, m_y), SDVector2(m_x + vec1.GetX(), m_y - vec1.GetY()), 255, 255, 0);

		//draw vector 2
		m_graphics.DrawLine(*m_window.GetRenderer(), SDVector2(m_x + vec1.GetX(), m_y - vec1.GetY()),//implemented vec2 to be drawn on the tip of vector 1(6/3/17)
			SDVector2(m_x + vec1.GetX() + vec2.GetX(), m_y - vec1.GetY() - vec2.GetY()), 255, 0, 255);

		//draw resultant vector
		//draw the resulatant vector
		m_graphics.DrawLine(*m_window.GetRenderer(), SDVector2(m_x, m_y), SDVector2(m_x + vec1.GetX() + vec2.GetX(), m_y - vec1.GetY() - vec2.GetY()), 0, 255, 0);
	}

	if(op == '-')
	{//////////////////////RENDER SUBTRACTION(-) VECTORS///////////////////////////////////////////
	 //draw vector 1
		m_graphics.DrawLine(*m_window.GetRenderer(), SDVector2(m_x, m_y), SDVector2(m_x + vec1.GetX(), m_y - vec1.GetY()), 255, 255, 0);

		//draw vector 2
		m_graphics.DrawLine(*m_window.GetRenderer(), SDVector2(m_x , m_y),//implemented vec2 to be drawn on the tip of vector 1(6/3/17)
			SDVector2(m_x + vec1.GetX() + vec2.GetX(), m_y - vec1.GetY() - vec2.GetY()), 255, 0, 255);

		//draw resultant vector
		//draw the resulatant vector
		m_graphics.DrawLine(*m_window.GetRenderer(), SDVector2(m_x + vec1.GetX(), m_y - vec1.GetY()),
			SDVector2(m_x + vec1.GetX() + vec2.GetX(), m_y - vec1.GetY() - vec2.GetY()), 0, 255, 0);
	}

	if (op == '*')
	{//////////////////////RENDER SUBTRACTION(-) VECTORS///////////////////////////////////////////

	}

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
void AppScene::DisplayAddInfo()
{
	resultantVec = vec1 + vec2;
	std::cout << "--------------------------------------------------\n";
	printf("Resultant vector co-ords- X:%f Y:%f", resultantVec.GetX(), resultantVec.GetY());
}

void AppScene::DisplaySubInfo()
{
	resultantVec = vec1 - vec2;
	std::cout << "--------------------------------------------------\n";
	printf("Resultant vector co-ords- X:%f Y:%f", resultantVec.GetX(), resultantVec.GetY());
}

/*void AppScene::DisplayDivInfo()
{
	resultantVec = vec1 / vec2;
	std::cout << "--------------------------------------------------\n";
	printf("Resultant vector co-ords- X:%f Y:%f", resultantVec.GetX(), resultantVec.GetY());
}*/

void AppScene::DisplayMultInfo()
{
	float dot = vec1.GetX() * vec2.GetX() + vec1.GetY() * vec2.GetY();

	std::cout << "--------------------------------------------------\n";
	printf("Resultant scalar value= %f", dot);

}


