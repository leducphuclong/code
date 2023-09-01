#include <iostream>
#include <cstdlib>
#include <array>

using namespace std;

int n;  array<bool, 10000> p;
int fibo(int n)
{
    if (n <= 2)
        return 1;
    else;
    {

        int pfi = fibo(n-1) + fibo(n-2);
        if (!p[n])
        {
            cout << pfi << "\t";
            p[n] = 1;
        }
        return pfi;
    }
}

int main()
{
    system("cls");
    p.fill(0);
    cout << "Nhap N la do dai day Fibo: ";
    cin >> n;
    cout << endl;
    cout << "Day fibo do la: " << endl;
    cout << fibo(n) << endl;
    cout << endl;
    system("pause");
    return 0;
}
