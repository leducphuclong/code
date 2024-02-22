#include <iostream>

using namespace std;

int n;

int tong(int n)
{
    for (int i = 1; i <= n; i++)
        return tong + i;
}

int main()
{
    cout "N: ";
    cin >> n;
    cout << tong(n);
    return 0;
}
