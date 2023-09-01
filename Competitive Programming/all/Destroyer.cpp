// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Namespace
using namespace std;  // NOLINT

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

bool check(vector<lo> arr) {
    map<lo, lo> cnt;
    for (auto v : arr) {
        cnt[v]++;
        if (v == 0)
            continue;
        if (!cnt[v-1])
            return false;
        cnt[v-1]--;
    }
    return true;
}

void solve() {
    lo n;
    cin >> n;
    vector<lo> arr;
    while (n--) {
        lo x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    
    if (check(arr))
        cout << "YES" << nln;
    else
        cout << "NO" << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
