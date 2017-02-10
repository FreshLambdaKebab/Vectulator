#include "SDVector.h"
#include <iostream>

SDVector2::SDVector2(std::string vectorName,float x,float y):
	m_x(x),
	m_y(x),
	m_vectorName(vectorName)
{
	std::cout << m_vectorName.c_str() << "(" << m_x << "," << m_y << ")" << std::endl;
}

SDVector2::~SDVector2()
{
}
