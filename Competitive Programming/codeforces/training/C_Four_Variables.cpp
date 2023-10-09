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

bool is_square_number(lo x) {
    return round(sqrt(x)) == sqrt(x);
}

void solve() {
    lo n;   cin >> n;

    map<lo, lo> cnt;
    for (lo x = 1; x <= n; ++x) {
        for (lo i = 1; i <= round(sqrt(x)); ++i)
            if (x % i == 0)
                cnt[x] += 2;
        if (is_square_number(x))
            cnt[x] -= 1;
    }
    
    lo ans = 0;
    for (lo x = 1; x <= n; ++x) {
        lo y = n-x;
        // cout << x << ": " << cnt[x] << nln;
        // cout << y << ": " << cnt[y] << nln;
        ans += cnt[x]*cnt[y];
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