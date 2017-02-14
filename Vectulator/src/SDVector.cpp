#include "SDVector.h"
#include <iostream>

SDVector2::SDVector2(std::string vectorName,float x,float y):
	m_x(x),
	m_y(y),
	m_vectorName(vectorName)
{
	//create the line vertex
	/*sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(400,300)),
		sf::Vertex(sf::Vector2f(400 + m_x,300 - m_y))
	};*/
}

SDVector2::~SDVector2()
{
}

void SDVector2::PrintVector(float x, float y)
{
	m_x = x;
	m_y = y;

	std::cout << m_vectorName.c_str() << "(" << m_x << "," << m_y << ")" << std::endl;
}

void SDVector2::DrawVector()
{
	
}

