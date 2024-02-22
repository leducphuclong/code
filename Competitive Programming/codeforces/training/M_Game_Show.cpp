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
    lo n, q;    cin >> n >> q;
    vector<lo> a(n), b(n);
    for (auto &v : a)
        cin >> v;
    for (auto &v : b)
        cin >> v;

    vector<lo> clw(1, 0);
    for (auto v : a)
        clw.push_back(clw.back()+v);
    for (auto v : a)
        clw.push_back(clw.back()+v);
    
    vector<lo> uclw(1, 0);
    for (auto v : b)
        uclw.push_back(uclw.back()+v);
    for (auto v : b)
        uclw.push_back(uclw.back()+v);
    
    // Check if flawed
    bool fld = false;
    if (accumulate(a.begin(), a.end(), 0ll) < 0 || accumulate(b.begin(), b.end(), 0ll) < 0)
        fld = true;
    for (lo i = 0; i < n; ++i)
        if (a[i] + b[i] < 0)
            fld = true;
    // Process queries
    /*
    clw[i] is the cost from 1 to i+1 according to clockwise way  
    so cost from 1 to i is clw[i-1]
    */
   while (q--) {
        if (fld) {
            cout << "flawed" << nln;
            continue;
        }
        lo s, t;    cin >> s >> t;
        // cout << s << " ~ " << t << nln;
        lo cost = LLONG_MAX;
        if (s == t) {
            cost = 0;
        } else if (s < t){
            cost = min(clw[t-1]-clw[s-1], uclw[n+s-1]-uclw[t-1]);
            // cout << clw[2] << " " << clw[0] << nln;
            // cout << n+s-1 << " " << t-1 << nln;
            // cout << uclw[n+s-1] << nln;
            // cout << uclw[t-1] << nln;
            // cout << "cost: " <<  clw[t-1]-clw[s-1] << " ~ " << uclw[n+s-1]-uclw[t-1] << nln;
        } else {
            swap(s, t);
            cost = min(uclw[t-1]-uclw[s-1], clw[n+s-1]-clw[t-1]);
        }
        cout << cost << nln;
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