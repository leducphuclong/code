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
    // Input
    lo m, n;        cin >> m >> n;
    /* Idea
    - We see, if we can archive the x joy, then we can archive x-1 joy,
    and also if we can't archive x joy, then we cann't archive x+1 joy.

    - Binary search from min joy to max joy

    - The check function is that everyone is bought at least one gift.
    */

    lo mn = LLONG_MAX, mx = LLONG_MIN; // this for BS
    vector<vector<lo>> joy(m, vector<lo> (n, 0)); // Remember we have 'm' shops and 'n' friends
    for (lo i = 0; i < m; ++i)
        for (lo j = 0; j < n; ++j) {
            cin >> joy[i][j];
            mn = min(mn, joy[i][j]);
            mx = max(mx, joy[i][j]);
        }   

    auto check = [&] (lo x) {
        // visit all shops and buy everything we can for some friends
        vector<bool> bought(n, false);
        bool same_shop = false;
        for (lo i = 0; i < m; ++i) {
            lo cnt = 0;     // this is a number of friends
            // bought gift in this shop
            for (lo j = 0; j < n; ++j)
                if (joy[i][j] >=  x)  // buy it 
                    bought[j] = true, cnt++;
            if (cnt > 1)
                same_shop = true;
        }

        if (!same_shop && n > 1)
            return false;
        
        bool res = true;
        for (auto v : bought)
            res = res && v;
        return res;
    };
    
    while (mn <= mx) {
        lo gss = (mn+mx) >> 1;
        if (check(gss)) {
            mn = gss+1;
        } else {
            mx = gss-1;
        }
    }
    cout << mn-1 << endl;
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