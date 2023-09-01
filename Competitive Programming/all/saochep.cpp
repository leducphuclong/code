// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

void precompute() {
}

void solve() {
    // Input
    lo n, m, a, b;
    cin >> n >> m >> a >> b;
    // Solve
    if (a % m == 1 && (b % m == 0 || b == n)) {
        cout << 1 << nln;
        return;
    }
    if ((a-1)/m == (b-1)/m) {
        cout << 1 << nln;
        return;
    }
    if (a % m == 1 || b % m == 0 || b == n) {
        cout << 2 << nln;
        return;
    }
    if ((a-1)/m+1 == (b-1)/m) {
        cout << 2 << nln;
        return;
    }
    if ((b-a+1) % m == 0) {
        cout << 2 << nln;
        return;
    }
    cout << 3 << nln;
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
  return 0;
}
