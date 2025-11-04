#include <iostream>
using namespace std;
int main()
{
	int n, k = 0, sum=0;
	setlocale(LC_ALL, "rus");
	cout << "¬ведите число n" << endl;
	cin >> n;
	while (k < n)
	{
		k++;
		sum = sum + (k * k);
	}
	cout << "s=" << sum << endl;


}