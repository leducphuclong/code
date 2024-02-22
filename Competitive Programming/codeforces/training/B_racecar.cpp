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

bool is_palin(string s) {
    for (lo i = 0; i < s.size()/2; ++i)
        if (s[i] != s[s.size()-1-i])
            return false;
    return true;
}

void solve() {
    // Input
    lo n;   cin >> n;
    vector<string> s(n);
    for (auto &v : s)
        cin >> v;
    // Output
    for (lo i = 0; i < n-1; ++i)
        for (lo j = i+1; j < n ; ++j) {
            string s1 = s[i]+s[j], s2 = s[j]+s[i];
            if (is_palin(s1) || is_palin(s2)) {
                cout << "Yes";
                return;
            }
        }
    cout << "No";
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