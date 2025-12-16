#include "vector.h"
#include <iostream>
int main()
{
	Vector array(3);
	Vector massiv{ 1,34 ,42 };
	Vector array_copy(massiv);
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << array_copy[i] << " ";
	}
		
	

	return 0;
}
