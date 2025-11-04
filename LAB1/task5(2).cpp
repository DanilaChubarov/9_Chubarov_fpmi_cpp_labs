#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");

	int m, a;
	cout << "¬ведите m ";
	cin >> m;
	for (a = 2; a <= m; a++)
	{
		if (m % a == 0)
		{
		  cout << a << endl;
		}



	}



}

