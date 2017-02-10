#include <iostream>
#include "SDVector.h"

int main()
{
	char c;
	std::cout << "****Welcome to Vectulator!****\npress any key to continue!" << std::endl;
	std::cin >> c;

	SDVector2 vec1("vec1",20.0f,23.0f);

	//exti program once any key is pressed
	std::cin >> c;

	return 0;
}