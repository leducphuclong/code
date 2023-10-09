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

lo cnt_d2s(lo x) {
    lo cnt = 0;
    while (x % 2 == 0) {
        cnt++;;
        x /= 2;
    }
    return cnt;
}

void solve() {
    lo n;   cin >> n;
    priority_queue<lo, vector<lo>, greater<lo>> d2s;
    lo ans = 0;
    while (n--) {
        lo x; cin >> x;
        ans = __gcd(ans, x);
        d2s.push(cnt_d2s(x));
    }
    while (d2s.size() > 1) {
        lo f = d2s.top();
        d2s.pop();
        lo s = d2s.top();
        d2s.pop();
        // cout << s << " ~ " << f << nln;
        d2s.push(min(s, f)+1);
    }
    while (ans % 2 == 0)
        ans /= 2;
    cout << (lo)(ans*pow(2, d2s.top())) << nln;
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