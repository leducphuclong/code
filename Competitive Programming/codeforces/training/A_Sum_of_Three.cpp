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
    int n;  cin >> n;
    if (n < 7) {
        cout << "NO" << endl;
    } else { // n now >= 7
        int x, y, z;
        x = 1, y = 2, z = n-x-y;
        if (x != z && y != z && z % 3) {
            cout << "YES" << nln;
            cout << x << ' ' << y << ' ' << z << nln;
            return;
        }
        x = 1, y = 4, z = n-x-y;
        if (x != z && y != z && z % 3) {
            cout << "YES" << nln;
            cout << x << ' ' << y << ' ' << z << nln;
            return;
        }
        x = 2, y = 4, z = n-x-y;
        if (x != z && y != z && z % 3) {
            cout << "YES" << nln;
            cout << x << ' ' << y << ' ' << z << nln;
            return;
        }
        cout << "NO" << nln;
    }
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