#include <iostream>
#include <ctime>
#include <array>

using namespace std;

int n;  array<int, 10000> a;

void khoitao()
{
    cout << "Nhap n la so phan tu cua mang: ";
    cin >> n;
    cout << "Mang duoc khoi tao ngau nhien: " << endl;
    for (int i = 1; i <= n; i++)
    {
        a[i] = rand() % 50 + 51;
        cout << a[i] << "\t";
    }
  //  a[1] = 4; a[2] = 1; a[3] = 7; a[4] = 5; a[5] = 3; a[6] = 2; a[7] = 6;
}

void qs(int d, int c)
{
    int i = d; int j = c; int m = a[(d+c) / 2]; int mp = m;
    while (i < j)
    {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j)
        {
            int tg  = a[i];
            a[i] = a[j];
            a[j] = tg;
            i++;    j--;
        }
    }
    if (i < c) qs(i,c);
    if (j > d) qs(d,j);
}

void inra()
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << "\t";
    cout << endl;
}

int main()
{
    system("cls");
    //srand(time(0));
    khoitao();
    cout << endl;
    qs(1,n);
    cout << "Sau khi sap xep nhanh: " << endl;
    inra();
    system("pause");
    return 0;
}
