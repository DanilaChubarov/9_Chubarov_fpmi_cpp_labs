#include "vector_impl.h"
#include <iostream>
std::ostream& operator<<(std::ostream& cout, Vector& vector)
{
	cout << "[";
	if (vector.Size() == 0)
	{
		cout << "]";
                return cout;
	}
	for (size_t i = 0; i < vector.Size() - 1; ++i)
	{
		cout << vector[i] << ", ";
	}
	cout << vector[vector.Size() - 1];
	cout << "]";
	return cout;
}
