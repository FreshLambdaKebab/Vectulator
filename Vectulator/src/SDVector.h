#ifndef _SDVECTOR_H
#define _SDVECTOR_H

/*
SDVector class is a class to wrap all the main vector functionality and information
*/

#include <string>

class SDVector2
{
public:
	SDVector2();
	SDVector2(float x,float y);
	~SDVector2();

	void PrintVector(float x, float y);
	void DrawVector();

	//getters
	const float GetX()const { return m_x; }
	const float GetY()const { return m_y; }

	//setters
	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void Set(float x = 0.0f, float y = 0.0f) { m_x = x, m_y = y; }

	//useful vector functions
	float Length();
	float LengthSquared();
	void Normalize();

	//TODO:add vector operation functions...

private:
	float m_x;
	float m_y;
	std::string m_vectorName;
	//sf::Vertex line;
};

#endif