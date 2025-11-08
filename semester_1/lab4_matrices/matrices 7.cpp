#include <iostream>
#include <random>
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
void FillMatrixRandom(int** matrix, int n, int m)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(-20, 20);
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			matrix[row][col] = dist(gen);
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
void FillMatrixSpiral(int** matrix, int n, int m, int start)
{
	int s = start, top = 0, bottom = n - 1, right = m - 1, left = 0;
	while (top <= bottom && left <= right)
	{
		if (left <= right)
		{
			for (int i = left; i <= right; i++)
			{
				matrix[top][i] = s;
				s++;
			}
			++top;
		}
		if (left == right)
		{
			break;
		}
		if (top <= bottom)
		{
			for (int j = top; j <= bottom; j++)
			{
				matrix[j][right] = s;
				s++;
			}
			right--;
		}

		if (left <= right)
		{
			for (int k = right; k >= left; k--)
			{
				matrix[bottom][k] = s;
				s++;
			}
			bottom--;
		}
		if (top <= bottom)
		{
			for (int l = bottom; l >= top; l--)
			{
				matrix[l][left] = s;
				s++;
			}
			++left;
		}
	}
}
int SummOfDioganal(int n, int** matrix)
{
	int sum = 0;
	for (int i = 0, j = n - 1; i < n && j >= 0; ++i, --j)
	{
		sum = sum + matrix[i][j];
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, m, start;
	std::cout << "Введите количество строк в массиве" << std::endl;
	if (!(std::cin >> n))
	{
		std::cerr << "Это не число";
		std::exit(1);
	}
	if (n < 1)
	{
		std::cout << "Число меньше нуля";
		std::exit(2);
	}
	std::cout << "Введите количество столбцов в массиве" << std::endl;
	if (!(std::cin >> m))
	{
		std::cerr << "Это не число";
		std::exit(3);
	}
	if (m < 1)
	{
		std::cerr << "Число меньше нуля";
		std::exit(4);
	}
	if (!(n == m))
	{
		std::cerr << "Матрица должна быть квадратной";
		std::exit(5);
	}
	int** matrix = CreateMatrix(n, m);
	std::cout << "Введите число с которого начнётся спираль" << std::endl;
	if (!(std::cin >> start))
	{
		std::cerr << "Это не число";
		std::exit(6);
	}
	if (start < 1)
	{
		std::cout << "Число не натуральное";
		std::exit(7);
	}
	FillMatrixSpiral(matrix, n, m, start);
	PrintMatrix(matrix, n, m);
	std::cout << "Сумма элементов побочной диагонали= " << SummOfDioganal(n, matrix) << std::endl;
	DeleteMatrix(matrix, n);



}
