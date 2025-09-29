#include <iostream>
#include <random>
int main()
{
	setlocale(LC_ALL, "rus");
	const int SIZE = 10;
	int count = 1;
	int arr[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(-10, 10);
		int x = dist(gen);
		arr[i] = x;
	
	}
	for (int i = 1; i < SIZE; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			count++;
		}
	}
	std::cout << "Количество различных элементов " << count << std::endl;



}
