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
typedef int lo;

// Constant

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
    // Eratosthenes sieve
}

void solve() {
    lo a, b, k;         cin >> a >> b >> k;

    if (k == 1) {
        if ((a != b) && (a % b == 0 || b % a == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }

    lo cnt_a = 0, cnt_b = 0;
    for (lo i = 2; i*i <= max(a, b); ++i) {
        while (a > 1 && a % i == 0)
            a /= i, cnt_a++;
        while (b > 1 && b % i == 0)
            b /= i, cnt_b++;
    }

    if (a > 1) cnt_a++;
    if (b > 1) cnt_b++;

    if (cnt_a + cnt_b >= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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