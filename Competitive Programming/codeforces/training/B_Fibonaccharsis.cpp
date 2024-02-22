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
vector<lo> fb = {0, 1};
// End of global variable declaration.

void precompute() {
    for (lo i = 0; i < 1e5; ++i)
        fb.push_back(fb.back() + fb[fb.size()-2]);
}

void solve() {
    lo n, k;    cin >> n >> k;
    if (k-1  > fb.size()-1) {
        cout << 0 << nln;
        return;
    }
    lo a = fb[k-2], b = fb[k-1];
    lo cnt = 0;
    for (lo i = 0; i <= n; ++i)
         if ((n-a*i) > 0 && b != 0 && (n-a*i) % b == 0 && i <= (n-a*i)/b)
            cnt++;
    cout << cnt << nln;
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