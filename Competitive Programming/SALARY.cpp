#include <iostream>
#include <fstream>
#include <array>

using namespace std;

fstream f1, f2; signed n;  array<signed, 10000> x, y;  array<array<signed, 10000>, 10000> dp;
void openf()
{
    f1.open("SALARY.INP", ios:: in);
    f2.open("SALARY.OUT", ios:: out);
}

void closef()
{
    f1.close(); f2.close();
}

void data()
{
    f1 >> n;
    for (int i = 1; i <= n; i++)
        f1 >> x[i] >> y[i];
}

signed min(signed a, signed b)
{
    if (a <= b) return a; return b;
}

void find()
{
    dp[0][0] = 0;
    for (int i = 0; i <= n/2; i++)
        for (int j = 0; j <= n/2; j++)
        {
            if (i > j)
                dp[i][j] = 999999;
            else
                dp[i][j] = min(dp[i-1][j] + x[i+j], dp[i][j-1] + y[i+j]);
        }
    f2 << dp[n/2][n/2] << endl;
}

void solve()
{
    openf();
    data();
    find();
    closef();
}

int main()
{
    solve();
    return 0;
}
