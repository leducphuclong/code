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
    lo n;   cin >> n;
    vector<lo> arr(n);
    deque<lo> deq;
    for (auto &v : arr) {
        cin >> v;
        deq.push_back(v);
    }
    
    lo ans[n+1] = {0};
    for (lo i = n ; i >= 1; --i) {
        while (deq.back() != i) {
            deq.push_back(deq.front());
            deq.pop_front();
            ans[i]++;
        }
        deq.pop_back();
    }

    for (lo i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
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