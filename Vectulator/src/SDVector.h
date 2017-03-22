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

	void PrintVector(std::string name);
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

	//operational operators
	SDVector2 operator + (const SDVector2& vec);
	SDVector2 operator - (const SDVector2& vec);
	SDVector2 operator / (const SDVector2& vec);
	//multiplication will use the dot product

	float dot(const SDVector2& vec);
	SDVector2 Add(const SDVector2& vec1,const SDVector2& vec2);

private:
	float m_x;
	float m_y;
	std::string m_vectorName;
	
};

#endif