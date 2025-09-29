#include <iostream>
#include <cmath>
int main()
{
	setlocale(LC_ALL, "rus");
	const int SIZE = 4;
	int arr[SIZE];
	std::cout << "Введите " << SIZE << " чисел для заполнения массива :" << std::endl;
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << "Элемент " << i + 1 << ": ";
		std::cin >> arr[i];
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

	int small, pr = 1;
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
