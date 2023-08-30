#include<iostream>

using namespace std;

int main()
{
    int m, n;
    scanf("%i%i", &m, &n);
    int a[m+1][n+1];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = 0;
    a[1][1] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j){
            if (i > 1)
                a[i][j] += a[i-1][j];
            if (j > 1)
                a[i][j] += a[i][j-1];
        }
    printf("%i", a[m][n]);
    return 0;
}