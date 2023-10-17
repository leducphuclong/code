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

void solve() {
    lo n, m;        cin >> n >> m;

    lo cnt2 = 0;
    lo tmp = n;
    while (tmp % 2 == 0) {
        cnt2++;
        tmp /= 2;
    }

    lo cnt5 = 0;
    tmp = n;
    while (tmp % 5 == 0) {
        cnt5++;
        tmp /= 5;
    }

    lo k = 1;
    while (cnt2 < cnt5 && k*2 <= m) {
        cnt2++;
        k *= 2;
    }

    while (cnt5 < cnt2 && k*5 <= m) {
        cnt5++;
        k *= 5;
    }

    while (k*10 <= m)
        k *= 10;
    
    if (k == 1) {
        cout << n*m << nln;
        return;
    }
    k *= (m/k);
    cout << n*k << nln;
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