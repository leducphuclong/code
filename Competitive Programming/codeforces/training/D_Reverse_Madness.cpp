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
    string s;   cin >> s;
    vector<lo> l(k), r(k);
    for (auto &v : l) { cin >> v; v--; }
    for (auto &v : r) { cin >> v; v--; }

    map<lo, lo> cnt;
    lo q;   cin >> q;
    while (q--) {
        lo x;   cin >> x;
        cnt[x-1]++;  // count
    }

    for (lo i = 0; i < k; ++i) {
        lo ops = 0;
        lo left = l[i], right = r[i];
        // cout << left << " " << right << nln;
        for (lo j = left; j <= (left+right)/2; ++j) {
            // cout << j << " : " << cnt[j] << ' ' << cnt[right+left-j] << nln;
            ops += cnt[j] + cnt[right+left-j];
            if (ops & 1)
                swap(s[j], s[right+left-j]);
        }
    }
    cout << s << nln;
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