// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define endl '\n'
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

    priority_queue<pair<lo, lo>> que;
    for (lo i = 0; i < n; ++i) {
        lo x;   cin >> x;
        if (x > 0)
            que.push({x, i+1});
    }

    vector<pair<lo, lo>> ans;
    while (que.size() > 1) {
        auto mx1 = que.top();
        que.pop();
        auto mx2 = que.top();
        que.pop();

        ans.push_back({mx1.second, mx2.second});

        if (mx1.first > 1)
            que.push({mx1.first-1, mx1.second});
        if (mx2.first > 1)
            que.push({mx2.first-1, mx2.second});
    }

    cout << ans.size() << nln; 
    for (auto p : ans)
        cout << p.first << " " << p.second << endl;
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
    cerr << "It's ok Long, Good for now !!" << endl;
    return 0;
}