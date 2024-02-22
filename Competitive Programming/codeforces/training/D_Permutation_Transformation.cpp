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
lo n;
vector<lo> p, d;
// End of global variable declaration.

void precompute() {
}

void construct(lo l, lo r, lo dth) {
    if (l > r)
        return;

    lo pos = -1, mx = 0;
    for (lo i = l; i <= r; ++i)
        if (p[i] > mx)
            mx = p[i],
            pos = i;

    d[pos] = dth++;

    construct(l, pos-1, dth);
    construct(pos+1, r, dth);
}

void solve() {
    lo n;   cin >> n;
    p.resize(n+1);
    for (lo i = 1; i <= n; ++i)
        cin >> p[i];
    
    d.resize(n+1);
    d.assign(n+1, 0);

    construct(1, n, 0);

    for (lo i = 1; i <= n; ++i)
        cout << d[i] << ' ';
    cout << endl;
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