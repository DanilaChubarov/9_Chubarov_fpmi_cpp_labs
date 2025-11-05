#include <iostream>

int** CreateMatrix(int n, int m)
{
	int** matrix = new int* [n];
	for (int row = 0; row < n; ++row)
	{
		matrix[row] = new int[m];
	}
	return matrix;
}
void DeleteMatrix(int** matrix, int n)
{
	for (int row = 0; row < n; ++row)
	{
		delete[] matrix[row];
	}
}
void FillMatrix(int** matrix, int n, int m)
{
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			std::cout << "Введите элемент строки " << row + 1 << " столбца " << col + 1 << std::endl;
			std::cin >> matrix[row][col];
		}
	}
}
void TurnArrayIntoMatrix(int** matrix, int* arr, int size, int n, int m)
{
	int i = 0;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			matrix[row][col] = arr[i];
			++i;
		}
	}
}
void PrintMatrix(int** matrix, int n, int m)
{
	std::cout << std::endl << std::endl;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			std::cout << matrix[row][col] << " ";

		}
		std::cout << std::endl;
	}
}
void FillArray(int* arr, int size, int n, int m)
{
	int i=0;
	for(int row=1; row<=n; row++)
	{ 
		for (int col=1; col<=m; ++col)
		{
			std::cout << "Введите элемент строки " << row << " столбца" << col << std::endl;
			std::cin >> arr[i];
			++i;
			
		}
	}
}
void BubbleSort(int* arr, int size, int sign_choice)
{
	if (sign_choice == 0)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j] < arr[j + 1]) 
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}
void Merge(int arr[], int left, int mid, int right, int sign_choice) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = arr[mid + 1 + i];

	int i = 0, j = 0, k = left;

	// Слияние с учетом порядка сортировки
	while (i < n1 && j < n2) {
		if ((sign_choice==0 && L[i] <= R[j]) || ( sign_choice==1 && L[i] >= R[j])) {
			arr[k++] = L[i++];
		}
		else {
			arr[k++] = R[j++];
		}
	}

	while (i < n1)
		arr[k++] = L[i++];

	while (j < n2)
		arr[k++] = R[j++];

	delete[] L;
	delete[] R;
}
void MergeSort(int arr[], int left, int right, int sign_choice) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		MergeSort(arr, left, mid, sign_choice);     // Сортируем левую часть
		MergeSort(arr, mid + 1, right, sign_choice); // Сортируем правую часть
		Merge(arr, left, mid, right, sign_choice); // Объединяем
	}
}
void CountingSort(int arr[], int n, int sign_choice) {
	if (sign_choice == 0)
	{
		// ШАГ 1: Находим максимальный элемент в массиве
		int max = arr[0];  // Предполагаем, что первый элемент - максимальный
		for (int i = 1; i < n; i++) {  // Проходим по всем элементам массива, начиная со второго
			if (arr[i] > max) {  // Если текущий элемент больше текущего максимума
				max = arr[i];    // Обновляем значение максимума
			}
		}

		// ШАГ 2: Создаем массив для подсчета частот элементов
		int* count = new int[max + 1]();  // Динамически создаем массив размером (max+1)
		// Круглые скобки () инициализируют массив нулями
		// Например, если max=8, создаем массив [0..8] (9 элементов)

	// ШАГ 3: Подсчитываем количество вхождений каждого элемента
		for (int i = 0; i < n; i++) {  // Проходим по всем элементам исходного массива
			count[arr[i]]++;           // Увеличиваем счетчик для текущего элемента
			// Например, если arr[i]=3, то count[3] увеличивается на 1
		}

		// ШАГ 4: Восстанавливаем отсортированный массив
		int index = 0;  // Индекс для записи в исходный массив
		for (int i = 0; i <= max; i++) {  // Проходим по всем возможным значениям от 0 до max
			while (count[i] > 0) {        // Пока есть элементы со значением i
				arr[index++] = i;         // Записываем значение i в массив и увеличиваем индекс
				count[i]--;               // Уменьшаем счетчик для значения i
			}
		}

		delete[] count;  // Освобождаем память, выделенную для массива count
	}
	else
	{
		// ШАГ 1: Находим максимальный элемент в массиве
		int max = arr[0];  // Предполагаем, что первый элемент - максимальный
		for (int i = 1; i < n; i++) {  // Проходим по всем элементам массива, начиная со второго
			if (arr[i] > max) {  // Если текущий элемент больше текущего максимума
				max = arr[i];    // Обновляем значение максимума
			}
		}

		// ШАГ 2: Создаем массив для подсчета частот элементов
		int* count = new int[max + 1]();  // Динамически создаем массив размером (max+1)
		// Круглые скобки () инициализируют массив нулями
		// Например, если max=8, создаем массив [0..8] (9 элементов)

	// ШАГ 3: Подсчитываем количество вхождений каждого элемента
		for (int i = 0; i < n; i++) {  // Проходим по всем элементам исходного массива
			count[arr[i]]++;           // Увеличиваем счетчик для текущего элемента
			// Например, если arr[i]=3, то count[3] увеличивается на 1
		}

		// ШАГ 4: Восстанавливаем отсортированный массив
		int index = 0;  // Индекс для записи в исходный массив
		for (int i = max; i >=0; i--) {  // Проходим по всем возможным значениям от 0 до max
			while (count[i] > 0) {        // Пока есть элементы со значением i
				arr[index++] = i;         // Записываем значение i в массив и увеличиваем индекс
				count[i]--;               // Уменьшаем счетчик для значения i
			}
		}

		delete[] count;  // Освобождаем память, выделенную для массива count
	}
}
void ShakerSort(int* mass, int count, int sign_choice)
{
	if (sign_choice == 0)
	{
		int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
		int flag = 1;  // флаг наличия перемещений
		// Выполнение цикла пока левая граница не сомкнётся с правой
		// и пока в массиве имеются перемещения
		while ((left < right) && flag > 0)
		{
			flag = 0;
			for (int i = left; i < right; i++)  //двигаемся слева направо
			{
				if (mass[i] > mass[i + 1]) // если следующий элемент меньше текущего,
				{             // меняем их местами
					int t = mass[i];
					mass[i] = mass[i + 1];
					mass[i + 1] = t;
					flag = 1;      // перемещения в этом цикле были
				}
			}
			right--; // сдвигаем правую границу на предыдущий элемент
			for (int i = right; i > left; i--)  //двигаемся справа налево
			{
				if (mass[i - 1] > mass[i]) // если предыдущий элемент больше текущего,
				{            // меняем их местами
					int t = mass[i];
					mass[i] = mass[i - 1];
					mass[i - 1] = t;
					flag = 1;    // перемещения в этом цикле были
				}
			}
			left++; // сдвигаем левую границу на следующий элемент
			if (flag == 0) break;
		}
	}
	else
	{
		int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
		int flag = 1;  // флаг наличия перемещений
		// Выполнение цикла пока левая граница не сомкнётся с правой
		// и пока в массиве имеются перемещения
		while ((left < right) && flag > 0)
		{
			flag = 0;
			for (int i = left; i < right; i++)  //двигаемся слева направо
			{
				if (mass[i] < mass[i + 1]) // если следующий элемент меньше текущего,
				{             // меняем их местами
					int t = mass[i];
					mass[i] = mass[i + 1];
					mass[i + 1] = t;
					flag = 1;      // перемещения в этом цикле были
				}
			}
			right--; // сдвигаем правую границу на предыдущий элемент
			for (int i = right; i > left; i--)  //двигаемся справа налево
			{
				if (mass[i - 1] < mass[i]) // если предыдущий элемент больше текущего,
				{            // меняем их местами
					int t = mass[i];
					mass[i] = mass[i - 1];
					mass[i - 1] = t;
					flag = 1;    // перемещения в этом цикле были
				}
			}
			left++; // сдвигаем левую границу на следующий элемент
			if (flag == 0) break;
		}
	}
}
void QuickSort(int* numbers, int left, int right, int sign_choice)
{
	if (sign_choice == 0) {
		int pivot; // разрешающий элемент
		int index; // индекс разрешающего элемента
		int l_hold = left; //левая граница
		int r_hold = right; // правая граница
		pivot = numbers[left];
		while (left < right) // пока границы не сомкнутся
		{
			while ((numbers[right] > pivot) && (left < right))
				right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
			if (left != right) // если границы не сомкнулись
			{
				numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
				left++; // сдвигаем левую границу вправо
			}
			while ((numbers[left] < pivot) && (left < right))
				left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
			if (left != right) // если границы не сомкнулись
			{
				numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
				right--; // сдвигаем правую границу влево
			}
		}
		numbers[left] = pivot; // ставим разрешающий элемент на место
		index = left;
		left = l_hold;
		right = r_hold;
		if (left < index) // Рекурсивно вызываем сортировку для левой и правой части массива
			QuickSort(numbers, left, index - 1,sign_choice);
		if (right > index)
			QuickSort(numbers, index + 1, right,sign_choice);
	}
	else
	{
		int pivot; // разрешающий элемент
		int index; // индекс разрешающего элемента
		int l_hold = left; //левая граница
		int r_hold = right; // правая граница
		pivot = numbers[left];
		while (left < right) // пока границы не сомкнутся
		{
			while ((numbers[right] < pivot) && (left < right))
				right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
			if (left != right) // если границы не сомкнулись
			{
				numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
				left++; // сдвигаем левую границу вправо
			}
			while ((numbers[left] > pivot) && (left < right))
				left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
			if (left != right) // если границы не сомкнулись
			{
				numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
				right--; // сдвигаем правую границу влево
			}
		}
		numbers[left] = pivot; // ставим разрешающий элемент на место
		index = left;
		left = l_hold;
		right = r_hold;
		if (left < index) // Рекурсивно вызываем сортировку для левой и правой части массива
			QuickSort(numbers, left, index - 1, sign_choice);
		if (right > index)
			QuickSort(numbers, index + 1, right, sign_choice);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, m, size, sort_choice, sign_choice;
    std::cout << "Введите колисво строк в массиве"<<std::endl;
	std::cin >> n;
	std::cout << "Введите количество столбцов в массиве" << std::endl;
	std::cin >> m;
	size = n * m;
	
	int* arr = new int[size];
	FillArray(arr, size, n, m);
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "Выбирете метод сортировки \n Пузырьком(0) \n Слиянием(1) \n Подсчётом(2) \n Шейкерная(3) \n Быстрая сортировка(4)\n";
	std::cin >> sort_choice;
	std::cout << "Если хотите отсортировать от меньшего к большему введите 0\n Если хотите отсортировать от большего к меньшему введите 1 \n ";
	std::cin >> sign_choice;
	switch (sort_choice)
	{
	case 0:
		  BubbleSort(arr, size, sign_choice);
		  break;
	case 1:
		 MergeSort(arr, 0, size-1, sign_choice);
		 break;
	case 2:
		 CountingSort(arr, size, sign_choice);
		 break;
	case 3:
		ShakerSort(arr, size, sign_choice);
		break;
	case 4:
		QuickSort(arr, 0, size - 1, sign_choice);
			break;
	}
	int**matrix=CreateMatrix(n, m);
	TurnArrayIntoMatrix(matrix, arr, size, n, m);
	PrintMatrix(matrix, n, m);
	DeleteMatrix(matrix, n);
}

