#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, k = 2,l=1, sum=0, pr=1;
	cout << "������� n" << endl;
	cin >> n;
	for (k; k <= n; k +=2) 
	 {
		sum = sum + k;
	  }
	cout << "����� ������ �����=" << sum << endl;
	for(l; l<=n; l+=2)
	 {
		pr = pr * l;
	 }
	cout << "������������ �������� �����=" << pr << endl;


}
