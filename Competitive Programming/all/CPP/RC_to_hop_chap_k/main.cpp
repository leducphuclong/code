#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;
long int n,k; array<long int, 10000> a;

void inra()
{
    for (int i = 1; i <= k; i++)
        cout << a[i];   cout << "\t";
}

void go(int i)
{
    for (int j = a[i-1] +1; j <= n; j++)
    {
        a[i] = j;
        if (i == k) inra(); else go(i+1);
    }
}

int main()
{
    system("cls");
    a.fill(0);
    cout << "n: ";  cin >> n;
    cout << "k: ";  cin >> k;
    go(1);
    cout << endl;
    system("pause");
    return 0;
}
