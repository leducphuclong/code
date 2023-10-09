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
    lo n;   cin >> n;
    lo z = 0;
    set<lo> clt;
    for (lo i = 0; i < n; ++i) {
        lo x;   cin >> x;
        if (!x) z++;
        clt.insert(x);
    }
    
    if (z == n) {
        cout << 1 << nln;
        return;
    }
    
    if (z <= (n-z)+1) {
        cout << 0 << nln;
        return;
    }

    clt.erase(0);
    
    if (clt.size() > 1) {
        cout << 1 << nln;
    } else {
        if (*clt.begin() == 1)
            cout << 2 << nln;
        else
            cout << 1 << nln;
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