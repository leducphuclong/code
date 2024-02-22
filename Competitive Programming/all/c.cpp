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

// Declare global variables.
map<lo, lo> cnt;
vector<lo> path;
bool ok = 0;
// End of global variable declaration.

void precompute() {
}

void go(lo n) {
    if (ok || n < 1)
        return;
    if (n == 1) {
        // reverse(path.begin(), path.end());
        for (auto v : path)
            cout << v << ' ';
        cout << nln;
        ok = 1;
        return;
    }
    for (lo i = 1; i <= round(sqrt(n)); ++i)
        if (n % i == 0) {
            lo d1 = i, d2 = n / i;

            if (cnt[d1] <= 1) {
                cnt[d1]++;
                path.push_back(n-d1);
                go(n-d1);
                path.pop_back();
                cnt[d1]--;
            }

            if (cnt[d2] <= 1) {
                cnt[d2]++;
                path.push_back(n-d2);
                go(n-d2);
                path.pop_back();
                cnt[d2]--;
            }
        }
}

void solve() {
    path.clear();
    lo n;
    cin >> n;
    ok = 0;
    cout << n << ' ';
    go(n);
}

int main(int argc, char* argv[]) {
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
