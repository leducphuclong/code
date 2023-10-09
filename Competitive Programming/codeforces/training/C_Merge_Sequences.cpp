// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Defime
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.


void solve() {
    // Input
    lo n, m;    cin >> n >> m;
    vector<pair<lo, lo>> a(n), b(m);
    for (lo i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (lo i = 0; i < m; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }

    // for (auto v : a)
    //     cout << v.first << ' ' << v.second << nln;;
    // for (auto v : b)
    //     cout << v.first << ' ' << v.second << nln;;
    // return;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    lo i = 0, j = 0, k = 1;
    vector<lo> pa(n, 0), pb(m, 0);
    while (i < n && j < m)
        if (b[j].first < a[i].first)
            pb[b[j++].second] = k++;
        else
            pa[a[i++].second] = k++;


    while (i < n)
        pa[a[i++].second] = k++;

    while (j < m)    
        pb[b[j++].second] = k++;
    
    for (lo i = 0; i < n; ++i)
        cout << pa[i] << ' ';
    cout << nln;

    for (lo j = 0; j < m; ++j)
        cout << pb[j] << ' ';
    cout << nln;

}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}