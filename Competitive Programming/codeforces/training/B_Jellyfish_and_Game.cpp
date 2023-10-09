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
    lo n, m, k, s1 = 0, s2 = 0;;
    cin >> n >> m >> k;
    vector<lo> a(n), b(m);
    for (auto &v : a) { cin >> v; s1 += v ;}
    for (auto &v : b) { cin >> v; s2 += v ;}


    lo m1 = *min_element(a.begin(), a.end());
    lo M1 = *max_element(a.begin(), a.end());

    lo m2 = *min_element(b.begin(), b.end());
    lo M2 = *max_element(b.begin(), b.end());

    if (k & 1)
            cout << s1 - m1 + max(m1, M2) << nln;
        else
            cout << s1 - m1 + max(m1, M2) - max(M1, M2) + min(m1, m2)<< nln;
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