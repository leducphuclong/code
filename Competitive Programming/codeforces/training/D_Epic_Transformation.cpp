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
    lo n;   cin >>n;
    map<lo, lo> cnt;
    for (lo i = 0; i < n; ++i) {
        lo x; cin >> x;
        cnt[x]++;
    }

    priority_queue<lo> que;
    for (auto p : cnt) {
        // cout << p.second << ' ';
        que.push(p.second);
    }
    // cout << endl;

    while (que.size() > 1) {
        lo p1 = que.top();  que.pop();
        lo p2 = que.top();  que.pop();
        if (p1 > 1) que.push(p1-1);
        if (p2 > 1) que.push(p2-1);
    }

    cout << (que.empty() ? 0 : que.top()) << endl;
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
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