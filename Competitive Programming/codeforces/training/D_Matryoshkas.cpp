// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
#include <conio.h>

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
    lo n;   cin >> n;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;

    sort(arr.begin(), arr.end());
    
    map<lo, lo> exist;
    lo cnt = 0;
    for (auto v : arr) {
        // cout << "v:  " << v << nln;
        // cout << "exist[v-1]: " << exist[v-1] << nln;
        // cout << "exist[v]: " << exist[v] << nln;
        if (exist[v-1] > 0) {
            exist[v-1]--;
        } else {
            cnt++;
        }
        exist[v]++;
        // cout << "cnt: " << cnt << nln;
        // getch();
    }



    cout << cnt << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}