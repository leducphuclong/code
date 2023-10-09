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
    lo n;   cin >> n;
    vector<lo> min, p_min;
    while (n--) {
        lo m; cin >> m;
        vector<lo> arr(m);
        for (auto &v : arr)
            cin >> v;
        sort(arr.begin(), arr.end());
        min.push_back(arr[0]), p_min.push_back(arr[1]);
    }
    cout << accumulate(p_min.begin(), p_min.end(), 0ll)
    -*min_element(p_min.begin(), p_min.end())
    +*min_element(min.begin(), min.end()) << endl;
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