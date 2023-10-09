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
    string s;   cin >> s;

    string v = "";
    for (lo i = 0; i < n; i++)
        v += (9-(s[i]-'0'))+'0';
    
    if (v[0] == '0') {
        // cout << "v: " << v << nln;
        string u = "";
        for (lo i = 0; i < n-1; ++i)
            u += '1';
        u += '2';
        // cout << "u: " << u << nln;

        lo rem = 0;
        for (lo i = n-1; i >= 0; --i) {
            lo val = ((v[i]-'0') + (u[i]-'0') + rem);
            v[i] = val % 10 + '0';
            rem  = (val) / 10;
        }
    }
    cout << v << nln;
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