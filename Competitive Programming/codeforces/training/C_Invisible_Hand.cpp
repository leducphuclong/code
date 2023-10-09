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
    lo n, m;    cin >> n >> m;
    vector<lo> a(n), b(m);

    vector<lo> psb;

    for (auto &v : a) { 
        cin >> v; 
        psb.push_back(v); 
    }
    for (auto &v : b) { 
        cin >> v; 
        psb.push_back(v+1); 
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    sort(psb.begin(), psb.end());

    lo ans;
    lo l = 0, r = 1e9+1;
    while (l <= r) {
        lo p = (l+r)/2;

        lo qtt_sell = 0;
        for (auto v : a)
            if (v <= p)
                qtt_sell++;

        lo qtt_buy = 0;
        for (auto v : b)
            if (v >= p)
                qtt_buy++;
        if (qtt_sell >= qtt_buy) {
            ans = p;
            r = p-1;
        } else {
            l = p+1;
        }
    }

    cout << ans << nln;

}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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