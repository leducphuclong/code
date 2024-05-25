// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>
// #include <conio.h>

// Namespace
using namespace std;

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t ll;

// Constant

// Declare global variables.
vector<pair<ll, ll>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
    
}

void solve() {
    string s;   cin >> s;
    char maxm = s[0], minm = s[0];
    ll idx1 = 0, idx2 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] > maxm) {
            maxm = s[i];
            idx1 = i;
        }
        if (s[i] < minm) {
            minm = s[i];
            idx2 = i;
        }
    }
    if (maxm == minm) {
        cout << "NO" << nln;
    } else {
        cout << "YES" << nln;
        swap(s[idx1], s[idx2]);
        cout << s << nln;
    }
}

int main(int argc, char* argv[]) {
    #ifndef ONLINE_JUDGE
    //freopen("in", "r", stdin);
    #endif // ONLINE_JUDGE
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