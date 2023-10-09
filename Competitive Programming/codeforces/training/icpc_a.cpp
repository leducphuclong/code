#include <bits/stdc++.h>
// #include <conio.h>

using namespace std;

#define nln '\n'
#define int long long

const int LIM = 1e18;

// Global Variables
vector<int> fb;
// End Declaration

void precompute() {
    fb.push_back(2);
    fb.push_back(3); 
    while (fb.back() <= LIM)
        fb.push_back(fb[fb.size()-1]+fb[fb.size()-2]);
}

int recurse(int n, int prev) {
    if (n == 1)
        return 1;

    int res = 0;
    for (auto v : fb)
        if (v >= prev && n % v == 0)
            res += recurse(n/v, v);

    return res;
}

void solve() {
    int n;  cin >> n;
    cout << recurse(n, 2) << nln;
}

signed main() {
    // freopen("in", "r", stdin);
    precompute();
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}