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
    ll n;   cin >> n;
    string s;   cin >> s;
    map<char, bool> cnt;
    string r = "";
    for (auto c : s)
        if (cnt[c] == 0) {
            cnt[c] = 1;
            r += c;
        }

    sort(r.begin(), r.end());



    map<char, ll> loc;
    for (ll i = 0; i < r.size(); ++i) {
        loc[r[i]] = i;
    }


    string res = "";
    for (auto c : s)
        res += r[r.size() - 1 - loc[c]];
    
    cout << res << nln;
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