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
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    for (int i = 4; i <= 10; ++i)
        a[i] = a[i-1]+a[i-2]+a[i-3];
    cout << a[10] << nln;
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
    return 0;
}
