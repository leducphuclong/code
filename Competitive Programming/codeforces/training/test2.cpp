//#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <deque>
#include <iomanip>
#define ld long double
using namespace std;
const int N = 1e6 + 10;
int n , L , R;
int a[N];
long long f[N];
bool check(long double x){
    bool res = false;
    deque <int> dq;
    // dq.push_back(0);
    for (int i = 1; i <= n; i++){
        while (dq.size() > 1 && dq.front() < i - R)
            dq.pop_front();
        if (!dq.empty()){
            long double u = f[i] - x * i;
            long double v = f[dq.front()] - x * dq.front();
            if (u >= v)
                res = true;
        }
        while (!dq.empty() && (i - L + 1 > 0) && (f[i - L + 1] - x * (i - L + 1) < f[dq.back()] - x * dq.back()))
            dq.pop_back();
        if (i - L + 1 >= 0) dq.push_back(i - L + 1);
    }
    return res;
}
void BruteForce(){
    long double ans = -1e9 - 2004;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (L <= j - i + 1 && j - i + 1 <= R) ans = max(ans,(ld)(f[j] - f[i - 1]) / (j - i + 1));
    cout << setprecision(4) << fixed << ans << "\n";
}
int main()
{
    // freopen("RUMP.inp","r",stdin);
    // freopen("RUMP.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> L >> R;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i];
    // for (int i = 1; i <= n; i++) cout << f[i] << " "; cout << "\n";
    long double L = -1e9 - 2 , R = 1e9 + 10 , ans = -1e9;
    while (R - L >= 0.00000010022004){
        long double mid = (L + R) / 2;
        if (check(mid))
            L = mid , ans = mid;
        else
            R = mid;
    }
    cout << setprecision(4) << fixed << ans << "\n";
    // BruteForce();
    return 0;
}
