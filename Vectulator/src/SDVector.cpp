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

void SDVector2::PrintVector(std::string name)
{
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

SDVector2 SDVector2::operator+(const SDVector2 & vec)
{
	//create a temporary vector to add onto desired vector
	SDVector2 tempVec = *this;//it equals a dereferenced pointer to this class
	tempVec.m_x += vec.m_x;
	tempVec.m_y += vec.m_y;

	return tempVec;
}

SDVector2 SDVector2::operator-(const SDVector2 & vec)
{
	SDVector2 tempVec = *this;
	tempVec.m_x -= vec.m_x;
	tempVec.m_y -= vec.m_y;

	return tempVec;
}

/*
-https://www.symbolab.com/solver/vector-add-subtract-calculator/%5Cleft(100%2C50%5Cright)%20%5Ccdot%20%5Cleft(20%2C100%5Cright)
*/

/*SDVector2 SDVector2::operator/(const SDVector2 & vec)
{
	
}*/

float SDVector2::dot(const SDVector2 & vec)
{
	float dot = m_x * vec.m_x + m_y * vec.m_y;

	return dot;
}

SDVector2 SDVector2::Add(const SDVector2 & vec1, const SDVector2 & vec2)
{
	SDVector2 resultantVec;
	
	resultantVec.m_x = vec1.m_x + vec2.m_x;
	resultantVec.m_y = vec1.m_y + vec2.m_y;
	
	return resultantVec;
}

