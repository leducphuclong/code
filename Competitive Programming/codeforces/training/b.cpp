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
    lo n, k;    cin >> n >> k;

    vector<lo> ans;
    lo f = 9;
    while (n > 1 && f > 1) {
        while (n % f == 0) {
            ans.push_back(f);
            n /= f;
        }
        f--;
    }

    while (ans.size() < k)
        ans.push_back(1);

    sort(ans.begin(), ans.end());
    
    if (ans.size() == k && n == 1) {
        for (auto v : ans)
            cout << v;
        cout << nln;
    } else {
        cout << -1 << nln;
    }
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