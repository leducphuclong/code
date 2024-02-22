#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("summax.inp" , "r" , stdin);
    freopen("summax.out" , "w" , stdout);
    int n; cin >> n;
    int a[n][n];
    int sum(0) , cnt(0);
    set<int>c;
    for(int i = 1 ; i <= n ; i++){
       for(int j = 1; j <= n ; j++)
       {
           cin >> a[i][j];
       }
    }
    for(int i = 1 ; i<= n ; i++)
    {
        sum += a[i][i];
    }
    c.insert(sum);

    for(int i = 2 ; i <= n ; i++)
    {
        int bd(1);
        for(int j = i ; j <= n ; j++){
        cnt+= a[j][bd];
        bd++;
        if(j == n)
            {
                c.insert(cnt);
                cnt = 0;
            }
        }
    }
    int tong(0);
    for(int i = n ; i>= 2 ; i--)
    {
        int q = 1;
        for(int j = i ; j<=n ; j++){
            tong += a[q][j];
            q++;
            if(j== n)
            {
                c.insert(tong);
                tong = 0;
            }
        }
    }
    cout << *prev(c.end()) << endl;
}
