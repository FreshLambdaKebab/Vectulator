#ifndef _SDVECTOR_H
#define _SDVECTOR_H

/*
SDVector class is a class to wrap all the main vector functionality and information
*/

#include <string>

class SDVector2
{
public:
	SDVector2(std::string vectorName,float x,float y);
	~SDVector2();

	void PrintVector(float x, float y);
	void DrawVector();

	//getters
	float& GetX() { return m_x; }
	float& GetY() { return m_y; }

	//setters
	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }


private:
	float m_x;
	float m_y;
	std::string m_vectorName;
	//sf::Vertex line;
};

#endif