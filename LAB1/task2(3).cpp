#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, k = 2,l=1, sum=0, pr=1;
	cout << "Введите n" << endl;
	cin >> n;
	for (k; k <= n; k +=2) 
	 {
		sum = sum + k;
	  }
	cout << "Сумма чётных чисел=" << sum << endl;
	for(l; l<=n; l+=2)
	 {
		pr = pr * l;
	 }
	cout << "Произведение нечётных чисел=" << pr << endl;


}
