#include <iostream>
#include <array>

using namespace std;

int n;  array<unsigned short int, 10000> a;

void inra()
{
    for (int i = 1; i <= n; i++)
        cout << a[i];   cout << endl;
}


void thu(int i)
{
    for  (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
            inra();
        else
            thu(i+1);
    }
}

int main()
{
    system("cls");
    cout << "Nhap phan tu mang nhi phan: ";
    cin >> n;
    cout << "Cac so nhi phan gom " << n << " chu so la: " << endl;
    thu(1);
    return 0;
}
