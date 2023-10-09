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

string shift(string s, lo t) {
    string res = "";
    lo n = s.size();
    for (lo i = 0; i < n; ++i)
        res += s[(i+t) % n];
    return res;
}

void solve() {
    // Test
    // string test = "0123456";
    // test = shift(test, 6); // 6012345
    // cout << test << nln;
    // return;
    lo n, a, b; cin >> n >> a >> b;
    string s;   cin >> s;

    lo ans = LLONG_MAX;

    for (lo t = 0; t <= n-1; ++t) {
        string tmp = shift(s, t);
        lo l = 0, r = n-1;
        lo cnt = 0;
        while (l < r)
            if (tmp[l++] != tmp[r--])
                cnt++;
    
        ans = min(ans, t*a + cnt*b);
    }
    cout << ans << nln;
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