#include <iostream>
#include <cmath>
#include <random>
int main()
{
	setlocale(LC_ALL, "rus");
	const int SIZE = 10;
	int count = 1, a;
	int arr[SIZE];
	std::cout << "Если хотите рандомно заполнить введите 0, если заполнить сами 1" << std::endl;
	std::cin >> a;
	if (a == 1)
	{
		std::cout << "Введите " << SIZE << " чисел для заполнения массива :" << std::endl;
		for (int i = 0; i < SIZE; ++i)
		{
			std::cout << "Элемент " << i + 1 << ": ";
			std::cin >> arr[i];
		}
	}
	else
	{
		for (int i = 0; i < SIZE; i++) //рандомайзер
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> dist(-20, 20);
			int x = dist(gen);
			arr[i] = x;
		}
	}

	for (int i = 0, pos = 0; i < SIZE; i++) {//начало сортировки
		if (arr[i] == 0) {
			int temp = arr[i];
			for (int j = i; j > pos; j--) {
				arr[j] = arr[j - 1];
			}
			arr[pos] = temp;
			pos++;
		}
	}
	for (int i = 0, pos = 0; i < SIZE; i++)
	{
		if (arr[i] < 0)
		{
			int temp = arr[i];
			for (int j = i; j > pos; j--)
			{
				arr[j] = arr[j - 1];
			}
			arr[pos] = temp;
			pos++;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << std::endl;
	}                  //конец сортировки
	for (int i = 1; i < SIZE; i++)//задание 1
	{
		if (arr[i] != arr[i - 1])
		{
			count++;
		}
	}
	std::cout << "Количество различных элементов " << count << std::endl;
	int small, pr = 1;//задание 2
	small = abs(arr[0]);
	for (int i = 0; i < SIZE; i++)
	{
		if (abs(arr[i]) < small)
		{
			small = abs(arr[i]);
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (abs(arr[i]) == small)
		{
			break;
		}
		pr = pr * arr[i];
	}
	std::cout << "Произведение= " << pr << std::endl;
}


