#include <iostream>
#include <cmath>
int main()
{
	setlocale(LC_ALL, "rus");
	int size, big=-9999999, small=99999999, sum=0;
	std::cout << "Введите размер массива" << std::endl;
	std::cin >> size;
    int* arr = new int[size];
	std::cout << "Введите " << size << " чисел для заполнения массива :" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Элемент " << i + 1 << ": ";
		std::cin >> arr[i];
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
		
	}//конец сортировки
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
			for (int j = i+1; j < size; j++)
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
	std::cout<<std::endl<<"Сумма между первым максимальным и последним минимальным элементами " << sum;

	
delete[] arr;
}
