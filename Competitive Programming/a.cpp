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
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo x, y, n;
    cin >> x >> y >> n;
    int add = 1;
    vector<lo> ans = {y};
    n -= 2;
    while (n > 0 && y > x+1) {
        y -= add;
        add++;
        n--;
        ans.push_back(y);
    }

    ans.push_back(x);

    reverse(ans.begin(), ans.end());
    if (ans[1]-ans[0] <= ans[2]-ans[1])
        n = 1;

    if (n == 0) {
        for (auto v : ans)
            cout << v << ' ';
        cout << nln;
    } else {
        cout << -1 << nln;
    }
}

int main(int argc, char* argv[]) {
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
