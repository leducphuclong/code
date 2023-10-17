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
typedef long double db;

// Constant

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void solve() {
    int n;  cin >> n;
    db d, h; cin >> d >> h;
    vector<db> arr(n);
    for (auto &v : arr)
        cin >> v;
    db ans = d*h/2*n;
    for (int i = 1; i < n; ++i) {
        db overlap = 0;
        if (arr[i] < arr[i-1]+h) {
            db new_h = arr[i-1]+h-arr[i];
            db new_d = new_h*d/2/h*2;
            overlap = new_d * new_h / 2;
        }
        ans -= overlap;
    }

    cout << setprecision(6) << fixed << ans << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}