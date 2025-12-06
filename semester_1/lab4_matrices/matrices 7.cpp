#include <iostream>
#include <random>
#include <iomanip>
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
			std::cout << std::setw(3)<<matrix[row][col] << " ";

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
int AskStart()
{
	int n;
	std::cout << "Введите число с которого начнётся спираль" << std::endl;
	if (!(std::cin >> n))
	{
		throw std::string("Число должно быть натуральным");
	}
	if (n < 0)
	{
		throw std::string("Число должно быть натуральным");
	}
	return n;
}

int AskAmountOfRows()
{
	 int n;
	std::cout << "Введите количество строк в массиве" << std::endl;
	if (!(std::cin >> n)  )
	{
		throw std::string("Некорректно введено число строк");
	}
	if (n < 0)
	{
		throw std::string("Некорректно введено число строк");
	}
	return n;
}
int AskAmountOfCols(unsigned int n)
{
	int m;
	std::cout << "Введите количество столбцов в массиве" << std::endl;
	if (!(std::cin >> m))
	{
		throw std::string ("Некорректно введено число столбцов");
	}
	if (m < 0)
	{
		throw std::string("Некорректно введено число строк");
	}
	if (!(n == m))
	{
		throw std::string("Матрица должна быть квадратной");
		
	}
	return m;
}
int main()
{
	setlocale(LC_ALL, "rus");
    int n, m, start;
	try
	{
		n = AskAmountOfRows();
		m = AskAmountOfCols(n);
		start = AskStart();
	}
	catch (const std::string& msg)
	{
		std::cerr << msg << std::endl;
		return 0;
	}

	int** matrix = CreateMatrix(n, m);
	FillMatrixSpiral(matrix, n, m, start);
	PrintMatrix(matrix, n, m);
	std::cout << "Сумма элементов побочной диагонали= " << SummOfDioganal(n, matrix) << std::endl;
	DeleteMatrix(matrix, n);



}
