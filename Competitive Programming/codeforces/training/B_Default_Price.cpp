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
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    lo n, m;
    cin >>n >> m;
    vector<string> dis(n);
    for (auto &s : dis)
        cin >> s;
    vector<string> col(m);
    for (auto &s : col)
        cin >> s;
    vector<lo> pri(m);
    lo dfa;     cin >> dfa;
    for (auto &s : pri)
        cin >> s;
    // Build map
    map<string, lo> cal;
    for (lo i = 0; i < m; i++)
        cal[col[i]] = pri[i];
    // Output
    lo bil = 0;
    for (auto d : dis)
        if (cal[d] != 0)
            bil += cal[d];
        else
            bil += dfa;
    cout << bil;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}