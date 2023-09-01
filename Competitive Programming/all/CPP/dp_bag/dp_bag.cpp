#include <iostream>
#include <fstream>
#include <cstdlib>
#include <array>
#include <unistd.h>

using namespace std;
long int n, p, nd;
  array<long int, 10000> m, c, d;
  array<array<long int, 10000>, 10000> dp;

fstream f1, f2;

void laydulieu()
{
    system("cls");
    f1.open("dp_bag.inp", ios::in);
    f1 >> n >> p;
    //cout << n << "\t" << p << endl;
    for (int i = 1; i <= n; i++)
    {
        f1 >> m[i] >> c[i];
        //cout << m[i] << "    " << c[i] << endl;
    }
    f1.close();
}

long int max(int x, int y)
{
    if (x >= y) return x;    return y;
}

void inra()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= p; j++)
            cout << dp[i][j];
        cout << endl;
    }
}

void xuli()
{
    for (int i =  1; i <= n; i++)
        for (int j = 1; j <= p; j++)
        {
            if (m[i] <= j) dp[i][j] = max(dp[i-1][j], dp[i][j - m[i]] + c[i]);
            else dp[i][j] = dp[i-1][j];
            if (i == n && j == p)   sleep(1);
        }
    f2 << "Gia tri toi da co trong tui la: " << dp[n][p] << endl;
}

void truyvet()
{
    nd = n;
    while (p > 0)
    {
        if (dp[n][p] == dp[n-1][p])
        n--;
        else
        {
            d[n]++;
            p = p - m[n];
        }
    }
    for (int i = 1; i <= nd; i++)
        f2 << "Tui " << i << " chua " << d[i] << endl;
}

int main()
{
    laydulieu();
    f2.open("dp_bag.out", ios::out);
    xuli();
    truyvet();
    f2.close();
    cout << "Chuong trinh da chay xong!";
    return 0;
}
