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
    string s1, s2;  cin >> s1 >> s2;
    map<char, lo> cnt1, cnt2;

    for (auto c : s1)
        cnt1[c]++;
    for (auto c : s2)
        cnt2[c]++;

    string mod = "atcoder";

    for (auto c : mod) {
        lo m = max(cnt1[c], cnt2[c]);
        if (m-cnt1[c] > cnt1['@'] || m-cnt2[c] > cnt2['@']) {
            cout << "No" << nln;
            return;
        }
        cnt1['@'] -= m-cnt1[c], cnt2['@'] -= m-cnt2[c];
        cnt1[c] = cnt2[c] = m;
    }

    if (cnt1 == cnt2)
        cout << "Yes" << nln;
    else
        cout << "No" << nln;
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