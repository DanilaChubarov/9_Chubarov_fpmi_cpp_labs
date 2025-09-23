#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int n, a, b, d;
    cout << "Введите n" << endl;
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        for (b = a + 1; b <= n; b++)
        {
            d = b * b + a * a;
            float c = sqrt(d);
            if ((c <= n) && (floor(c)==c))
            {
                cout << a << " " << b << " " << c << endl;
            }
        }
    }


}
