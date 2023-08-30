

// Copyright (c) 2023, Le Duc Phuc Long
 
/*If you don't think twice, you have to code twice.*/
 
// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>
 
// Namespace
using namespace std;  // NOLINT
 
// Define
#define nln '\n'
 
// Typedef and Struct
typedef int64_t lo;
 
// Constant
const long double eps = 1e-7;
 
// Declare global variables.
// End of global variable declaration.
 
void precompute() {
}

long long func(double x){
    long long y = x ;
    if(abs(y-x)<1e-6) return y ;
    if(abs(y+1-x)<1e-6) return y+1 ;
    return y ;
}

bool check(vector<long double> arr, lo q, long double m) {
    lo cnt = 0;
    for (auto v : arr) {
        cnt += func(v/m);
    }
    return cnt >= q;
}

void solve() {
    // Input
    lo n, q;
    cin >> n >> q;
    vector<long double> arr(n);
    for (auto &v : arr)
        cin >> v;
    // Binary Search
    long double l = eps, r = (lo)1e9, res = 0;
    // cout << "r: " << r << nln;
    while (r-l >= eps) {
        long double m = (l+r)/2;
        if (check(arr, q, m))
            l = m, res = m;
        else
            r = m-eps;
    }
    cout << setprecision(2) << fixed << res << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;

}

