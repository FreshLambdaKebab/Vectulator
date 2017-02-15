#include "SDVector.h"
#include <iostream>

SDVector2::SDVector2():
	m_x(0.0f),
	m_y(0.0f)
{
}

SDVector2::SDVector2(float x, float y)
{
	Set(x, y);
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

float SDVector2::Length()
{
	float length = sqrt(m_x * m_x + m_y * m_y);

	return length;
}

float SDVector2::LengthSquared()
{
	float length = m_x * m_x + m_y * m_y;

	return length;
}

void SDVector2::Normalize()
{
	float length = this->Length();

	//be sure to not divide by zero!!
	if (length == 0.0f)
	{
		m_x = 0.0f;
		m_y = 0.0f;

		return;
	}
	
	m_x /= length;
	m_y /= length;
}

