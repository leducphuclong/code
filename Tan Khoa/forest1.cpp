#include <iostream>
#include<cstring>
#include <cstdint>

using namespace std;
#define nln '/n'

typedef int64_t lo;


int main() 
{
    int n,m,k;
    cin >> n >> m >> k;
    int a[n+1][m+1];
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= m; ++j)
        cin >> a[i][j];
      
    lo psa[n-1][m-1];
    memset(psa,0,sizeof(psa));
    for(int i= 1; i <= n; ++i){
      for(int j = 1; j <= m; ++j){
        psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1]+a[i-1][j-1];
      }
    }
    lo mav = -999999999;
    for(int i =1; i <= n-k+1; ++i){
      for(int j = 1; j <= m-k+1; ++j){
        lo tong = psa[i+k-1][j+k-1] - psa[i+k-1][j-1] + psa[i-1][j-1] - psa[i-1][j+k-1];
        if(tong > mav){
          mav = tong;
        }
      }
    }
    cout << mav;
    return 0;
}