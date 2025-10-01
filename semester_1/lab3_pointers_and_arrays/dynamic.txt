#include <iostream>
#include <cmath>
#include <random>
int main()
{
	setlocale(LC_ALL, "rus");
	int size, maxLen = 1, currLen = 1, startIndex = 0, currStart = 0, a, big=999999999999, small=-9999999999999, sum=0;
	std::cout << "Введите размер массива" << std::endl;
	std::cin >> size;
	int* arr = new int[size];
	std::cout << "Если хотите рандомно заполнить введите 0, если заполнить сами 1" << std::endl;
	std::cin >> a;
	if (a == 1)
	{
		std::cout << "Введите " << size << " чисел для заполнения массива :" << std::endl;
		for (int i = 0; i < size; ++i)
		{
			std::cout << "Элемент " << i + 1 << ": ";
			std::cin >> arr[i];
		}
	}
	else
	{
		for (int i = 0; i < size; i++) //рандомайзер
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> dist(-20, 20);
			int x = dist(gen);
			arr[i] = x;
		}
	}



	for (int i = 0; i < size - 1; i++) { //сортировка
		for (int j = 0; j < size - i - 1; j++) {
			if (abs(arr[j]) < abs(arr[j + 1])) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	std::cout << "Массив по убыванию модулей: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";

	}
	std::cout << std::endl; //конец сортировки
	for (int i = 1; i < size; i++) {//1
		if (arr[i] > arr[i - 1]) {
			currLen++;
		}
		else {
			if (currLen > maxLen) {
				maxLen = currLen;
				startIndex = currStart;
			}
			currLen = 1;
			currStart = i;
		}
	}
	if (currLen > maxLen) {
		maxLen = currLen;
		startIndex = currStart;
	}
	std::cout << "Самая длинная возрастающая цепочка: ";
	for (int i = startIndex; i < startIndex + maxLen; i++) {
		std::cout << arr[i] << " ";
	}
	for (int i = 0; i < size; i++)//поиск большого
	{
		if (big < arr[i])
		{
			big = arr[i];
		}

	}
	for (int i = 0; i < size; i++)//поиск маленького
	{
		if (small > arr[i])
		{
			small = arr[i];
		}

	}
	for (int i = 0; i < size; i++)//подсчёт сумммы
	{
		if (arr[i] == small)
		{
			goto endloops;
		}
		if (arr[i] == big)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[j] == small)
				{
					goto endloops;
				}
				sum = arr[j] + sum;
			}
		}
	}
endloops:
	std::cout << std::endl << "Сумма между первым максимальным и последним минимальным элементами " << sum;




	delete[] arr;

}
