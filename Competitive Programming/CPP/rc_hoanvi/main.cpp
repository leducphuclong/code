#include <iostream>
#include <array>
#include <cstdlib>
#include <cmath>

using namespace std;

int n, times; array<short int, 50> a, p;

void inra()
{
    times++;
    for (int i = 1; i <= n; i++)
        cout << a[i];   cout << "\t";
}

void go(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (p[j] == 0)
        {
            p[j] = 1;
            a[j] = i;
            if (i == n) inra();
            go(i+1);
            p[j] = 0;
        }
    }
}

void xuli()
{
    a.fill(0); p.fill(0);   times = 0;
    go(1);
}

int main()
{
    system("cls");
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << endl << endl;
    cout << "Cac hoan vi cua " << n << " la: " << endl << endl;
    xuli();
    cout << endl << endl;
    cout << "So hoan vi cua " << n << " la: " << times << endl;
    system("pause");
    return 0;
}
