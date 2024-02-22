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
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

bool check(lo n, lo m) {
    if (n % m == 0) return true;
    m /= __gcd(n, m);
    return log2(m) == round(log2(m));
}

void solve() {
    lo n, m;    cin >> n >> m;

    if (check(n, m) == false) {
        cout << -1 << nln;
    } else {
        lo ans = 0;
        while (n % m != 0) {
            n %= m;
            ans += n;
            n *= 2;
        }
        cout << ans << nln;
    }
    
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
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